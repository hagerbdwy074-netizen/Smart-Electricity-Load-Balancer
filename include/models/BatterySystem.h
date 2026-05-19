#ifndef BATTERYSYSTEM_H
#define BATTERYSYSTEM_H
#include "Common.h"
class BatterySystem {
private:
    double MaxCapacity;
    double CurrentCharge;

public:
    BatterySystem(double max, double initial);

    void charge(double amount);
    double discharge(double needed);
    double getChargeLevel();
};

#endif