#include"BatterySystem.h"
#include<iostream>
#include<string>
#include<algorithm>
#include"Common.h"
using namespace std;

BatterySystem::BatterySystem(double max, double initial) {
    MaxCapacity = max;
    CurrentCharge = initial;
}

void BatterySystem::charge(double amount) {
    double before = CurrentCharge;
    CurrentCharge = min(CurrentCharge + amount, MaxCapacity);

    setColor(GREEN);
    cout << "🔋 Battery charged +"
         << (CurrentCharge - before)
         << " kWh → Level: "
         << CurrentCharge
         << "/"
         << MaxCapacity
         << " kWh\n";
    setColor(RESET);
}

double BatterySystem::discharge(double needed) {
    double available = min(needed, CurrentCharge);

    CurrentCharge -= available;

    setColor(YELLOW);
    cout << "Battery discharged -"
         << available
         << " kWh → Level: "
         << CurrentCharge
         << "/"
         << MaxCapacity
         << " kWh\n";
    setColor(RESET);

    return available;
}

double BatterySystem::getChargeLevel() {
    return CurrentCharge;
}