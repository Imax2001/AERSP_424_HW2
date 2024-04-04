#include "Sensor.h"
#include "Altitude.h"
#include "Air_Speed.h"
#include "AoA.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"

using namespace std;

void Q1() {

	AerospaceControlSystem ctlSys;
	ctlSys.addSensor("AoA");
	ctlSys.addSensor("Altitude");
	ctlSys.addSensor("AirSpeed");
	ctlSys.monitorAndAdjust();
}