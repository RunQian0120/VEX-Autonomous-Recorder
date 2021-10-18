#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES
#define PROS_USE_LITERALS

#include "api.h"
#include "classes.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <iterator>

using namespace pros;
using namespace std;

//GLOBAL MOTOR DEFINTIONS
extern pros::Motor BR;
extern pros::Motor BL;
extern pros::Motor FR;
extern pros::Motor FL;
extern pros::Motor RollerBot;
extern pros::Motor RollerTop;
extern pros::Motor IntakeR;
extern pros::Motor IntakeL;

//MOTOR PORT DEFINITIONS
#define brPort 8
#define blPort 20
#define frPort 4
#define flPort 2
#define intakeRPort 3
#define intakeLPort 1
#define rollerBotPort 10
#define rollerTopPort 9

extern pros::Controller master;

extern Recorder recorder;



#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
