# ⚡ Smart Electricity Load Balancer
### *A C++ Simulation for Intelligent Power Distribution*

---

> 🔌 **What if software could decide who keeps the lights on?**
> This project does exactly that — simulating a smart power grid manager
> that distributes electricity intelligently, prioritizes critical consumers,
> and sheds load gracefully when supply runs short.

---

## 📋 Table of Contents

- [🌍 Introduction](#-introduction)
- [⚙️ How It Works](#️-how-it-works)
- [✨ Major Features](#-major-features)
- [🏥 Use Case Scenario](#-use-case-scenario)
- [🏗️ Technical Design (OOP)](#️-technical-design-oop)
- [🎓 Educational Value](#-educational-value)
- [🚀 Future Extensions](#-future-extensions)
- [✅ Conclusion](#-conclusion)

---

## 🌍 Introduction

Every day, power grids around the world face a deceptively hard problem:
**too many consumers, not enough electricity, and zero margin for error.**

When a hospital is fighting to keep its ICU machines running during a blackout,
while a shopping mall down the street still has its escalators going —
*someone or something has to make the call about where the power goes first.*

The **Smart Electricity Load Balancer** is a C++ simulation project that models
exactly this challenge. It manages multiple energy sources
(solar panels, generators, battery storage) and distributes their combined
capacity across multiple consumer groups — each carrying a different
priority level — using intelligent load balancing algorithms implemented
through clean object-oriented design.

> 💡 **Why does this matter?**
> Load shedding (rolling blackouts) is a growing reality in many countries.
> Egypt, South Africa, Pakistan and many others deal with scheduled power cuts daily.
> A smarter management layer — one that *knows* a hospital matters more than a gym —
> could save lives and reduce economic damage.

---

> 🔬 **Circuit Analogy for Electronics folks:**
> Think of it as a smart **multiplexer (MUX) for power lines.**
> Just like a digital MUX selects one of many inputs based on a control word,
> this system selects which loads stay active based on available capacity
> and priority flags — but dynamically, in real time.

---

## ⚙️ How It Works

The program runs through a clean, interactive flow:

```
[ Start ] → [ Define Sources ] → [ Register Consumers ]
         → [ Run Balancer ]  → [ Display Results ]
         → [ Adjust / Repeat ]
```

### Step-by-step:

**① Define Energy Sources 🔋**
The user inputs available power sources — solar panels (variable output),
diesel generators (fixed capacity), or battery banks (limited reserve).
Each source has a current output level and a maximum rated capacity in kW.

**② Register Consumer Groups 🏘️**
Each consumer group (hospitals, residential, commercial, etc.)
is given a power demand in kW and a **priority level** (1 = critical → 5 = optional).
These are stored internally in a sorted priority structure.

**③ Run the Balancer ⚡**
The core algorithm:
- Aggregates total available power from all sources
- Iterates through consumers from **highest → lowest priority**
- Allocates power until capacity is exhausted
- Marks remaining consumers as **"load shed"** 🔴

**④ View Results & Interact 📊**
The system displays a full status table:
which consumers are powered ✅, which are shed 🔴,
total load vs. total capacity, and source utilization percentages.

**⑤ Adjust & Re-simulate 🔁**
The user can modify source outputs, add consumers, or change priorities
and re-run the balancer — simulating dynamic grid conditions in real time.

---

## ✨ Major Features

| Feature | Description |
|---|---|
| 🎛️ **Interactive Menu** | Clean terminal UI with numbered options and input validation |
| ⚖️ **Auto Load Balancing** | Greedy priority-based allocation algorithm |
| 🔴 **Load Shedding** | Graceful shutdown of low-priority consumers when capacity is exceeded |
| 📊 **Progress Bars** | Visual ASCII bars showing source utilization and load percentages |
| 🔋 **Multi-Source Support** | Solar, generator, battery — each with unique behavior |
| 🏥 **Priority System** | 5-level priority scale for consumer groups |
| 🛡️ **Input Validation** | Guards against invalid data at every input point |
| 📈 **Status Dashboard** | Real-time summary of grid state after every balancing cycle |
| ♻️ **Re-simulation** | Adjust parameters and re-run without restarting the program |

---

## 🏥 Use Case Scenario

### *"The 6 PM Crisis"*

Imagine a small city during a summer evening peak.
The grid manager sets up the simulation with these inputs:

**🔌 Sources:**
- Solar Farm → 200 kW (dropping fast — it's sunset)
- Diesel Generator → 150 kW (online)
- Battery Bank → 80 kW (50% charged, reserve mode)
- **Total Available: 430 kW**

**🏘️ Consumers:**
| Group | Demand | Priority |
|---|---|---|
| 🏥 Hospital Complex | 180 kW | 1 (Critical) |
| 🚦 Traffic & Street Lights | 60 kW | 2 (Important) |
| 🏠 Residential Zone A | 120 kW | 3 (Normal) |
| 🏬 Commercial Mall | 100 kW | 4 (Low) |
| 🎮 Entertainment Center | 90 kW | 5 (Optional) |
| **Total Demand** | **550 kW** | — |

**Result from the Balancer:**
- ✅ Hospital → **Powered** (180 kW allocated)
- ✅ Traffic Lights → **Powered** (60 kW allocated)
- ✅ Residential Zone A → **Powered** (120 kW allocated)
- ⚠️ Commercial Mall → **Partially powered** (70 kW — last of supply)
- 🔴 Entertainment Center → **Load shed** (0 kW)

> The system saved power for what matters most —
> automatically, without human intervention. 🎯

---

## 🏗️ Technical Design (OOP)

The project is organized around the principle of **Single Responsibility** —
each class owns one concept, and classes communicate through clean interfaces.

```
📦 Project Structure
│
├── 🔌 EnergySource (base class)
│   ├── SolarPanel  (variable output)
│   ├── Generator   (fixed output)
│   └── BatteryBank (reserve + depletion logic)
│
├── 🏘️ Consumer
│   ├── name, demand_kw, priority_level
│   └── status (POWERED / SHED)
│
├── ⚖️ LoadBalancer
│   ├── vector<EnergySource*> sources
│   ├── priority_queue<Consumer> consumers
│   └── balance() — core algorithm
│
└── 🖥️ UI / Menu Handler
    └── display, input validation, progress bars
```

### Key OOP Concepts Used:

| Concept | Where Applied |
|---|---|
| **Inheritance** | `SolarPanel`, `Generator`, `BatteryBank` all extend `EnergySource` |
| **Polymorphism** | `getOutput()` behaves differently per source type |
| **Encapsulation** | Internal state hidden behind clean getters/setters |
| **Vectors** | Dynamic list of sources and consumers |
| **Priority Queue** | Auto-sorts consumers by priority for the balancer |
| **Operator Overloading** | `<` overloaded on `Consumer` for priority comparison |

> 🔬 **Electronics Analogy:**
> The class hierarchy mirrors a **layered PCB design** —
> the base class is the schematic symbol,
> subclasses are the specific component footprints,
> and `LoadBalancer` is the PCB that routes everything together.

---

## 🎓 Educational Value

This project is a goldmine for learners at multiple levels:

**For students learning C++ OOP** 📚
The project demonstrates all major OOP pillars in a context
that actually makes sense — not contrived "Animal → Dog" examples,
but real engineering logic that maps to physical systems.

**For electronics/embedded students** 🔧
The concepts map directly to real hardware:
priority interrupts ↔ consumer priorities,
ISR scheduling ↔ load balancing algorithm,
PWM duty cycle ↔ percentage allocation.
The simulation gives intuition that translates to real RTOS and power management firmware.

**For software engineering students** 🏗️
The project models good practices:
separation of concerns, modular classes, input validation,
and a clean separation between business logic and UI.

**For instructors and evaluators** 👨‍🏫
The project covers: dynamic memory, STL containers, inheritance hierarchies,
algorithm design, and user interaction — making it suitable as a
capstone project for a first- or second-year C++ course.

---

## 🚀 Future Extensions

The project is intentionally designed to be **extensible**. Here are exciting directions:

**🖥️ Graphical Interface (GUI)**
Replace the terminal UI with a Qt or SFML-based visual dashboard
showing live bar charts, animated power flow between sources and consumers,
and real-time shedding events.

**📡 Real-Time Simulation Mode**
Add a time loop that simulates changing conditions over 24 hours —
solar output rising at dawn, peak demand at evening, battery depleting overnight.

**📝 Data Logging & Reports**
Export simulation results to `.csv` or `.json` for external analysis —
track which consumers were shed the most across multiple runs.

**🌐 Network / Multi-Node Grids**
Extend to simulate multiple interconnected sub-grids that can trade power
between each other — closer to a real smart grid topology.

**🤖 AI-Based Scheduling**
Replace the greedy algorithm with a simple ML model (or even a rule-based
fuzzy logic system) that learns optimal shedding patterns from historical data.

**🔌 Embedded Port (Arduino / ESP32)**
Port the core balancing logic to embedded C for a real hardware demo —
use relays to physically switch loads on/off based on the algorithm's output.

---

## ✅ Conclusion

The **Smart Electricity Load Balancer** is more than a C++ exercise —
it's a miniaturized model of a real engineering challenge that affects millions of people.

By combining **object-oriented software design** with **power systems concepts**,
it sits at an intersection that is rare and valuable:
code that solves a problem you can *feel* and *see* in the physical world.

Whether you're a student building your portfolio, an instructor looking for a
compelling capstone project, or an engineer exploring software simulations of
physical systems — this project offers something meaningful at every level.

> *"Good software doesn't just run correctly.*
> *It mirrors the logic of the real world it was built to serve."* 💡

---

<div align="center">

**Built with C++ · Powered by OOP · Designed for Real-World Impact**

⚡ `SmartLoadBalancer v1.0` ⚡

</div>
