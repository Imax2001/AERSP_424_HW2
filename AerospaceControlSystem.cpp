#include "AerospaceControlSystem.h"
#include "Sensor.h"
#include "SensorFactory.h"
#include <vector>
#include <iostream>
using namespace std;

void AerospaceControlSystem::addSensor(string sensor_type) {
	Sensor* sensor = this->factory.createSensor(sensor_type);
	this->sensors.push_back(sensor);
}

void AerospaceControlSystem::monitorAndAdjust() {
	for (Sensor* sensor : this->sensors) {
		sensor->gatherData();
		sensor->processData();
	}
	cout << "Adjusting controls based on sensor data." << endl;
}