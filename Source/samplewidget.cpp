#include "samplewidget.h"
#include "ui_samplewidget.h"


SampleWidget::SampleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SampleWidget)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
}

SampleWidget::~SampleWidget()
{
    delete ui;
}

void SampleWidget::on_pushButton_start_clicked()
{
    if(dk_type == sy){
        if(cal_type == single){
            w_sy_single.show();
        }
        else if(cal_type == totle){
            w_sy_totle.show();
        }
    }
    else if(dk_type == zh){
        w_zh.show();
    }
}

void SampleWidget::on_comboBox_dkfs_currentIndexChanged(int index)
{
    if(index == 0 || index == 1){
        dk_type = sy;
        ui->comboBox_dklx->setEnabled(true);
        ui->comboBox_dklx->setCurrentIndex(0);
    }
    else if(index == 2){//如果为组合贷款  锁定计算方式combox
        dk_type = zh;
        ui->comboBox_dklx->setCurrentIndex(1);
        ui->comboBox_dklx->setEnabled(false);
    }
}

void SampleWidget::on_comboBox_dklx_currentIndexChanged(int index)
{
    if(index == 0){
        cal_type = single;
    }
    else if(index == 1){
        cal_type = totle;
    }
}
