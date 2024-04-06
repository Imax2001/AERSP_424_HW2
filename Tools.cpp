#include "Tools.h"
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

mutex m1, m2, m3, m4, m5;

void tool1(int id) {
	m1.lock();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Robot " << id << " has grabed tool 1." << endl;
	if (id == 1){
		tool2(id);
	}
	else if (id == 5){
		tool5(id);
	}
	else {
		cout << "This thread isn't supposed to be here. Something went wrong." << endl;
	}
	m1.unlock();
}

void tool2(int id){
	m2.lock();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Robot " << id << " has grabed tool 2." << endl;
	task(id);
	m2.unlock();
}

void tool3(int id) {
	m3.lock();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Robot " << id << " has grabed tool 3." << endl;
	if (id == 2) {
		tool2(id);
	}
	else if (id == 3) {
		tool4(id);
	}
	else {
		cout << "This thread isn't supposed to be here. Something went wrong." << endl;
	}
	m3.unlock();
}

void tool4(int id) {
	m4.lock();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Robot " << id << " has grabed tool 4." << endl;
	if (id == 3) {
		task(id);
	}
	else if (id == 4) {
		tool5(id);
	}
	else {
		cout << "This thread isn't supposed to be here. Something went wrong." << endl;
	}
	m4.unlock();
}

void tool5(int id){
	m5.lock();
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Robot " << id << " has grabed tool 5." << endl;
	task(id);
	m5.unlock();
}

void task(int id) {
	this_thread::sleep_for(chrono::seconds(5));
	cout << "Robot " << id << " has completed its task." << endl;
}