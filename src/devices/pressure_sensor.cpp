
#include <Wire.h>
#include <MS5837.h>

#include "devices.h"
#include "../ROS/ros_deps.h"


// Macro declarations

#define METERS_TO_FEET 3.3  // Conversion from meters to feet


// Global declarations

static MS5837 pressure_sensor;  // Instance of the pressure sensor
static std_msgs::Float32* depth;  // Depth message for publishing
ros::Publisher current_depth_pub("depth_current", depth);  // Publisher object for the depth topic


// Function declarations 

// Function to initialize pressure sensors
void initializePressureSensor(void)
{
    // Initialize wire for the pressure sensor
    Wire.begin();

    // Display error message as long as the pressure sensor is not initializing
    while(!pressure_sensor.init())
        nh.logerror("Pressure sensor cannot initialize.");

    // pressure_sensor.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
}

// This functions publishes the current depth value to the "depth_current" topic
void publishCurrentDepth(void)
{
    pressure_sensor.read();  // Read current pressure value
    depth->data = pressure_sensor.depth()*METERS_TO_FEET;  // Extract the depth from the stored pressure value in feet
    current_depth_pub.publish(depth);
}

