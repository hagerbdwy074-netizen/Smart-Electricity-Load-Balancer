#include<string>
#include"ResidentialArea.h"
#include "Common.h"
 
ResidentialArea::ResidentialArea(string n, double demand) {
    name = n;
    PowerDemand = demand;
    Priority = priority::Normal;
}

double ResidentialArea::getPowerDemand() {
    return PowerDemand;
}

priority ResidentialArea::getPriority() {
    return Priority;
}

void ResidentialArea::setStatus(ConnectionStatus status) {
    currentStatus = status;
}