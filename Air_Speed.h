#pragma once
#include "Sensor.h"

class AirSpeed : public Sensor {
public:
	void gatherData();
	void processData();
};
