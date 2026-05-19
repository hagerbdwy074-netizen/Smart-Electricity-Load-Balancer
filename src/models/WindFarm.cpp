#include"WindFarm.h"

WindFarm::WindFarm(string n, double max, double wind) {
     name = n;
     MaxPower = max;
     WindSpeed = wind;

}

double WindFarm::getAvailablePower(){
    if ( WindSpeed < 3.0 )
        return 0;

    return MaxPower * (WindSpeed / 15.0);

}

string WindFarm::getType(){
    return "Wind";
}