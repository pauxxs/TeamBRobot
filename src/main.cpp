#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "vex.h"

#include "init.hpp"

using namespace vex;

competition Competition;

namespace helperfunc {
  void launch_spin() {
    launcher.spin(forward);
  }

  void launch_stop() {
    launcher.stop();
  }

  void wiggle() {
    for (int i = 0; i < 5; i++) {
      Drivetrain.turnFor(10, degrees);
      Drivetrain.turnFor(-10, degrees);
    }
  }
}

void pre_auton() {

}

void topleftAuto() {
  Drivetrain.setDriveVelocity(150, percent);
  Drivetrain.driveFor(43, inches);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(-20, inches);
  wait(.5, seconds);
  Drivetrain.turnFor(right, -60, degrees);
  Drivetrain.driveFor(-10, inches);
  wait(.5, seconds);
  Drivetrain.driveFor(13, inches);
  wait(.5, seconds);
  Drivetrain.turnFor(-50, degrees);
  Drivetrain.driveFor(27, inches);
  Drivetrain.turnFor(10, degrees);
  Drivetrain.driveFor(forward, 40, inches);
}

void toprightAuto() {
  Drivetrain.setDriveVelocity(150, percent);
  Drivetrain.driveFor(43, inches);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.driveFor(-20, inches);
  wait(.5, seconds);
  Drivetrain.turnFor(right, 60, degrees);
  Drivetrain.driveFor(-10, inches);
  wait(.5, seconds);
  Drivetrain.driveFor(13, inches);
  wait(.5, seconds);
  Drivetrain.turnFor(50, degrees);
  Drivetrain.driveFor(27, inches);
  Drivetrain.turnFor(-10, degrees);
  Drivetrain.driveFor(forward, 40, inches);

}

void usercontrol() {
  Drivetrain.setTurnVelocity(25, percent);
  launcher.setVelocity(50, percent);

  Controller1.ButtonUp.pressed(helperfunc::launch_spin);
  Controller1.ButtonDown.pressed(helperfunc::launch_stop);
  
  Controller1.ButtonA.pressed(helperfunc::wiggle);

  while (1) {
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(topleftAuto);
  // Competition.autonomous(toprightAuto);

  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
