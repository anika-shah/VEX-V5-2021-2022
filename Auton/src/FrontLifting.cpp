#include "vex.h"

/*void FLift() {

  BackForklift_L.setVelocity(Velocity, percent);
  Forklift_L.spin(dir);
  wait(Time, seconds);
  Forklift_L.stop();
  wait(1, seconds);


}*/

void FrontLift(int Velocity, int numberOfDegrees, vex::directionType dir) {
  BackForklift_L.setVelocity(Velocity, percent);
  BackForklift_R.setVelocity(Velocity, percent);
  BackForklift_L.spinFor(dir, numberOfDegrees, degrees);
  BackForklift_R.spinFor(dir, numberOfDegrees, degrees);
  wait(0.5, seconds);
  BackForklift_L.stop();
  BackForklift_R.stop();
  wait(0.5, seconds);
}

