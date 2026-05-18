#include<string>
#include"Hospital.h"
#include "Common.h"

Hospital::Hospital(string n, double demand) {
    name = n;
    PowerDemand = demand;
    Priority = priority::High;
}

double Hospital::getPowerDemand() {
    return PowerDemand;
}

priority Hospital::getPriority() {
    return Priority;
}

void Hospital::setStatus(ConnectionStatus status) {
    currentStatus = status; 

}