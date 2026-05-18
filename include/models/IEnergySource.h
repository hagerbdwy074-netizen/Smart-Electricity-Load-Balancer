#ifndef IENERGYSOURCE_H
#define IENERGYSOURCE_H

#include<string>
using namespace std;

class IEnergySource {

   public:
        string name;
        double MaxPower;

        virtual double getAvailablePower() = 0;
        virtual string getType() = 0;
        virtual ~IEnergySource() {}


};

#endif
