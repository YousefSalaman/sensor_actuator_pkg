
#include <Arduino.h>

#include "ROS/ros_deps.h"
#include "devices/devices.h"

void setup() 
{
  initROSDependencies();
  initializeThrusters();
  initializePressureSensor();
}

void loop() 
{
  publishCurrentDepth();
  runROSDependencies();
}
