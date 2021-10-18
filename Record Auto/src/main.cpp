#include "main.h"

// Motor Definitions
pros::Motor FR(frPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor BR(brPort, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor FL(flPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor BL(blPort, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);

pros::Motor IntakeR(intakeRPort, E_MOTOR_GEARSET_06, true, E_MOTOR_ENCODER_DEGREES);
pros::Motor IntakeL(intakeLPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor RollerTop(rollerTopPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);
pros::Motor RollerBot(rollerBotPort, E_MOTOR_GEARSET_06, false, E_MOTOR_ENCODER_DEGREES);

pros::Controller master(E_CONTROLLER_MASTER);

Recorder recorder;

void autonomous() {
  recorder.performAutonomous();
}

void initialize() {
  FR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	BR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	FL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	BL.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	IntakeR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	IntakeL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	RollerTop.set_brake_mode(E_MOTOR_BRAKE_HOLD);
	RollerBot.set_brake_mode(E_MOTOR_BRAKE_HOLD);

	pros::lcd::initialize();

  Task record(recorderFunction, (void*)"PROS", //Initialize multitask function
    TASK_PRIORITY_DEFAULT,
    TASK_STACK_DEPTH_DEFAULT,
    "Records and plays autonomouses"
  );
}

void opcontrol() {

}
