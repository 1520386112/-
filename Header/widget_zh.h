#ifndef WIDGET_ZH_H
#define WIDGET_ZH_H

#include <QWidget>
#include "dialog_bj.h"
#include "dialog_bx.h"

namespace Ui {
class Widget_zh;
}

/**
 * @brief The Widget_zh class
 * 组合贷款
 */
class Widget_zh : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_zh(QWidget *parent = nullptr);
    ~Widget_zh();

private slots:
    void on_lineEdit_changed();

    void on_comboBox_hkfs_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::Widget_zh *ui;

    Dialog_bj * dialog_bj;
    Dialog_bx * dialog_bx;

    bool bedx =  true;

    double sydke;
    long double sydkll;

    double gjjdke;
    long double gjjdkll;

    int ajns;
};

#endif // WIDGET_ZH_H
