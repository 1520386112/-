#include "widget_sy_totle.h"
#include "ui_widget_sy_totle.h"
#include "calcu.h"

Widget_sy_totle::Widget_sy_totle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_sy_totle)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    ui->lineEdit_dkze->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{0,3}\\.[0-9]{0,2}")));
    ui->lineEdit_dkll->setValidator(new QRegExpValidator(QRegExp("([1-9][0-9]\\.[0-9]{0,2})|([0-9]\\.[0-9]{0,2})")));

    connect(ui->lineEdit_dkze,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
    connect(ui->lineEdit_dkll,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
}

Widget_sy_totle::~Widget_sy_totle()
{
    delete ui;
}

void Widget_sy_totle::on_pushButton_clicked()
{
    //获取当前输入
    dkze = ui->lineEdit_dkze->text().toInt() * 10000;
    ajns = ui->comboBox_ajns->currentText().toInt();
    dkll = ui->lineEdit_dkll->text().toDouble() / 100 / 12;//转为月利率

    if(bedx){
        int yg, lx, hkze, hkys;

        Calcu::Get_Instance()->cal_totle_bedx(dkze, ajns, dkll, yg, lx, hkze, hkys);

        dialog_bx = new Dialog_bx(false, QString::number(0), QString::number(yg), QString::number((int)dkze),
                                        QString::number(lx), QString::number(hkze), QString::number(hkys));
        dialog_bx->show();
    }
    else{
        int hkys, syyg, mydj, hkze, lx;

        Calcu::Get_Instance()->cal_totle_bedj(dkze, ajns, dkll, syyg, mydj, lx, hkze, hkys);

        dialog_bj = new Dialog_bj(false, QString::number(0), QString::number(syyg), QString::number(mydj),
                                        QString::number((int)dkze), QString::number(lx), QString::number(hkze),QString::number(hkys));
        dialog_bj->show();
    }
}


void Widget_sy_totle::on_lineEdit_changed(){
    //所有文本框均有输入则启用按钮
    if(ui->lineEdit_dkze->text()!="" && ui->lineEdit_dkll->text()!=""){
        ui->pushButton->setEnabled(true);
    }
    else{
        ui->pushButton->setEnabled(false);
    }
}

void Widget_sy_totle::on_comboBox_hkfs_currentIndexChanged(int index)
{
    bedx = (index==0);
}
