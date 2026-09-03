#ifndef SMARTLOADBALANCER_H
#define SMARTLOADBALANCER_H

#include <vector>

class IEnergySource;
class IConsumer;
class BatterySystem;

class SmartLoadBalancer {
private:
    std::vector<IEnergySource*> Sources;
    std::vector<IConsumer*> Consumers;
    BatterySystem* battery;

public:
    SmartLoadBalancer(BatterySystem* bat);

    void addSource(IEnergySource* src);
    void addConsumer(IConsumer* con);

    void showStatus();
    void balanceLoad();

};

#endif