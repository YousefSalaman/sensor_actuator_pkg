

#include <Servo.h>

#include "devices.h"


#define CAMERA_SERVO_PIN 10  // Pin for the camera servo (TODO: Assign the actual pin later)
#define CAMERA_SERVO_NEUTRAL_ANGLE 90  // The neutral position for the camera servo (TODO: Assign the real neutral angle)


static Servo camera_servo;
static bool init_camera_servo = false;
ros::Subscriber<std_msgs::UInt16> camera_angle_sub("camera_angle", setCameraAngle);


// Set the camera's servo to a specified angle
void setCameraAngle(const std_msgs::UInt16& camera_angle){

    if(init_camera_servo)
        camera_servo.write(camera_angle.data);
}

// Initialize the camera's servo
void initializeCameraServo(void){

    init_camera_servo = true;
    camera_servo.attach(CAMERA_SERVO_PIN);
    camera_servo.write(CAMERA_SERVO_NEUTRAL_ANGLE);  // Set the camera servo to its neutral angle
}
