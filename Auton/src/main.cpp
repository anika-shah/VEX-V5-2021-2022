/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontR_DT            motor         11              
// BackR_DT             motor         2               
// BackL_DT             motor         10              
// FrontL_DT            motor         20              
// Forklift_L           motor         19              
// Controller1          controller                    
// Inertial             inertial      4               
// Forklift_Hook        motor         13              
// BackForklift_L       motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Moving.h"
#include "Turn.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {

  Brain.Screen.print("Hello 938J");
  // Calibrate the Gyro, and wait for it to finish.
  Inertial.calibrate();
  waitUntil(!Inertial.isCalibrating());

  // Set the Gyro's heading to 0.
  Inertial.setHeading(0, degrees);


  Brain.Screen.print(Inertial.heading(degrees));

  FrontL_DT.setVelocity(50, percent);
  FrontR_DT.setVelocity(50, percent);
  BackL_DT.setVelocity(50, percent);
  BackR_DT.setVelocity(50, percent);
  
  //Step 1: Go forward to push the blue goal into the other side
  MoveStraight(2500, forward);

  //Step 1: Come back
  MoveStraight(1850, reverse);

  //Turn left 90 degrees
  TurnUsingGyro(84, left);
  
  //Go forward
  MoveStraight(625, forward);
  
  //Turn right 90 degrees the face the first yellow goal
  TurnUsingGyro(85, right);
  

  //Step 2: Go forward 1700 degrees forward to push the yellow goal to the other side
  MoveStraight(1700, forward);
  
  //Step 2: Come back
  MoveStraight(1500, reverse);
  
  TurnUsingGyro(82, left);
  
  //Go forward
  MoveStraight(930, forward);
  
  //Turn right 90 degrees the face the first yellow goal
  TurnUsingGyro(83, right);

  
  //Step 3: Go forward 1700 degrees forward to push the yellow goal to the other side
  MoveStraight(1750, forward);

  //Step 3: Come back
  MoveStraight(155, reverse);
  
  //Turn left 90 degrees

  TurnUsingGyro(80, left);

  //Go forward
  MoveStraight(970, forward);
  
  //Turn left 90 degrees
  TurnUsingGyro(83, left);

  //Go forward to push the third yellow goal to the other side
  MoveStraight(1160, forward);

  //Go backward
  MoveStraight(2450, reverse);

  //Turn to face red goal
  TurnUsingGyro(83, right);

  //MoveStraight(1500, forward);
  //wait(1, seconds);
  //TurnUsingGyro(90, left);
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  FrontL_DT.setVelocity(100, percent);
  FrontR_DT.setVelocity(100, percent);
  BackL_DT.setVelocity(100, percent);
  BackR_DT.setVelocity(100, percent);
  Forklift_L.setVelocity(20, percent);
  Forklift_L.setMaxTorque(1000, percent);
  Forklift_L.setStopping(hold);

  //tank drive

  while(true) {
    FrontL_DT.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct); //(Axis3+Axis4)/2
    BackL_DT.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct); //(Axis3+Axis4)/2
    FrontR_DT.spin(directionType::fwd, Controller1.Axis2.value(), velocityUnits::pct); //(Axis3-Axis4)/2
    BackR_DT.spin(directionType::fwd, Controller1.Axis2.value(), velocityUnits::pct); //(Axis3-Axis4)/2

    if (Controller1.ButtonX.pressing()) {
      Forklift_L.spin(forward);
    }
    else if (Controller1.ButtonB.pressing()) {
      Forklift_L.spin(reverse);
    }
    else {
      Forklift_L.stop();
    }
    task::sleep(20);
  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}