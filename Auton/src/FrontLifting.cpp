#include "vex.h"

void FrontLift(int Velocity, int numberOfDegrees, vex::directionType dir) {
  BackForklift_L.setVelocity(Velocity, percent);
  BackForklift_R.setVelocity(Velocity, percent);
  BackForklift_L.spinFor(dir, numberOfDegrees, degrees, true);
  BackForklift_R.spinFor(dir, numberOfDegrees, degrees);
  wait(0.5, seconds);
  BackForklift_L.stop();
  BackForklift_R.stop();
  wait(0.5, seconds);
}