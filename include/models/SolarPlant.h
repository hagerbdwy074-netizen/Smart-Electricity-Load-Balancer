#ifndef SOLARPLANT_H
#define SOLARPLANT_H

#include <iostream>
#include "IEnergySource.h"
using namespace std;

class SolarPlant : public IEnergySource {
private:
    double sunLightLevel;

public:
    SolarPlant(string n, double max, double sun);

    double getAvailablePower() override;
    string getType() override;
};

#endif