#ifndef _CLASSES_HPP_
#define _CLASSES_HPP_

#include "main.h"

class Recorder {
public:
  vector<int> motor_voltages;
  void performAutonomous();
  Recorder();

  void record();
  void read();
private:
  void write();
};

void recorderFunction(void*param);
#endif
