
#include "ros_deps.h"
#include "devices/devices.h"

// Global declarations

ros::NodeHandle nh;


void initROSDependencies(void)
{
    nh.initNode();  // Initialize ROS node

    // Declare publishers
    nh.advertise(current_depth_pub);

    // Declare subscribers
    nh.subscribe(mov_motor_sub);
    nh.subscribe(camera_angle_sub);
    nh.subscribe(gripper_mode_sub);
}


void runROSDependencies(void)
{
    nh.spinOnce();
}

