#include "main.h"

vector<int> motor_voltages;

Recorder::Recorder(void) {
  FILE*file = fopen("/usd/motor_voltages.txt", "r");

  char buff[1000];
  string s = "";

  while (fgets(buff, 1000, file) != NULL) { //750 for 15 seconds, 3000 for 1 minut
      string a = buff;
      s = s + a;
  }

  fclose(file);

  vector<string> motor_string;

  istringstream ss (s);
  string voltage;

  while(ss>>voltage) {
      motor_string.push_back(voltage);
  }

  for (int i = 0; i<motor_string.size(); i++) {
    motor_voltages.push_back(stoi(motor_string[i]));
  }
}

void performAutonomous() {
  for(int i = 0; i<motor_voltages.size()-8; i=i+8) {
		FR.move_voltage(motor_voltages[i]);
		BR.move_voltage(motor_voltages[i + 1]);
		FL.move_voltage(motor_voltages[i + 2]);
		BL.move_voltage(motor_voltages[i + 3]);
		RollerTop.move_voltage(motor_voltages[i + 4]);
		RollerBot.move_voltage(motor_voltages[i + 5]);
		IntakeR.move_voltage(motor_voltages[i + 6]);
		IntakeL.move_voltage(motor_voltages[i + 7]);
		pros::delay(1);
	}
}

void Recorder::write () {
  FILE*file = fopen("/usd/motor_voltages.txt", "w");

  for(int i = 0; i<motor_voltages.size() - 8; i=i+8) {
    string a = to_string(motor_voltages[i]) + " " +
    to_string(motor_voltages[i + 1]) + " " +
    to_string(motor_voltages[i + 2]) + " " +
    to_string(motor_voltages[i + 3]) + " " +
    to_string(motor_voltages[i + 4]) + " " +
    to_string(motor_voltages[i + 5]) + " " +
    to_string(motor_voltages[i + 6]) + " " +
    to_string(motor_voltages[i + 7]) + " ";

    fputs(a.c_str(), file);
  }

  fclose(file);
}

void Recorder::read() {
  for(int i = 0; i<motor_voltages.size()-8; i=i+8) {
    FR.move_voltage(motor_voltages[i]);
    BR.move_voltage(motor_voltages[i + 1]);
    FL.move_voltage(motor_voltages[i + 2]);
    BL.move_voltage(motor_voltages[i + 3]);
    RollerTop.move_voltage(motor_voltages[i + 4]);
    RollerBot.move_voltage(motor_voltages[i + 5]);
    IntakeR.move_voltage(motor_voltages[i + 6]);
    IntakeL.move_voltage(motor_voltages[i + 7]);
    pros::delay(1);
  }
}

void Recorder::record() {
  int timeStamp = pros::millis() + 15000;
  while (pros::millis() < timeStamp){
      motor_voltages.push_back(FR.get_voltage());
      motor_voltages.push_back(BR.get_voltage());
      motor_voltages.push_back(FL.get_voltage());
      motor_voltages.push_back(BL.get_voltage());
      motor_voltages.push_back(RollerTop.get_voltage());
      motor_voltages.push_back(RollerBot.get_voltage());
      motor_voltages.push_back(IntakeR.get_voltage());
      motor_voltages.push_back(IntakeL.get_voltage());

      pros::delay(1);
  }
  write();
}
