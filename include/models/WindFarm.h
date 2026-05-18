#ifndef WINDFARM_H
#define WINDFARM_H

#include"IEnergySource.h"
using namespace std;

class WindFarm : public IEnergySource {
private:
    double WindSpeed;

public:
    WindFarm(string n, double max, double wind);
    
    double getAvailablePower() override;
    string getType() override;

};

#endif