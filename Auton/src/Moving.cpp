#include "vex.h"

void Move(int Velocity, double Time, vex::directionType dir) {
  FrontL_DT.setVelocity(Velocity, percent);
  FrontR_DT.setVelocity(Velocity, percent);
  BackL_DT.setVelocity(Velocity, percent);
  BackR_DT.setVelocity(Velocity, percent);
  FrontL_DT.spin(dir);
  FrontR_DT.spin(dir);
  BackL_DT.spin(dir);
  BackR_DT.spin(dir);
  wait(Time, seconds);
  FrontL_DT.stop();
  FrontR_DT.stop();
  BackL_DT.stop();
  BackR_DT.stop();
  wait(0.1, seconds);
  }

/*** 
This function moves the robot forward or reverse based on the provided number of degree rotations

  * @param numberOfDegrees (numberOfDegrees is the amount of degrees that the robot moves forward or reverse)
  * @param dir (dir is the direction that the robot moves- forward or reverse)
  
*/
void MoveStraight(int numberOfDegrees, vex::directionType dir) {

  FrontL_DT.spinFor(dir, numberOfDegrees, degrees, false);
  FrontR_DT.spinFor(dir, numberOfDegrees, degrees, false);
  BackL_DT.spinFor(dir, numberOfDegrees, degrees, false);
  BackR_DT.spinFor(dir, numberOfDegrees, degrees);
 
}