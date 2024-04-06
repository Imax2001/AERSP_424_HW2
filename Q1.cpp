#include "Sensor.h"
#include "Altitude.h"
#include "Air_Speed.h"
#include "AoA.h"
#include "SensorFactory.h"
#include "AerospaceControlSystem.h"
#include <iostream>

using namespace std;

void Q1() {
	cout << "-------------------------- Begin Q1 --------------------------" << endl;
	AerospaceControlSystem ctlSys;
	ctlSys.addSensor("AoA");
	ctlSys.addSensor("Altitude");
	ctlSys.addSensor("AirSpeed");
	ctlSys.monitorAndAdjust();
	cout << "--------------------------- End Q1 ---------------------------" << endl << endl;

}
