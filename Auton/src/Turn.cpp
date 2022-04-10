#include "vex.h"

void Turn(int Velocity, double Time, vex::turnType dir) {

  FrontL_DT.setVelocity(Velocity, percent);
  FrontR_DT.setVelocity(Velocity, percent);
  BackL_DT.setVelocity(Velocity, percent);
  BackR_DT.setVelocity(Velocity, percent);

  if (dir == right) {
    FrontL_DT.spin(forward);
    BackL_DT.spin(forward);
    FrontR_DT.spin(reverse);
    BackR_DT.spin(reverse);
  }
    else if (dir == left) {
    FrontL_DT.spin(reverse);
    BackL_DT.spin(reverse);
    FrontR_DT.spin(forward);
    BackR_DT.spin(forward);
  }
  wait(Time, seconds);
  FrontL_DT.stop();
  FrontR_DT.stop();
  BackL_DT.stop();
  BackR_DT.stop();
  wait(1, seconds);
}

/*
This function turns the robot by the provided amount of degrees in the provided direction
*/
void TurnUsingGyro(int numOfDegrees, vex::turnType dir) {
  Inertial.setHeading(0, degrees);

  if (dir == right) {
    Brain.Screen.print(Inertial.heading(degrees));
    FrontL_DT.spinFor(forward, 2000, degrees, false);
    FrontR_DT.spinFor(reverse, 2000, degrees, false);
    BackL_DT.spinFor(forward, 2000, degrees, false);
    BackR_DT.spinFor(reverse, 2000, degrees, false);
  
    while  (Inertial.heading(degrees) <= numOfDegrees) {
      wait(0.05, seconds);
    }

    Brain.Screen.print(Inertial.heading(degrees));
    FrontL_DT.stop();
    FrontR_DT.stop();
    BackL_DT.stop();
    BackR_DT.stop();

  }
  else if (dir == left) {
    // Turn left by spinning the RightMotor forward and the LeftMotor reverse.
    Brain.Screen.print(Inertial.heading(degrees));
    Brain.Screen.print("***");
    FrontL_DT.spinFor(reverse, 2000, degrees, false);
    FrontR_DT.spinFor(forward, 2000, degrees, false);
    BackL_DT.spinFor(reverse, 2000, degrees, false);
    BackR_DT.spinFor(forward, 2000, degrees, false);

    wait(0.5, seconds);

    // Wait until the Gyro's heading is greater than x degrees.
     while  (Inertial.heading(degrees) >= 360 - numOfDegrees) {
      wait(0.05, seconds);
      
    }

    Brain.Screen.print(Inertial.heading(degrees));
    Brain.Screen.print("***");

    // Stop both motors.
    FrontL_DT.stop();
    FrontR_DT.stop();
    BackL_DT.stop();
    BackR_DT.stop();
  }
}