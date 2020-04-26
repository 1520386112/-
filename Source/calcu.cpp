#include "calcu.h"
#include <QWidget>

Calcu::Calcu()
{

}

void Calcu::cal_single_bedx(int fwdj, int fwmj, double ajcs, int ajns, long double dkll,
                            int &sf, int &dkze, int &hkys, int &yg, int &lx, int &hkze){
    sf = ((10-ajcs)/10.0) * fwdj * fwmj;
    dkze = (ajcs/10.0) * fwdj * fwmj;
    hkys = ajns * 12;
    //如果输入利率为0，，避免分母为0，，分开讨论
    if(dkll > 1e-6){
        yg = dkze * dkll *  powl(1+dkll, hkys) / (powl(1+dkll, hkys) - 1);
        lx = yg * hkys - dkze;
    }
    else{
        yg = dkze / hkys;
        lx = 0;
    }
    hkze = dkze + lx;
}

void Calcu::cal_single_bedj(int fwdj, int fwmj,double ajcs, int ajns, long double dkll,
                            int &sf, int &dkze, int &hkys, int &syyg, int &mydj, int &hkze,int &lx){
    sf = ((10-ajcs)/10.0) * fwdj * fwmj;
    dkze = (ajcs/10.0) * fwdj * fwmj;
    hkys = ajns * 12;
    syyg = (1.0 * dkze / hkys) + (dkze - 0) * dkll;
    mydj = floor((dkze - (dkze - (1.0 * dkze / hkys))) * dkll + 0.5);//四舍五入
    hkze = 0;
    long double yg = syyg;
    for(int i = hkys; i >= 1; --i){
        hkze += yg;
        yg -= (dkze - (dkze - (1.0 * dkze / hkys))) * dkll;
    }
    lx = hkze - dkze;

}

void Calcu::cal_totle_bedx(int dkze, int ajns, long double dkll, int &yg, int &lx, int &hkze, int &hkys){
    hkys = ajns * 12;
    //如果输入利率为0，，避免分母为0，，分开讨论
    if(dkll > 1e-6){
        yg = dkze * dkll *  powl(1+dkll, hkys) / (powl(1+dkll, hkys) - 1);
        lx = yg * hkys - dkze;
    }
    else{
        yg = dkze / hkys;
        lx = 0;
    }
    hkze = dkze + lx;
}

void Calcu::cal_totle_bedj(int dkze, int ajns, long double dkll, int &syyg, int &mydj, int &lx, int &hkze, int &hkys){
    hkys = ajns * 12;
    syyg = (1.0 * dkze / hkys) + (dkze - 0) * dkll;
    mydj = floor((dkze - (dkze - (1.0 * dkze / hkys))) * dkll + 0.5);//四舍五入
    hkze = 0;
    long double yg = syyg;
    for(int i = hkys; i >= 1; --i){
        hkze += yg;
        yg -= (dkze - (dkze - (1.0 * dkze / hkys))) * dkll;
    }
    lx = hkze - dkze;
}
