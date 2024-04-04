#pragma once
class Sensor
{
public:
	virtual void gatherData();
	virtual void processData();
};