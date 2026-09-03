#include <emscripten/bind.h>
#include <string>

#include "core/SmartLoadBalancer.h"
#include "models/IConsumer.h"
#include "models/IEnergySource.h"
#include "models/BatterySystem.h"

std::string run_simulation() {
    BatterySystem battery(100.0, 50.0);
    SmartLoadBalancer balancer(&battery);

    balancer.balanceLoad();

    return "Simulation completed successfully via C++ Engine!";
}

EMSCRIPTEN_BINDINGS(smart_grid_module) {
    emscripten::function("run_simulation", &run_simulation);
}