#ifndef BATTERYSYSTEM_H
#define BATTERYSYSTEM_H

#include <iostream>

class BatterySystem {
protected:
    double MaxCapacity;
    double CurrentCharge;

public:
    BatterySystem(double max, double initial);

    void charge(double amount);
    double discharge(double needed);
    double getChargeLevel() const;
    double getMaxCapacity() const;

    void printProgressBar() const;
};

#endif