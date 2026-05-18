#include"BatterySystem.h"
#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;

BatterySystem::BatterySystem(double max, double initial) {
    MaxCapacity = max;
    CurrentCharge = initial;
}

void BatterySystem::charge(double amount) {
    double before = CurrentCharge;

    CurrentCharge = min(CurrentCharge + amount, MaxCapacity);

    cout << "🔋 Battery charged +"
         << (CurrentCharge - before)
         << " kWh → Level: "
         << CurrentCharge
         << "/"
         << MaxCapacity
         << " kWh\n";
}


double BatterySystem::discharge(double needed) {
    double available = min(needed, CurrentCharge);

    CurrentCharge -= available;

    cout << "🔋 Battery discharged -"
         << available
         << " kWh → Level: "
         << CurrentCharge
         << "/"
         << MaxCapacity
         << " kWh\n";

    return available;
}

double BatterySystem::getChargeLevel() {
    return CurrentCharge;
}