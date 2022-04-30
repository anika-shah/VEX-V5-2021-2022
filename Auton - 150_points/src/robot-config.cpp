#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontR_DT = motor(PORT4, ratio18_1, true);
motor BackR_DT = motor(PORT20, ratio18_1, true);
motor BackL_DT = motor(PORT14, ratio18_1, false);
motor FrontL_DT = motor(PORT8, ratio18_1, false);
motor Forklift_L = motor(PORT2, ratio36_1, false);
controller Controller1 = controller(primary);
inertial Inertial = inertial(PORT21);
motor Forklift_Hook = motor(PORT5, ratio18_1, false);
motor BackForklift_L = motor(PORT3, ratio18_1, true);
motor BackForklift_R = motor(PORT10, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}