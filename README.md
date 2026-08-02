# mini-4dof-robotarm
<img width="1076" height="639" alt="image" src="https://github.com/user-attachments/assets/9d78bf51-481e-4d2a-8f52-8cb341e40c66" />

**> A 3D printed mini 4-DOF robotic arm featuring a removable control unit, multi-mode teleoperation, and Inverse Kinematics control—engineered around static torque analysis.**

Overall, this project provides a cost-effective, modular platform to practice Inverse Kinematics and experiment with different robotic arm geometries without needing to rebuild the underlying control hardware.

---

## **❗IMPORTANT NOTE❗**
<img width="963" height="593" alt="image" src="https://github.com/user-attachments/assets/a746f76f-75af-4b1d-aa84-3ee81d45ec35" />

- this project is a PROTOTYPE, there are still some minor issues with the mechanical design and parts to be improved and are in development
- this github repo is currently under construction, only major content has been added and there may be some missing files and information.

---

## *🎯 Project Goals*
**Low-Cost Kinematic Platform:** Design and build an affordable 4-DOF mini robotic arm using budget-friendly electronics and minimal 3D printing filament.

**Universal Modular Brain:** Build a self-contained, well-built control enclosure that acts as a universal controller for future servo-based robotic arms.

**Design for Manufacturability (DFM):** Optimize CAD geometry during the design phase to minimize support structures and reduce material consumption.

**Rigorous Engineering:** Ensure all link sizing, structural decisions, and actuator choices are driven by real physical calculations rather than trial and error.

---

## 📌 Project Highlights

### 💡 Value Engineering & Hardware:
**Universal Modular Brain:** Powered by an ESP32 microcontroller paired with a PCA9685 16-channel 12-bit PWM servo driver. Offloading PWM generation to the PCA9685 allows for the brain to control robot arms with multiple servos (up to 16) that act at higher voltage (up to 12v).


<img width="1108" height="489" alt="image" src="https://github.com/user-attachments/assets/a6f260f7-b614-4dae-a280-c4fb460c2c49" />
<img width="1079" height="473" alt="image" src="https://github.com/user-attachments/assets/77d55f2f-6ca0-4421-a9e3-c9ba4d7145a9" />


**Modular Mounting System:** Uses an integrated sliding dovetail joint to quickly snap the Modular Brain into different arm bases. Dovetail sliders are isolated for easy 3D printing replacement in case of mechanical wear.

### 🛠️ Mechanical Design & DFM
**Minimal Support Printing:** Engineered the entire linkage mechanism and brain housing to lay completely flat on the build plate, requiring  minimal support material.


<img width="738" height="707" alt="image" src="https://github.com/user-attachments/assets/ea1f6c0b-7fef-4bb0-b26b-26f29ed212ba" />


**Material & Weight Optimization:** Applied recessed geometry in non-critical structural areas of the brain housing to minimize filament consumption.

**Anti-Tipping Optimization:** Designed the arm base with top surface recesses and dense bottom infill to lower the overall Center of Gravity (CG) and prevent tip-over during rapid movements. Also added attachments points for legs in case of any tipping.

### 📐 Static Torque Analysis & Link Sizing

<img width="1008" height="744" alt="image" src="https://github.com/user-attachments/assets/59528961-f6fb-4f9c-8739-65d6603c0b87" />


- Sized arm link lengths around the strict holding torque limits of the shoulder servo (reported **2.2 kg/cm stall torque**).
- Created a free-body diagram assuming link material density and cross-sectional areas, applying a 1.5× safety factor to servo self-weight alongside a **30g point-mass payload** at the end effector.

### 🎛️ Control & Teleoperation
The brain is designed to handle three control structures:
-  (🟢Current): Wireless teleoperation via command packets sent over Bluetooth from a custom mobile app built with MIT App Inventor.
-  (🟡In Development): Trigonometric / Vector-based Inverse Kinematics (IK) solver for direct (X, Y, Z) Cartesian positioning.
-   (🟡In Development): Waldo-Style Master Controller for direct physical teleoperation and motion tracking.






