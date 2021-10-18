#include "main.h"

Base::Base() {

}

void Base::drive() {
  int Y = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
  int X = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

  FR = Y - X;
  BR = Y - X;
  FL = Y + X;
  BL = Y + X;

}
