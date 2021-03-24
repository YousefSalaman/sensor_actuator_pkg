
#ifndef DEVICES_H

#define DEVICES_H

#include <ros.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Float32.h>

// TODO: Could change the message structure, so each msg class doesn't use
// a header to define it
#include "msg/MotorValues.h"

// SG90 Servo (for camera)

void initializeCameraServo(void);
void setCameraAngle(const std_msgs::UInt16&);
extern ros::Subscriber<std_msgs::UInt16> camera_angle_sub;

// Newton Subsea Gripper

void initializeGripper(void);
void manipulateGripper(const std_msgs::UInt8&);
extern ros::Subscriber<std_msgs::UInt8> gripper_mode_sub;

// T100 thrusters declarations

void initializeThrusters(void);
void setThrusterSpeeds(const MotorValues);
extern ros::Subscriber<MotorValues> mov_motor_sub;

// MS5837 pressure sensor declarations

void publishCurrentDepth(void);
void initializePressureSensor(void);
extern ros::Publisher current_depth_pub;

#endif