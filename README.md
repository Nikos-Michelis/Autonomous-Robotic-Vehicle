# Autonomous Robotic Vehicle

Wall-E was designed to autonomously detect and avoid obstacles using a ultrasonic sensor and IR infrared obstacle sensors.

<p align="center">
  <img src="https://user-images.githubusercontent.com/92666389/194114378-d4b1af7c-6795-4833-9fe8-e5280fbf1c1a.png" alt="FrontWall-e" />
</p>

## Circuit

![wall-eCircuite](https://github.com/user-attachments/assets/88bb4e0c-38ca-4388-a66e-6b627ed32d7b)

# How it works
## Ultrasonic sensor
The ultrasonic sensor is used to detect obstacles at longer distances. It works by emitting high-frequency sound waves and measuring the time it takes for the echo to return after hitting an object. This allows the robot to calculate the distance to obstacles in its path with good accuracy. Using ultrasonic sensing helps the vehicle plan its movements early and avoid collisions with objects that are several centimeters or even meters away.

<p align="center">
  <img src="https://github.com/user-attachments/assets/4d545f01-d28c-44c4-95ef-cd459f705697" alt="Ultrasonic-Sensor" />
</p>


## IR infrared obstacle sensors
For nearby obstacles, the vehicle relies on infrared (IR) sensors. These sensors emit infrared light and detect reflections from nearby surfaces, making them well-suited for short-range detection. IR sensors are ideal for quickly sensing walls, small objects, or sudden changes in terrain, such as the edge of a table. Their fast response time helps the vehicle make quick decisions in tight spaces where precision is critical.

![Untitled-3](https://github.com/user-attachments/assets/7ab88c72-7b1b-4a54-ab81-a4e55503dac8)
