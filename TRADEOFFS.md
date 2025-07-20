# Design Decisions and Trade-offs – ParkAndRide System

Every project comes with choices. Here's an overview of the trade-offs we made while building the ParkAndRide system:

## 🚦 Why C++

We chose **C++** because it gives us clean modularity and solid object-oriented structure. It’s great for organizing a large system with clearly defined responsibilities.

## 🗃️ Choosing the Right Data Structures

- We went with `unordered_map` where speed mattered — like looking up slots and reservations quickly.
- We skipped heavier STL containers like `deque`, since our use cases didn’t demand them, and this kept the codebase lighter and easier to maintain.

## 🎯 Simulated Features vs Real Implementations

- Some hardware-driven features like License Plate Recognition (LPR) and RFID were simplified. We used strings to simulate them instead of complex hardware integrations.
- For surge pricing, rather than implementing machine learning, we stuck to a rule-based approach. This keeps the logic transparent and easy to tweak based on demand patterns.

## ⚙️ Performance vs Simplicity

Speed is important, but so is clarity. We focused on making the system readable and modular — especially since this project is meant for presentation and learning. In some places, we chose clean design over maximum performance.

## 🔒 Offline Capability

To handle low-network zones (like underground parking), we simulated offline access using basic file storage. This helps users access reservations and sync back automatically when connected again — without needing a full database or cloud backend.

