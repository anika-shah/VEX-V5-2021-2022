#include "vex.h"

void FrontLift(int Velocity, double Time, vex::directionType dir) {
  BackForklift_L.setVelocity(Velocity, percent);
  BackForklift_R.setVelocity(Velocity, percent);
  BackForklift_L.spin(dir);
  BackForklift_R.spin(dir);
  wait(Time, seconds);
  BackForklift_L.stop();
  BackForklift_R.stop();
  wait(0.1, seconds);
}