#include "UserInterface.h"
#include <iostream>
#include <limits>
#include "SmartLoadBalancer.h"
#include "BatterySystem.h"
#include "Factory.h"
#include "Hospital.h"
#include "ResidentialArea.h"
#include "SolarPlant.h"
#include "WindFarm.h"
#include "Common.h"

using namespace std;

void UserInterface::run() {
    setColor(MAGENTA);
    cout << "\n============================================\n";
    cout << CYAN << "   Smart Electricity Load Balancer\n" << MAGENTA;
    cout << "============================================\n";
    setColor(RESET);

    mainMenu();
}
void UserInterface::mainMenu() {
    while (true) {
        setColor(MAGENTA);
        cout << "\n=============== Main Menu ===============\n";
        setColor(BCYAN);
        cout << "  1. Add Energy Source\n";
        cout << "  2. Add Consumer\n";
        cout << "  3. Show System Status\n";
        cout << "  4. Balance Load\n";
        cout << "  5. Exit\n";
        setColor(MAGENTA);
        cout << "=========================================\n";
        setColor(RESET);

        int choice = safeInputInt("Choose option (1-5): ", 1, 5);
        if (choice == 1) addSource();
        else if (choice == 2) addConsumer();
        else if (choice == 3) showStatus();
        else if (choice == 4) balanceLoad();
        else break;
    }
}

void UserInterface::showStatus() {
    balancer.showStatus();
    battery.printProgressBar();
}

void UserInterface::addSource() {
    setColor(YELLOW); cout << "\nChoose energy source type:\n"; setColor(RESET);
    cout << "  1. Solar Plant\n  2. Wind Farm\n";
    int type = safeInputInt("Enter type number: ", 1, 2);
    string name = safeInputStr("Enter Name: ");
    double max = safeInputDouble("Max power (kW): ");
    if (type == 1) {
        double sun = safeInputDouble("Sun intensity [0-1]: ", false);
        balancer.addSource(new SolarPlant(name, max, sun));
        setColor(GREEN); cout << "Solar Plant added!\n"; setColor(RESET);
    } else {
        double wind = safeInputDouble("Wind speed (m/s): ", false);
        balancer.addSource(new WindFarm(name, max, wind));
        setColor(GREEN); cout << "Wind Farm added!\n"; setColor(RESET);
    }
}

void UserInterface::addConsumer() {
    setColor(YELLOW); cout << "\nChoose consumer type:\n"; setColor(RESET);
    cout << "  1. Factory\n  2. Hospital\n  3. Residential Area\n";
    int type = safeInputInt("Enter type number: ", 1, 3);
    string name = safeInputStr("Enter Name: ");
    double demand = safeInputDouble("Power demand (kW): ");
    if (type == 1) {
        balancer.addConsumer(new Factory(name, demand));
        setColor(GREEN); cout << " Factory added!\n"; setColor(RESET);
    } else if (type == 2) {
        balancer.addConsumer(new Hospital(name, demand));
        setColor(GREEN); cout << " Hospital added!\n"; setColor(RESET);
    } else {
        balancer.addConsumer(new ResidentialArea(name, demand));
        setColor(GREEN); cout << " Residential added!\n"; setColor(RESET);
    }
}

void UserInterface::balanceLoad() {
    balancer.balanceLoad();
    battery.printProgressBar();
}

double UserInterface::safeInputDouble(const std::string& prompt, bool nonNegative) {
    double x;
    while (true) {
        setColor(WHITE);
        cout << prompt;
        setColor(RESET);
        cin >> x;
        if (cin.fail() || (nonNegative && x < 0)) {
            setColor(RED);
            cout << " Invalid input! Enter a " << (nonNegative ? "NON-negative" : "valid") << " number.\n";
            setColor(RESET);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else { cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
    }
    return x;
}
int UserInterface::safeInputInt(const std::string& prompt, int minValue, int maxValue) {
    int x;
    while (true) {
        setColor(WHITE);
        cout << prompt;
        setColor(RESET);
        cin >> x;
        if (cin.fail() || x < minValue || x > maxValue) {
            setColor(RED);
            cout << " Please enter a number between " << minValue << " and " << maxValue << ".\n";
            setColor(RESET);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else { cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
    }
    return x;
}
std::string UserInterface::safeInputStr(const std::string& prompt) {
    setColor(WHITE); cout << prompt; setColor(RESET);
    std::string s;
    getline(cin, s);
    return s;
}