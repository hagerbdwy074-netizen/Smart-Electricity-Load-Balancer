#ifndef ICONSUMER_H
#define ICONSUMER_H

#include<iostream>
#include<string>
#include "Common.h"
using namespace std;

class IConsumer {
public:
    string name;
    double PowerDemand;
    priority Priority;
    ConnectionStatus currentStatus;

    virtual double getPowerDemand() = 0;
    virtual priority getPriority() = 0;
    virtual void setStatus(ConnectionStatus status) = 0;

    virtual ~IConsumer() {}
};

inline ostream& operator<<(ostream& out, priority p) {
    switch (p)
    {

    case priority::High:
        out << "High" ;
    break;

    case priority::Middle:
        out << "Middle";
    break;

    case priority::Normal:

        out << "Normal";
    break;

    }
    
    return out;
}

#endif