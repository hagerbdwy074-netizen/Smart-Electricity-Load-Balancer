#ifndef FACTORY_H
#define FACTORY_H

#include<string>
#include"IConsumer.h"
#include "Common.h"

class Factory : public IConsumer {
 public:
     Factory(string n, double demand);

     double getPowerDemand() override;
     priority getPriority() override;

     void setStatus(ConnectionStatus status) override;

};

#endif