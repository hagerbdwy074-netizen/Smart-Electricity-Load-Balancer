#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
class SmartLoadBalancer;
class BatterySystem;

class UserInterface {
private:
    SmartLoadBalancer& balancer;
    BatterySystem& battery;

    void mainMenu();
    void showStatus();
    void addSource();
    void addConsumer();
    void balanceLoad();
    double safeInputDouble(const std::string& prompt, bool nonNegative=true);
    int safeInputInt(const std::string& prompt, int minValue=0, int maxValue=1000);
    std::string safeInputStr(const std::string& prompt);

public:
    UserInterface(SmartLoadBalancer& bl, BatterySystem& bat)
        : balancer(bl), battery(bat) {}

    void run();
};

#endif