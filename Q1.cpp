#include "Sensor.h"
#include "Altitude.h"
#include "Air_Speed.h"
#include "AoA.h"
#include "SensorFactory.h"

using namespace std;

void Q1() {

	SensorFactory sensorfactory;
	Sensor* aoa1 = sensorfactory.createSensor("AoA");
	aoa1->gatherData();
}