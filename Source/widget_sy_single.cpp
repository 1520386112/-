#include "widget_sy_single.h"
#include "ui_widget_sy_single.h"
#include "calcu.h"

Widget_sy_single::Widget_sy_single(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_sy_single)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    ui->lineEdit_fwdj->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{5}")));
    ui->lineEdit_fwmj->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{3}")));

    ui->lineEdit_dkll->setValidator(new QRegExpValidator(QRegExp("([1-9][0-9]\\.[0-9]{0,2})|([0-9]\\.[0-9]{0,2})")));

    connect(ui->lineEdit_fwdj,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
    connect(ui->lineEdit_fwmj,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
    connect(ui->lineEdit_dkll,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
}

Widget_sy_single::~Widget_sy_single()
{
    delete ui;
}


void Widget_sy_single::on_comboBox_hkfs_currentIndexChanged(int index)
{
    bedx = (index==0);
}

/**
 * @brief Widget::on_pushButton_ksjs_clicked
 * 开始计算
 */
void Widget_sy_single::on_pushButton_ksjs_clicked()
{
    //获取当前输入
    fwdj = ui->lineEdit_fwdj->text().toInt();
    fwmj = ui->lineEdit_fwmj->text().toInt();
    ajcs = ui->comboBox_ajcs->currentText().toDouble();
    ajns = ui->comboBox_ajns->currentText().toInt();
    dkll = ui->lineEdit_dkll->text().toDouble() / 100 / 12;//转为月利率

    if(bedx){
        int sf, dkze, hkys, yg, lx, hkze;

        Calcu::Get_Instance()->cal_single_bedx(fwdj, fwmj, ajcs, ajns, dkll, sf, dkze, hkys, yg, lx, hkze);

        dialog_bx = new Dialog_bx(true, QString::number(sf), QString::number(yg), QString::number(dkze),
                                        QString::number(lx), QString::number(hkze), QString::number(hkys));
        dialog_bx->show();
    }
    else{
        int sf, dkze, hkys, syyg, mydj, hkze, lx;

        Calcu::Get_Instance()->cal_single_bedj(fwdj, fwmj, ajcs, ajns, dkll, sf, dkze, hkys, syyg, mydj, hkze, lx);

        dialog_bj = new Dialog_bj(true, QString::number(sf), QString::number(syyg), QString::number(mydj),
                                        QString::number(dkze), QString::number(lx), QString::number(hkze),QString::number(hkys));
        dialog_bj->show();
    }
}

void Widget_sy_single::on_lineEdit_changed(){
    //所有文本框均有输入则启用按钮
    if(ui->lineEdit_fwdj->text()!="" && ui->lineEdit_fwmj->text()!="" && ui->lineEdit_dkll->text()!=""){
        ui->pushButton_ksjs->setEnabled(true);
    }
    else{
        ui->pushButton_ksjs->setEnabled(false);
    }
}
