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

    cout << "\n========================================\n";
    cout << "        SYSTEM STATUS REPORT\n";
    cout << "========================================\n";

    cout << "\n[Energy Sources]\n";

   for (auto s : Sources) {
          cout << "  "
               << s->getType()
               << " | "
               << s->name
               << " → "
               << s->getAvailablePower()
               << " kW available\n";
    }

    cout << "\n[Consumers]\n";

    for (auto c : Consumers) {
            cout << "  Priority "
                 << c->getPriority()
                 << " | "
                 << c->name
                 << " → needs "
                 << c->getPowerDemand()
                 << " kW\n";
        }

    cout << "\n[Battery]\n";
    cout << "  Charge Level: "
         << battery->getChargeLevel()
         << " kWh\n";
    cout << "========================================\n";
}

void SmartLoadBalancer::balanceLoad() {
    cout << "\n==============================\n";
    cout << "      LOAD BALANCING DECISION\n";
    cout << "==============================\n";

    double totalDemand = 0;
    for (auto c : Consumers) {
        c->setStatus(ConnectionStatus::Connected); 
        totalDemand += c->getPowerDemand();
    }

    double totalRenewable = 0;
    for (auto s : Sources) {
        totalRenewable += s->getAvailablePower();
    }

      cout << "\nTotal Demand   : " << totalDemand << " kW\n";
      cout << "Renewable Power: " << totalRenewable << " kW\n";

    if (totalRenewable >= totalDemand) {
        double excess = totalRenewable - totalDemand;
          cout << "\n✅ Renewables cover everything!\n";
          cout << "Excess power: " << excess << " kW → charging battery\n";
        battery->charge(excess);
    } 

    else {
        double deficit = totalDemand - totalRenewable;
           cout << "\n⚠️ Deficit: " << deficit << " kW\n";
           cout << "Trying battery...\n";

        double fromBattery = battery->discharge(deficit);
        double remainingDeficit = deficit - fromBattery;

    if (remainingDeficit <= 0) {
          cout << "✅ Battery covered the deficit!\n";
       } else {
          cout << "\n🚨 EMERGENCY! Need " << remainingDeficit << " kW. Starting smart load shedding...\n";
            
    for (auto c : Consumers) {
        if (c->getPriority() == priority::Normal && remainingDeficit > 0) {
              cout << "❌ Disconnecting (Normal Priority): " << c->name 
                   << " (Saved " << c->getPowerDemand() << " kW)\n";
                    
                c->setStatus(ConnectionStatus::Disconnected);
                remainingDeficit -= c->getPowerDemand();
                }
            }

    for (auto c : Consumers) {
        if (c->getPriority() == priority::Middle && remainingDeficit > 0) {
                cout << "❌ Disconnecting (Middle Priority): " << c->name 
                     << " (Saved " << c->getPowerDemand() << " kW)\n";
                    
                c->setStatus(ConnectionStatus::Disconnected);
                remainingDeficit -= c->getPowerDemand();
                }
            }

            if (remainingDeficit > 0) {
                cout << "🚨 CRITICAL: Even after cutting off normal and middle sectors, we still lack " 
                     << remainingDeficit << " kW from Main Grid!\n";
            }
        }
    }
     cout << "==============================\n";
}