#include "dialog_bx.h"
#include "ui_dialog_bx.h"

Dialog_bx::Dialog_bx(bool sf_enable, QString sf, QString yg, QString dkze, QString lx, QString hkze, QString hkys, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_bx)
{
    ui->setupUi(this);
    setFixedSize(width(), height());

    setWindowModality(Qt::ApplicationModal);//阻塞除此所有窗口

    if(!sf_enable){
        ui->lineEdit_sf->setEnabled(false);
        ui->label->setEnabled(false);
        ui->label_3->setEnabled(false);
    }
    ui->lineEdit_sf->setText(sf);
    ui->lineEdit_yg->setText(yg);
    ui->lineEdit_dkze->setText(dkze);
    ui->lineEdit_lx->setText(lx);
    ui->lineEdit_hkze->setText(hkze);
    ui->lineEdit_hkys->setText(hkys);
}

Dialog_bx::~Dialog_bx()
{
    delete ui;
}
