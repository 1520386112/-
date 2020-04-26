#ifndef WIDGET_SY_SINGLE_H
#define WIDGET_SY_SINGLE_H

#include <QWidget>

#include "dialog_bx.h"
#include "dialog_bj.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget_sy_single; }
QT_END_NAMESPACE

/**
 * @brief The Widget class
 * 商业或公积金贷款  按房屋单价和面积计算
 */
class Widget_sy_single : public QWidget
{
    Q_OBJECT

public:
    Widget_sy_single(QWidget *parent = nullptr);
    ~Widget_sy_single();

private slots:
    void on_comboBox_hkfs_currentIndexChanged(int index);

    void on_pushButton_ksjs_clicked();

    void on_lineEdit_changed();

private:
    Ui::Widget_sy_single *ui;

    Dialog_bx *dialog_bx;
    Dialog_bj *dialog_bj;

    bool bedx = true;

    int fwdj;
    int fwmj;
    double ajcs;
    int ajns;
    long double dkll;
};
#endif // WIDGET_H
