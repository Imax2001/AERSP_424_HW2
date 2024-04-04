#pragma once
#include "Sensor.h"


class AoA : public Sensor {
public:
	void gatherData();
	void processData();
};