#include "SmartLoadBalancer.h"
#include "IEnergySource.h"
#include "IConsumer.h"
#include "BatterySystem.h"
#include "Common.h"
#include <iostream>
using namespace std;

SmartLoadBalancer::SmartLoadBalancer(BatterySystem* bat) {
    battery = bat;
}

void SmartLoadBalancer::addSource(IEnergySource* src) {
    Sources.push_back(src);
}

void SmartLoadBalancer::addConsumer(IConsumer* con) {
    Consumers.push_back(con);
}

void SmartLoadBalancer::showStatus() {
    setColor(MAGENTA);
    cout << "\n========================================\n"
         << "        SYSTEM STATUS REPORT\n"
         << "========================================\n";
    setColor(RESET);

    setColor(CYAN);
    cout << "\n[Energy Sources]\n";
    setColor(RESET);

    for (auto s : Sources) {
        setColor(GREEN);
        cout << "  " << s->getType()
             << " | " << s->name
             << " → "
             << s->getAvailablePower() << " kW available\n";
        setColor(RESET);
    }

    setColor(CYAN);
    cout << "\n[Consumers]\n";
    setColor(RESET);

    for (auto c : Consumers) {
        setColor(WHITE); cout << "  Priority ";
        setColor(YELLOW); cout << c->getPriority();
        setColor(WHITE); cout << " | ";
        setColor(CYAN); cout << c->name;
        setColor(WHITE); cout << " → needs ";
        setColor(GREEN); cout << c->getPowerDemand() << " kW\n";
        setColor(RESET);
    }

    setColor(MAGENTA);
    cout << "\n[Battery]\n";
    setColor(WHITE);
    cout << "  Charge Level: ";
    setColor(GREEN); cout << battery->getChargeLevel() << " kWh\n";
    setColor(MAGENTA);
    cout << "========================================\n";
    setColor(RESET);
}

void SmartLoadBalancer::balanceLoad() {
    setColor(BCYAN);
    cout << "\n==============================\n"
         << "      LOAD BALANCING DECISION\n"
         << "==============================\n";
    setColor(RESET);

    double totalDemand = 0;
    for (auto c : Consumers) {
        c->setStatus(ConnectionStatus::Connected);
        totalDemand += c->getPowerDemand();
    }

    double totalRenewable = 0;
    for (auto s : Sources) {
        totalRenewable += s->getAvailablePower();
    }

    setColor(YELLOW);
    cout << "\nTotal Demand   : " << totalDemand << " kW\n";
    cout << "Renewable Power: " << totalRenewable << " kW\n";
    setColor(RESET);

    if (totalRenewable >= totalDemand) {
        double excess = totalRenewable - totalDemand;
        setColor(GREEN);
        cout << "\n Renewables cover everything!\n";
        cout << "Excess power: " << excess << " kW → charging battery\n";
        setColor(RESET);
        battery->charge(excess);
    }
    else {
        double deficit = totalDemand - totalRenewable;
        setColor(YELLOW);
        cout << "\nDeficit: " << deficit << " kW\n";
        cout << "Trying battery...\n";
        setColor(RESET);

        double fromBattery = battery->discharge(deficit);
        double remainingDeficit = deficit - fromBattery;

        if (remainingDeficit <= 0) {
            setColor(GREEN);
            cout << "Battery covered the deficit!\n";
            setColor(RESET);
        } else {
            setColor(RED);
            cout << "\nEMERGENCY! Need " << remainingDeficit << " kW. Starting smart load shedding...\n";
            setColor(RESET);

            for (auto c : Consumers) {
                if (c->getPriority() == priority::Normal && remainingDeficit > 0) {
                    setColor(RED);
                    cout << " Disconnecting (Normal Priority): " << c->name
                         << " (Saved " << c->getPowerDemand() << " kW)\n";
                    setColor(RESET);

                    c->setStatus(ConnectionStatus::Disconnected);
                    remainingDeficit -= c->getPowerDemand();
                }
            }

            for (auto c : Consumers) {
                if (c->getPriority() == priority::Middle && remainingDeficit > 0) {
                    setColor(RED);
                    cout << " Disconnecting (Middle Priority): " << c->name
                         << " (Saved " << c->getPowerDemand() << " kW)\n";
                    setColor(RESET);

                    c->setStatus(ConnectionStatus::Disconnected);
                    remainingDeficit -= c->getPowerDemand();
                }
            }

            if (remainingDeficit > 0) {
                setColor(RED);
                cout << " CRITICAL: Even after cutting off normal and middle sectors, we still lack "
                     << remainingDeficit << " kW from Main Grid!\n";
                setColor(RESET);
            }
        }
    }
    setColor(BCYAN);
    cout << "==============================\n";
    setColor(RESET);
}