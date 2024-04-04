#pragma once
#include "Sensor.h"
#include "SensorFactory.h"
#include <vector>

using namespace std;

class AerospaceControlSystem {
private:
	SensorFactory factory;
	vector<Sensor*> sensors;
public:
	void addSensor(string);
	void monitorAndAdjust();
};