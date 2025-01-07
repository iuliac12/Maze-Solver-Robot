# Maze Solver Robot

<details>
  <summary> <h2>  Introduction </h2> </summary>
  
##
  
  This project brings the concept of autonomous navigation into the real world. Building a maze solver robot that can detect and navigate through mazes using sensors and algorithms — all powered by an Arduino microcontroller. 
  
This project combines hardware assembly and software development, making it a hands-on learning experience for enthusiasts interested in robotics, microcontrollers, and problem-solving. By leveraging sensors, algorithms, and microcontroller programming, a maze solver robot can effectively detect and avoid obstacles, map its environment, and reach its destination efficiently.


##
</details>


<details>
  <summary> <h2> General Description </h2> </summary>

  ##
  
The maze solver robot consists of several interconnected modules: a power supply to energize the system, sensors for obstacle detection, a microcontroller to process data and implement the maze-solving algorithm, a motor driver to control wheel motion, and actuators to enable movement. These modules work together to ensure the robot can detect walls, decide the optimal direction, and navigate through the maze autonomously. The ultrasonic sensors continuously relay distance measurements to the microcontroller, which interprets the data, computes the next move, and sends corresponding commands to the motors.

  #
  

##
</details>


<details>
  <summary> <h2> Hardware Design </h2> </summary>

# Components

## 1. Arduino Uno

Function: The Arduino Uno is the microcontroller that acts as the brain of the robot. It processes data received from the ultrasonic sensors and executes the maze-solving algorithm. It also controls the motor driver and sends commands to the motors based on the logic of the program. The Arduino is responsible for interpreting sensor data and deciding the next move of the robot.

## 2. HC-SR04 Ultrasonic Sensors (3)

Function: These sensors are used to detect obstacles and measure the distance between the robot and objects (like walls in the maze). The sensor sends out sound waves and measures the time it takes for the waves to bounce back from the nearest obstacle. Based on this information, the Arduino calculates the distance and decides whether the robot should move forward, turn, or stop.

## 3. L298N Motor Driver Module

Function: The L298N motor driver is used to control the direction and speed of the robot's DC motors. It receives commands from the Arduino and drives the motors accordingly. The L298N allows the motors to rotate in both directions (forward and backward), enabling the robot to move around the maze and navigate through it. It also controls the speed by adjusting the voltage sent to the motors.

## 4. DC Motors with Wheels (4)
   
Function: These are the actuators that physically move the robot. The four DC motors are connected to the wheels and are controlled by the L298N motor driver. The motors enable the robot to move forward, backward, and turn by adjusting their rotation speed and direction based on commands from the Arduino.

## 5. Rechargeable Battery Pack
Function: The rechargeable battery pack provides power to the entire robot system, including the Arduino, sensors, motor driver, and motors. It stores electrical energy and ensures the robot operates independently, without being plugged into an external power source. The battery is essential for the mobility and functionality of the robot.

## 6. Power Switch
Function: The power switch controls the power flow to the robot. It allows the user to turn the robot on and off, ensuring that power is only supplied when needed. The switch is typically connected between the battery and the rest of the components.

## 7. Jumper Wires and Connectors
Function: Jumper wires and connectors are used to make electrical connections between different components in the robot. They link the Arduino to the ultrasonic sensors, motor driver, and other parts of the system, enabling the flow of signals and power.

## 8. Robot Chassis
Function: The robot chassis is the physical frame that holds and supports all the components of the robot. It provides a structure for mounting the Arduino, motors, sensors, battery, and other parts. The chassis gives the robot its shape and ensures that the components are securely in place, allowing the robot to move efficiently through the maze.

  ##
  
   ### 1. List of components: 
   
| Component                   | Quantity | Description                                   | Source         |
|-----------------------------|:--------:|-----------------------------------------------|---------------|
| Arduino Uno                 |    1     | Microcontroller for managing system state     | Kit            | 
| HC-SR04 Ultrasonic Sensor   |    3     | Detect obstacles and measure distances        | Kit            |
| L298N Motor Driver Module   |    1     | Controls the speed and direction of motors    | Kit            |
| DC Motors with Wheels       |    4     | Enables robot movement                        | [Link](https://www.emag.ro/sasiu-dublu-masina-inteligenta-cu-4-roti-3874784221220/pd/DWKRZKYBM/) | 
| Rechargeable Battery Pack   |    1     | Powers the entire system                      | [Link](https://www.emag.ro/sasiu-dublu-masina-inteligenta-cu-4-roti-3874784221220/pd/DWKRZKYBM/) |
| Power Switch                |    1     | Controls power to the robot                   | [Link](https://www.emag.ro/sasiu-dublu-masina-inteligenta-cu-4-roti-3874784221220/pd/DWKRZKYBM/) |
| Jumper Wires and Connectors |  various | Connects components in the circuit            | Kit            |
| Robot Chassis               |    1     | Physical structure housing all components     | [Link](https://www.emag.ro/sasiu-dublu-masina-inteligenta-cu-4-roti-3874784221220/pd/DWKRZKYBM/)  |


### **Block Diagram**

![image](https://github.com/user-attachments/assets/2e87b6c4-b17a-406f-83e8-e52c4b884eea)

  ### 2. Circuit Diagram
  ![image](https://github.com/user-attachments/assets/266be15e-0c12-4d4d-899f-eca66bcd1c98)


  ### 3. Results
<img src="https://github.com/user-attachments/assets/ab55e865-ea8e-4406-b836-9a83a6bd4869" width="400" />
<img src="https://github.com/user-attachments/assets/a05b789e-75d8-49ff-82d6-83a663061e0d" width="400" />
<img src="https://github.com/user-attachments/assets/acf02a38-8f6f-403a-bedc-6b736136307b" width="400" />

  
##
</details>

<details>
  <summary> <h2> Software Design </h2> </summary>

  ##
  ### Development enviroment:
  
  I will use the PlatformIO IDE extension within Visual Studio Code.

  
   TBD
  
##
</details>

<details>
  <summary> <h2> Results </h2> </summary>

  ##
   TBD
  
##
</details>

<details>
  <summary> <h2> Conclusions </h2> </summary>

  ##
   TBD
  
##
</details>

<details>
  <summary> <h2> Resources </h2> </summary>
  
  ##

   TBD
  
##
</details>
