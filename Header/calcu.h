#ifndef CALCU_H
#define CALCU_H

/**
 * @brief The Calcu class
 * 计算方式类，免得重复写那么多遍orz
 */
class Calcu
{
public:
    static Calcu* Get_Instance(){
        static Calcu calcu;
        return &calcu;
    }

    void cal_single_bedx(int fwdj, int fwmj, double ajcs, int ajns, long double dkll,
                         int &sf, int &dkze, int &hkys, int &yg, int &lx, int &hkze);
    void cal_single_bedj(int fwdj, int fwmj,double ajcs, int ajns, long double dkll,
                         int &sf, int &dkze, int &hkys, int &syyg, int &mydj, int &hkze,int &lx);
    void cal_totle_bedx(int dkze, int ajns, long double dkll, int &yg, int &lx, int &hkze, int &ys);
    void cal_totle_bedj(int dkze, int ajns, long double dkll, int &syyg, int &mydj, int &lx, int &hkze, int &hkys);
private:
    Calcu();
};

#endif // CALCU_H
