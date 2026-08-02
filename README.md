# mini-4dof-robotarm
**> A 3D printed mini 4-DOF robotic arm featuring a removable control unit, multi-mode teleoperation, and Inverse Kinematics control—engineered around static torque analysis.**
Overall, this project provides a cost-effective, modular platform to practice Inverse Kinematics and experiment with different robotic arm geometries without needing to rebuild the underlying control hardware.

---

## 🎯 Project Goals
Low-Cost Kinematic Platform: Design and build an affordable 4-DOF mini robotic arm using budget-friendly electronics and minimal 3D printing filament.
Universal Modular Brain: Build a self-contained, well-built control enclosure that acts as a universal controller for future servo-based robotic arms.
Design for Manufacturability (DFM): Optimize CAD geometry during the design phase to minimize support structures and reduce material consumption.
Rigorous Engineering: Ensure all link sizing, structural decisions, and actuator choices are driven by real physical calculations rather than trial and error.

---

## 📌 Project Highlights

### 💡 Value Engineering & Hardware:
Universal Modular Brain: Powered by an ESP32 microcontroller paired with a PCA9685 16-channel 12-bit PWM servo driver. Offloading PWM generation to the PCA9685 allows for the brain to control robot arms with multiple servos (up to 16) that act at higher voltage (up to 12v).
Modular Mounting Interface: Uses an integrated sliding dovetail joint to quickly snap the Modular Brain into different arm bases. Dovetail sliders are isolated for easy 3D printing replacement in case of mechanical wear.

###🛠️ Mechanical Design & DFM
Minimal Support Printing: Engineered the entire linkage mechanism and brain housing to lay completely flat on the build plate, requiring  minimal support material.
Material & Weight Optimization: Applied recessed geometry in non-critical structural areas of the brain housing to minimize filament consumption.
Anti-Tipping Optimization: Designed the arm base with top surface recesses and dense bottom infill to lower the overall Center of Gravity (CG) and prevent tip-over during rapid movements.

### 📐 Static Torque Analysis & Link Sizing
- Sized arm link lengths around the strict holding torque limits of the shoulder servo (reported 2.2 kg/cm stall torque).
- Created a free-body diagram assuming link material density and cross-sectional areas, applying a 1.5× safety factor to servo self-weight alongside a **30g point-mass payload** at the end effector.

### 🎛️ Control & Teleoperation
The brain is designed to handle three control structures:
 (🟢Current): Wireless teleoperation via command packets sent over Bluetooth from a custom mobile app built with MIT App Inventor.
 (🟡In Development): Trigonometric / Vector-based Inverse Kinematics (IK) solver for direct (X, Y, Z) Cartesian positioning.
 (🟡In Development): Waldo-Style Master Controller for direct 1:1 physical teleoperation and motion tracking.







