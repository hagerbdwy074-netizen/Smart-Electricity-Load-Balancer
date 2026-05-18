#ifndef RESIDENTIALAREA_H
#define RESIDENTIALAREA_H

#include<string>
#include"IConsumer.h"
#include "Common.h"

class ResidentialArea : public IConsumer {
public:
    ResidentialArea(string n, double demand);

    double getPowerDemand() override;
    priority getPriority() override;

    void setStatus(ConnectionStatus status) override;
};

#endif