#ifndef SAMPLEWIDGET_H
#define SAMPLEWIDGET_H

#include <QWidget>
#include "widget_sy_single.h"
#include "widget_sy_totle.h"
#include "widget_zh.h"

enum DK_TPYE{
    sy = 1, zh = 2
};
enum CAL_TYPE{
    single = 1, totle = 2
};

namespace Ui {
class SampleWidget;
}

/**
 * @brief The SampleWidget class
 * 初始界面
 */
class SampleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SampleWidget(QWidget *parent = nullptr);
    ~SampleWidget();

private slots:
    void on_pushButton_start_clicked();

    void on_comboBox_dkfs_currentIndexChanged(int index);

    void on_comboBox_dklx_currentIndexChanged(int index);

private:
    Ui::SampleWidget *ui;

    Widget_sy_single w_sy_single;
    Widget_sy_totle w_sy_totle;
    Widget_zh w_zh;

    int dk_type = sy;
    int cal_type = single;

};

#endif // SAMPLEWIDGET_H
