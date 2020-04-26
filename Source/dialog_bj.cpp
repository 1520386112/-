#include "dialog_bj.h"
#include "ui_dialog_bj.h"

Dialog_bj::Dialog_bj(bool sf_enabled, QString sf, QString syyg, QString mydj, QString dkze, QString lx,
                                 QString hkze, QString hkys,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_bj)
{
    ui->setupUi(this);
    setFixedSize(width(), height());

    setWindowModality(Qt::ApplicationModal);//阻塞除此所有窗口

    if(!sf_enabled){
        ui->lineEdit_sf->setEnabled(false);
        ui->label->setEnabled(false);
        ui->label_2->setEnabled(false);
    }
    ui->lineEdit_sf->setText(sf);
    ui->lineEdit_syyg->setText(syyg);
    ui->lineEdit_mydj->setText(mydj);
    ui->lineEdit_dkze->setText(dkze);
    ui->lineEdit_lx->setText(lx);
    ui->lineEdit_hkze->setText(hkze);
    ui->lineEdit_hkys->setText(hkys);
}

Dialog_bj::~Dialog_bj()
{
    delete ui;
}
