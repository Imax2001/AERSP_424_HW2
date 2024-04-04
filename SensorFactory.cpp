#include "SensorFactory.h"
#include "AoA.h"
#include "Altitude.h"
#include "Air_Speed.h"
#include <string>
#include <iostream>

using namespace std;

 Sensor* SensorFactory::createSensor(string sensor_type) {
	if (sensor_type == "AoA") {
		return new AoA();
	}
	else if (sensor_type == "Altitude") {
		return new Altitude();
	}
	else if (sensor_type == "AirSpeed") {
		return new AirSpeed();
	}
	else {
		cout << "Sensor type not recognized" << endl;
		return NULL;
	}
	
}
