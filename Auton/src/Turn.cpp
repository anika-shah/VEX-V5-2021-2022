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

  FrontL_DT.setVelocity(15, percent);
  FrontR_DT.setVelocity(15, percent);
  BackL_DT.setVelocity(15, percent);
  BackR_DT.setVelocity(15, percent);

  Brain.Screen.print("Before:");
  Brain.Screen.print(Inertial.heading(degrees));

  if (dir == right) {
    FrontL_DT.spinFor(forward, 2000, degrees, false);
    FrontR_DT.spinFor(reverse, 2000, degrees, false);
    BackL_DT.spinFor(forward, 2000, degrees, false);
    BackR_DT.spinFor(reverse, 2000, degrees, false);

    float target = Inertial.heading(degrees) + numOfDegrees;
    if(target >= 360)
    {
      target = target-360;
    }
    Brain.Screen.print("Target:");
    Brain.Screen.print(target);

    while (true)
    {
      wait(0.01, seconds);
      if (Inertial.heading(degrees) > target-1 && Inertial.heading(degrees) < target+1)
      {
          break;
      }
    }

    Brain.Screen.print("After:");
    Brain.Screen.print(Inertial.heading(degrees));
  }
  else if (dir == left) {
    FrontL_DT.spinFor(reverse, 2000, degrees, false);
    FrontR_DT.spinFor(forward, 2000, degrees, false);
    BackL_DT.spinFor(reverse, 2000, degrees, false);
    BackR_DT.spinFor(forward, 2000, degrees, false);

    wait(0.2, seconds);

    //Setting the target
    float target = Inertial.heading(degrees) - numOfDegrees;
    if (target < 0)
    {
      target = target + 360;
    }
    Brain.Screen.print("Target:");
    Brain.Screen.print(target);

    while (true)
    {
      wait(0.01, seconds);
      if (Inertial.heading(degrees) > target-1 && Inertial.heading(degrees) < target+1)
      {
          break;
      }
    }
    Brain.Screen.print("After:");
    Brain.Screen.print(Inertial.heading(degrees));
  }

  FrontL_DT.stop();
  FrontR_DT.stop();
  BackL_DT.stop();
  BackR_DT.stop();

  FrontL_DT.setVelocity(50, percent);
  FrontR_DT.setVelocity(50, percent);
  BackL_DT.setVelocity(50, percent);
  BackR_DT.setVelocity(50, percent);
}