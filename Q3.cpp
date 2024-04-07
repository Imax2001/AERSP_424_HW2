#include "Q3.h"
#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <queue>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex m;

// global queue represents 'traffic pattern'
queue<int> traffic;

void contact_ATC() {
	// 'Plane' thread attempts to talk to ATC if no other 'Plane' is
	m.lock();
	this_thread::sleep_for(chrono::seconds(1));
	int pid = traffic.front();
	traffic.pop();
	cout << "Plane " << pid << " has landed." << endl;
	m.unlock();
}


void Q3() {
	cout << "-------------------------- Begin Q3 --------------------------" << endl;
	vector<thread> planes;
	srand(time(NULL));
	// Main thread loops, spawning threads to represent each Plane
	for (int i = 1; i <= 10; i++) {
		this_thread::sleep_for(chrono::milliseconds(rand() % 1001));
		if (traffic.size() < 3) {
			cout << "Plane " << i << " has requested to land." << endl;
			traffic.push(i);
			planes.emplace_back([&]() { contact_ATC(); });
		}
		else {
			cout << "The traffic pattern is full. Plane " << i << " has left for another airport." << endl;
		}
	}

	for (auto& t : planes)
	{
		t.join();

	}


	cout << "--------------------------- End Q3 ---------------------------" << endl << endl;
}
