#pragma once
#include "Sensor.h"
#include "SensorFactory.h"

using namespace std;

class AerospaceControlSystem {
private:
	SensorFactory factory;
public:
	void addSensor(Sensor*);
	void monitorAndAdjust();
};