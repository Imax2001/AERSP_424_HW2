#pragma once
#include "Sensor.h"

class Altitude : public Sensor {
public:
	void gatherData();
	void processData();
};