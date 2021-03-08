
#ifndef DEVICES_H

#define DEVICES_H

#include <ros.h>
#include <std_msgs/Float32.h>

#include "msg/MotorValues.h"

// T100 thrusters declarations

void initializeThrusters(void);
void setThrusterSpeeds(const MotorValues);
extern ros::Subscriber<MotorValues> mov_motor_sub;

// MS5837 pressure sensor declarations

void publishCurrentDepth(void);
void initializePressureSensor(void);
extern ros::Publisher current_depth_pub;

#endif