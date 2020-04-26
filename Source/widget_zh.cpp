#include "widget_zh.h"
#include "ui_widget_zh.h"
#include "calcu.h"

Widget_zh::Widget_zh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_zh)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    ui->lineEdit_sydke->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{0,3}\\.[0-9]{0,2}")));
    ui->lineEdit_sdll->setValidator(new QRegExpValidator(QRegExp("([1-9][0-9]\\.[0-9]{0,2})|([0-9]\\.[0-9]{0,2})")));

    ui->lineEdit_gjjdke->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]{0,3}\\.[0-9]{0,2}")));
    ui->lineEdit_gjjll->setValidator(new QRegExpValidator(QRegExp("([1-9][0-9]\\.[0-9]{0,2})|([0-9]\\.[0-9]{0,2})")));

    connect(ui->lineEdit_sydke,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
    connect(ui->lineEdit_sdll,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
    connect(ui->lineEdit_gjjdke,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
    connect(ui->lineEdit_gjjll,SIGNAL(textChanged(const QString&)),this,SLOT(on_lineEdit_changed()));
}

Widget_zh::~Widget_zh()
{
    delete ui;
}

void Widget_zh::on_lineEdit_changed(){
    //所有文本框均有输入则启用按钮
    if(ui->lineEdit_sydke->text()!="" && ui->lineEdit_sdll->text()!=""
            && ui->lineEdit_gjjdke->text()!="" && ui->lineEdit_gjjll->text()!="")
    {
        ui->pushButton->setEnabled(true);
    }
    else{
        ui->pushButton->setEnabled(false);
    }
}

void Widget_zh::on_comboBox_hkfs_currentIndexChanged(int index)
{
    bedx = (index == 0);
}

void Widget_zh::on_pushButton_clicked()
{
    //获取当前输入
    ajns = ui->comboBox_ajns->currentText().toInt();
    sydke = ui->lineEdit_sydke->text().toInt() * 10000;
    sydkll = ui->lineEdit_sdll->text().toDouble() / 100 / 12;

    gjjdke = ui->lineEdit_gjjdke->text().toInt() * 10000;
    gjjdkll = ui->lineEdit_gjjll->text().toDouble() / 100 / 12;

    if(bedx){
        int hkys = ajns * 12;
        int yg;
        int lx;
        int hkze;

        //商贷部分
        int yg1, lx1, hkze1;

        Calcu::Get_Instance()->cal_totle_bedx(sydke, ajns, sydkll, yg1, lx1, hkze1, hkys);

        //公积金部分
        int yg2, lx2, hkze2;

        Calcu::Get_Instance()->cal_totle_bedx(gjjdke, ajns, gjjdkll, yg2, lx2, hkze2, hkys);

        yg = yg1 + yg2;
        lx = lx1+ lx2;
        hkze = hkze1 + hkze2;

        dialog_bx = new Dialog_bx(false, QString::number(0), QString::number(yg), QString::number((int)(sydke+gjjdke)),
                                        QString::number(lx), QString::number(hkze), QString::number(hkys));
        dialog_bx->show();
    }
    else{
        int hkys = ajns * 12;

        int syyg;
        int mydj;
        int hkze;
        int lx;

        //商贷部分
        int syyg1, mydj1, lx1, hkze1;

        Calcu::Get_Instance()->cal_totle_bedj(sydke, ajns, sydkll, syyg1, mydj1, lx1, hkze1, hkys);

        //公积金部分
        int syyg2, mydj2, lx2, hkze2;

        Calcu::Get_Instance()->cal_totle_bedj(gjjdke, ajns, gjjdkll, syyg2, mydj2, lx2, hkze2, hkys);

        syyg = syyg1 + syyg2;
        mydj = mydj1 + mydj2;
        hkze = hkze1 + hkze2;
        lx = lx1 + lx2;

        dialog_bj = new Dialog_bj(false, QString::number(0), QString::number(syyg), QString::number(mydj),
                                        QString::number((int)(sydke+gjjdke)), QString::number(lx), QString::number(hkze),QString::number(hkys));
        dialog_bj->show();
    }
}
