#include "vex.h"

void Lift(int Velocity, double Time, vex::directionType dir) {
  Forklift_L.setVelocity(Velocity, percent);
  Forklift_L.spin(dir);
  wait(Time, seconds);
  Forklift_L.stop();
  wait(1, seconds);
}