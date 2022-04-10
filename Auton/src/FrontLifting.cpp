#include "vex.h"

/*void FLift() {

  BackForklift_L.setVelocity(Velocity, percent);
  Forklift_L.spin(dir);
  wait(Time, seconds);
  Forklift_L.stop();
  wait(1, seconds);


}*/

void FLift(int Velocity, double Time, vex::directionType dir) {
  BackForklift_L.setVelocity(Velocity, percent);
  Forklift_L.spin(dir);
  wait(Time, seconds);
  Forklift_L.stop();
  wait(1, seconds);
}

