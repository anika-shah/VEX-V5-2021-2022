//FINAL 1 minute skills autonomous code------- 130 points

#include "vex.h"
#include "Moving.h"
#include "Turn.h"
#include "FrontLifting.h"
#include "Lifting.h"

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

  FrontL_DT.setVelocity(85, percent);
  FrontR_DT.setVelocity(85, percent);
  BackL_DT.setVelocity(85, percent);
  BackR_DT.setVelocity(85, percent);
  Forklift_L.setVelocity(100, percent);
  BackForklift_L.setVelocity(100,percent);
  BackForklift_R.setVelocity(100, percent);
  Forklift_L.setMaxTorque(100, percent);
  BackForklift_L.setMaxTorque(100, percent);
  BackForklift_R.setMaxTorque(100, percent);
  Forklift_L.stop(brakeType::hold);
  Forklift_Hook.stop(brakeType::hold);

  
  //Step 1: Go forward to push the blue goal into the other side
  MoveStraight(2090, forward);

  //Step 1: Come back
  MoveStraight(1442, reverse);

  //Turn left 90 degrees
  //TurnUsingGyro(84, left);
  TurnToTarget(278);
  
  //Go forward
  MoveStraight(625, forward);
  //---------------------------------------------------------------------------------------------------------------------------------------------
  //Step 2: Turn right 90 degrees the face the first yellow goal
  TurnToTarget(357);
  
  //Step 2: Go forward 1700 degrees forward to push the yellow goal to the other side
  MoveStraight(1407, forward);
  
  //Step 2: Come back
  MoveStraight(1237, reverse);
  
  //Turn left
  TurnToTarget(278);
  
  //Go forward
  MoveStraight(947, forward);
  
  //Turn right 90 degrees the face the second yellow goal
  TurnToTarget(357);
//------------------------------------------------------------------------------------------------------------------------------------------------
  
  //Step 3: Go forward 1700 degrees forward to push the second yellow goal to the other side
  MoveStraight(1690, forward);

  //Step 3: Come back
  MoveStraight(140, reverse);
  
  //Turn left 90 degrees
  TurnToTarget(278);
  
  //Go forward to align with third yellow goal
  MoveStraight(1010, forward);
  
  //Turn left 90 degrees
  TurnToTarget(185);
  
  //Go forward to push the third yellow goal to the other side
  MoveStraight(1130, forward);

  //Go backward
  MoveStraight(1520, reverse);

  //Turn to face red goal
  TurnToTarget(265);
  //----------------------------------------------------------------------------------------------------------------------------------------------
  //Step 4: Move backward to give space for the forklift
  
  //Decrease the velocity to 60 to lightly bump the wall
  FrontL_DT.setVelocity(60, percent);
  FrontR_DT.setVelocity(60, percent);
  BackL_DT.setVelocity(60, percent);
  BackR_DT.setVelocity(60, percent);
  Forklift_L.setVelocity(50, percent);
  BackForklift_L.setVelocity(50,percent);
  BackForklift_R.setVelocity(50, percent);
  Forklift_L.setMaxTorque(50, percent);
  BackForklift_L.setMaxTorque(50, percent);
  BackForklift_R.setMaxTorque(50, percent);

  //Step 4: Move backward to give space for the forklift
  MoveStraight(50, reverse);
  //---------------------------------------------------------------------------------------------------------------------------------------------
  //Step 5: Lower the forklift to pick up the red goal
  FrontLift(100, 1.4, reverse);

  //Step 5: Move forward to get under the red goal
  MoveStraight(500, forward);

  //Step 5: Spin the hook to clamp the red goal
  Forklift_Hook.spinFor(forward, 100, degrees);

  //Step 5: Move the forklift up to pick up the red goal
  FrontLift(70, 1.5, forward);

  //Step 5: Move forward to move closer to the wall
  MoveStraight(90, forward);

  //Step 5: Turn left 90 degrees to be parallel to the wall
  TurnToTarget(182);
  //-----------------------------------------------------------------------------------------------------------------------------------------------
  //Step 6: Move forward to move the robot to the other side of the field
  MoveStraight(1700, forward);

  //Step 6: Turn left 90 degrees to drop the red goal 
  TurnToTarget(90);

  //Step 6: Move forward to drop the red goal
  MoveStraight(500, forward);

  //Step 6: Lower the forklift to drop the red goal
  FrontLift(100, 1.4, reverse);

  //Step 6: Spin the hook to unlatch from the red goal
  Forklift_Hook.spinFor(reverse, 100, degrees);

  //Step 6: Move back from the red goal
  MoveStraight(350, reverse);

  //Step 6: Move the forklift up to it's original position
  FrontLift(100, 1.4, forward);

  //Step 6: Turn right 90 degrees to be parallel to the wall again
  TurnToTarget(179);
  //---------------------------------------------------------------------------------------------------------------------------------------------
  //Step 7: Go forward until the robot touches the far wall
  MoveStraight(945, forward);
 
  //Step 7: Move back from the wall
  MoveStraight(20, reverse);
  
  //Step 7: Turn left 90 degrees to face the red ramp
  TurnToTarget(90);

  //Step 7: Align the robot to get up the red ramp
  TurnToTarget(115);
  MoveStraight(65, forward);
  TurnToTarget(100);
  TurnToTarget(115);
  MoveStraight(65, forward);
  TurnToTarget(100);
  //---------------------------------------------------------------------------------------------------------------------------------------------
  //Set the velocity to 100 percent
  FrontL_DT.setVelocity(100, percent);
  FrontR_DT.setVelocity(100, percent);
  BackL_DT.setVelocity(100, percent);
  BackR_DT.setVelocity(100, percent);
  Forklift_L.setVelocity(60, percent);
  BackForklift_L.setVelocity(50,percent);
  BackForklift_R.setVelocity(50, percent);
  Forklift_L.setMaxTorque(50, percent);
  BackForklift_L.setMaxTorque(100, percent);
  BackForklift_R.setMaxTorque(100, percent);

  //Step 8: Use the back forklift to slightly pick up the blue goal
  FrontLift(100, 1.5, reverse);
  MoveStraight(620, forward);
  Forklift_Hook.spinFor(forward, 90, degrees);
  FrontLift(70, 1, forward);

  //Step 8: Climb up the red ramp
  MoveStraight(1000, forward);

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

