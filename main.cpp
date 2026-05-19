#include <iostream>
#include "BatterySystem.h"
#include "SmartLoadBalancer.h"
#include "UserInterface.h"

int main() {
    double batMax, batInit;
    std::cout << "Enter Battery Max Capacity (kWh): ";
    std::cin >> batMax;
    do {
        std::cout << "Enter Battery Initial Charge (kWh): ";
        std::cin >> batInit;
        if (batInit > batMax) std::cout << "Cannot exceed max capacity!\n";
    } while (batInit > batMax);
    std::cin.ignore(); 

    BatterySystem* battery = new BatterySystem(batMax, batInit);
    SmartLoadBalancer balancer(battery);
    UserInterface ui(balancer, *battery);
    ui.run();

    delete battery;
    return 0;
}