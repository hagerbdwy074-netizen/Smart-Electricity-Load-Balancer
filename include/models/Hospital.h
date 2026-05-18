#ifndef HOSPITAL_H
#define HOSPITAL_H

#include"IConsumer.h"
#include "Common.h"
#include<string>
#include<iostream>

class Hospital : public IConsumer {
public:
    Hospital(string n, double demand);

    double getPowerDemand() override;
    priority getPriority() override;

    void setStatus(ConnectionStatus status) override;

};

#endif