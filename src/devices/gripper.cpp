
#include <Servo.h>

#include "devices.h"


// Gripper PWM signals
// Neutral signal is 1500
// Opening signal range (>1530-1900)
// Closing signal range (<1470-1100)

// TODO: Check if we can just send the PWM value from another part of
// the code.
// TODO: Check how much the PWM value affects the gripper
#define GRIPPER_PIN 12  // Pin for the gripper (#TODO: Assign a pin for the gripper)
#define GRIPPER_OPEN 1899  // PWM value for the gripper to be almost opened
#define GRIPPER_CLOSED 1099  // PWM value for the gripper to be almost closed
#define GRIPPER_NEUTRAL 1500  // PWM value for the gripper to be neutral


static Servo gripper_motor;
static bool init_gripper = false;
ros::Subscriber<std_msgs::UInt8> gripper_mode_sub("gripper_mode", manipulateGripper);


void manipulateGripper(const std_msgs::UInt8& gripper_mode){

    if(init_gripper){
        uint8_t mode = gripper_mode.data;  // Get the data from the message

        int PWM_value = GRIPPER_NEUTRAL;  // As default, set the gripper to its neutral state
        if(mode == 0)
            PWM_value = GRIPPER_OPEN;
        else if (mode == 1)
            PWM_value = GRIPPER_CLOSED;
        gripper_motor.writeMicroseconds(PWM_value);
    }
}


void initializeGripper(void){

    init_gripper = true;
    gripper_motor.attach(GRIPPER_PIN);
    gripper_motor.write(GRIPPER_NEUTRAL);  // Start the gripper in its neutral state
    // Serial.begin(9600);  // TODO: Ask about this and why software was going to send stuff here
}