#include "BatterySystem.h"
#include <iostream>
#include <algorithm>
#include "Common.h"
#include "UserInterface.h"

using namespace std;

BatterySystem::BatterySystem(double max, double initial) {
    MaxCapacity = max;
    CurrentCharge = initial;
}

void BatterySystem::charge(double amount) {
    double before = CurrentCharge;
    CurrentCharge = min(CurrentCharge + amount, MaxCapacity);
    setColor(GREEN);
    cout << " Battery charged +" << (CurrentCharge-before) << " kWh → Level: " 
         << CurrentCharge << "/" << MaxCapacity << " kWh\n";
    setColor(RESET);
    printProgressBar();
}
double BatterySystem::discharge(double needed) {
    double available = min(needed, CurrentCharge);
    CurrentCharge -= available;
    setColor(YELLOW);
    cout << " Battery discharged -" << available << " kWh → Level: "
         << CurrentCharge << "/" << MaxCapacity << " kWh\n";
    setColor(RESET);
    printProgressBar();
    return available;
}
double BatterySystem::getChargeLevel() const {
    return CurrentCharge;
}
double BatterySystem::getMaxCapacity() const {
    return MaxCapacity;
}
void BatterySystem::printProgressBar() const {
    setColor(CYAN);
    int width = 30;
    double percent = (MaxCapacity > 0 ? CurrentCharge/MaxCapacity : 0);
    int filled = static_cast<int>(percent * width);

    cout << "[";
    setColor(GREEN);
    for(int i=0;i<filled;i++) cout << "#";
    setColor(RED);
    for(int i=filled;i<width;i++) cout << "-";
    setColor(CYAN);
    cout << "] ";
    setColor(WHITE);
    cout << int(percent*100+0.5) << "%\n";
    setColor(RESET);
}