#include"SolarPlant.h"

SolarPlant::SolarPlant(string n, double max, double sun) {
    name = n;
    MaxPower = max;
    sunLightLevel = sun;
}

double SolarPlant::getAvailablePower(){
    return MaxPower * sunLightLevel;
}

string SolarPlant::getType(){
    return "Solar ☀️";
}