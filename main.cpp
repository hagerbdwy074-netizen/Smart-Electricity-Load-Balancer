#include <iostream>
#include <string>

#define private public
#include "SmartLoadBalancer.h"
#undef private

#include "SolarPlant.h"
#include "WindFarm.h"
#include "BatterySystem.h"

using namespace std;

int main() {
    cout << "Smart Electricity Load Balancer Configuration\n";
    cout << "---------------------------------------------\n";

    double batMax, batInit;
    cout << "[Battery System Setup]\n";
    cout << "Enter Max Capacity (kW): ";
    cin >> batMax;
    cout << "Enter Initial Charge (kW): ";
    cin >> batInit;
    
    BatterySystem* battery = new BatterySystem(batMax, batInit);

    SmartLoadBalancer balancer(battery);

    // 3. Gather Solar Plant Data
    string solarName;
    double solarMax, solarSun;
    cout << "\n[Solar Plant Setup]\n";
    cout << "Enter Name (single word): ";
    cin >> solarName;
    cout << "Enter Max Capacity (kW): ";
    cin >> solarMax;
    cout << "Enter Sun Intensity: ";
    cin >> solarSun;
    
    SolarPlant* solar = new SolarPlant(solarName, solarMax, solarSun);

    string windName;
    double windMax, windWind;
    cout << "\n[Wind Farm Setup]\n";
    cout << "Enter Name (single word): ";
    cin >> windName;
    cout << "Enter Max Capacity (kW): ";
    cin >> windMax;
    cout << "Enter Wind Speed: ";
    cin >> windWind;
    
    WindFarm* wind = new WindFarm(windName, windMax, windWind);

    balancer.Sources.push_back(solar);
    balancer.Sources.push_back(wind);

    balancer.showStatus();

    delete solar;
    delete wind;
    delete battery;

    return 0;
}