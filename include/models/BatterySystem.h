#ifndef BATTERYSYSTEM_H
#define BATTERYSYSTEM_H

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