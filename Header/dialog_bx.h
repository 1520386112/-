#ifndef DIALOG_BX_H
#define DIALOG_BX_H

#include <QDialog>

namespace Ui {
class Dialog_bx;
}

/**
 * @brief The Dialog_bx class
 * 等额本息结果窗口
 */
class Dialog_bx : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog_bx(bool sf_enable, QString sf, QString yg, QString dkze, QString lx, QString hkze, QString hkys, QWidget *parent = nullptr);
    ~Dialog_bx();

private:
    Ui::Dialog_bx *ui;

};

#endif // DIALOG_SY_DJ_BX_H
