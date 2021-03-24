
#include <Arduino.h>

#include "ROS/ros_deps.h"
#include "devices/devices.h"

void setup() 
{
  initializeGripper();
  initROSDependencies();
  initializeThrusters();
  initializeCameraServo();
  initializePressureSensor();
}

void loop() 
{
  publishCurrentDepth();
  runROSDependencies();
}
