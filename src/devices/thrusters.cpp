

#include <Servo.h>

#include "devices.h"


// Macro and enum declarations

#define MOTOR_NUM 8  // Total number of motors for the actuator
#define PWM_NEUTRAL 1500  // The thruster's output force is 0 lbf at this PWM value

enum MotorPins {MOTOR_1_PIN = 2, MOTOR_2_PIN, MOTOR_3_PIN, MOTOR_4_PIN, MOTOR_5_PIN, MOTOR_6_PIN, MOTOR_7_PIN, MOTOR_8_PIN};


// Global variable declarations

static Servo motors[MOTOR_NUM]; 
static bool init_motors = false;
ros::Subscriber<MotorValues> mov_motor_sub("mov_motor_values", setThrusterSpeeds);  // ROS subscriber for thruster motor PWM values
static MotorPins motor_pins[] = {MOTOR_1_PIN, MOTOR_2_PIN, MOTOR_3_PIN, MOTOR_4_PIN, MOTOR_5_PIN, MOTOR_6_PIN, MOTOR_7_PIN, MOTOR_8_PIN};


// Function declarations

void initializeThrusters(void)
{     
    init_motors = true;
    for (uint8_t i = 0; i < MOTOR_NUM; i++){
        motors[i].attach(motor_pins[i]);
        motors[i].writeMicroseconds(PWM_NEUTRAL);  // This sets the thrusters output force to 0 lbf
    }   
}

// Setter for the thruster motor PWM values
void setThrusterSpeeds(const MotorValues &motor_msg)
{ 
    if(init_motors)
        for (uint8_t i = 0; i < MOTOR_NUM; i++)
            motors[i].writeMicroseconds(motor_msg.motor_values[i]); // This can be done if I send an array instead of individual numbers
}
