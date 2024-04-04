#pragma once
#include "Sensor.h"
#include <string>
using namespace std;


class SensorFactory {
public:
	static Sensor* createSensor(string);
};