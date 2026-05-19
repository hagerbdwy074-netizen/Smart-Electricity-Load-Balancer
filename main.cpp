#include <iostream>
#include <string>
#include "Common.h"

// hack to access private for demo
#define private public
#include "SmartLoadBalancer.h"
#undef private

#include "SolarPlant.h"
#include "WindFarm.h"
#include "BatterySystem.h"

using namespace std;

void printTitle() {
    setColor(MAGENTA);
    cout << "============================================\n";
    cout << CYAN << "   Smart Electricity Load Balancer Demo\n" << MAGENTA;
    cout << "============================================\n";
    setColor(RESET);
    cout << "This program simulates load balancing between\n";
    cout << "solar/wind energy, battery backup, and consumers\n";
    cout << endl;
    setColor(CYAN);
    cout << "[You will enter system data step by step.]\n";
    setColor(RESET);
}

void waitForEnter() {
    setColor(WHITE);
    cout << endl << "Press Enter to continue ..." << endl;
    setColor(RESET);
    cin.ignore();
    cin.get();
}

int main() {
    printTitle();
    // 1. Battery setup
    double batMax, batInit;
    setColor(YELLOW);
    cout << "[Battery System Setup]\n";
    setColor(WHITE); cout << " - Maximum Capacity (kWh): "; setColor(RESET);
    cin >> batMax;
    setColor(WHITE); cout << " - Initial Charge (kWh): "; setColor(RESET);
    cin >> batInit;
    BatterySystem* battery = new BatterySystem(batMax, batInit);

    // 2. Create SmartLoadBalancer object
    SmartLoadBalancer balancer(battery);

    waitForEnter();

    // 3. Solar Plant setup
    string solarName;
    double solarMax, solarSun;
    setColor(BCYAN);
    cout << "[Solar Plant Setup]\n";
    setColor(WHITE); cout << " - Name: "; setColor(RESET);
    cin >> solarName;
    setColor(WHITE); cout << " - Maximum Output (kW): "; setColor(RESET);
    cin >> solarMax;
    setColor(WHITE); cout << " - Sun Intensity [0~1]: "; setColor(RESET);
    cin >> solarSun;
    SolarPlant* solar = new SolarPlant(solarName, solarMax, solarSun);

    // 4. Wind Farm setup
    string windName;
    double windMax, windSpeed;
    setColor(BCYAN);
    cout << "[Wind Farm Setup]\n";
    setColor(WHITE); cout << " - Name: "; setColor(RESET);
    cin >> windName;
    setColor(WHITE); cout << " - Maximum Output (kW): "; setColor(RESET);
    cin >> windMax;
    setColor(WHITE); cout << " - Wind Speed (m/s): "; setColor(RESET);
    cin >> windSpeed;
    WindFarm* wind = new WindFarm(windName, windMax, windSpeed);

    balancer.Sources.push_back(solar);
    balancer.Sources.push_back(wind);

    waitForEnter();

    // 5. Consumer setup (optional improvement idea)
    setColor(YELLOW);
    cout << "[Add consumers in code for more realism]\n";
    setColor(RESET);

    // 6. Show system status
    balancer.showStatus();

    waitForEnter();

    // 7. Perform load balancing
    balancer.balanceLoad();

    waitForEnter();

    setColor(GREEN);
    cout << "Simulation finished. Thank you for using the Smart Load Balancer!\n";
    setColor(RESET);

    delete solar;
    delete wind;
    delete battery;
    return 0;
}