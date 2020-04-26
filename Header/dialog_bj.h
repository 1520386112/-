#ifndef DIALOG_BJ_H
#define DIALOG_BJ_H

#include <QDialog>

namespace Ui {
class Dialog_bj;
}

/**
 * @brief The Dialog_bj class
 * 等额本金结果窗口
 */
class Dialog_bj : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_bj(bool sf_enabled, QString sf, QString syyg, QString mydj, QString dkze, QString lx,
                             QString hkze, QString hkys, QWidget *parent = nullptr);
    ~Dialog_bj();

private:
    Ui::Dialog_bj *ui;
};

#endif // DIALOG_SY_DJ_BJ_H
