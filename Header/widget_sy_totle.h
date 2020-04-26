#ifndef WIDGET_SY_TOTLE_H
#define WIDGET_SY_TOTLE_H

#include <QWidget>
#include "dialog_bx.h"
#include "dialog_bj.h"

namespace Ui {
class Widget_sy_totle;
}

/**
 * @brief The Widget_sy_totle class
 * 商业或公积金贷款  按房屋单价和房屋面积计算
 */
class Widget_sy_totle : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_sy_totle(QWidget *parent = nullptr);
    ~Widget_sy_totle();

private slots:
    void on_lineEdit_changed();

    void on_pushButton_clicked();

    void on_comboBox_hkfs_currentIndexChanged(int index);

private:
    Ui::Widget_sy_totle *ui;

    Dialog_bj * dialog_bj;
    Dialog_bx * dialog_bx;

    bool bedx = true;

    double dkze;
    int ajns;
    long double dkll;
};

#endif // WIDGET_SY_TOTLE_H
