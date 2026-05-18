#include<string>
#include"Factory.h"
#include "Common.h"

Factory::Factory(string n, double demand) {
    name = n;
    PowerDemand = demand;
    Priority = priority::Middle;
}

double Factory::getPowerDemand() {
    return PowerDemand;
}

priority Factory::getPriority(){
    return Priority;
}

void Factory::setStatus(ConnectionStatus status) {
    currentStatus = status; 

}