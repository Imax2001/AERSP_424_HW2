#include "Q2.h"
#include "Tools.h"
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

void Q2() {
	cout << "-------------------------- Begin Q2 --------------------------" << endl;
	thread robot1(tool1, 1);
	thread robot4(tool4, 4);
	thread robot3(tool3, 3);
	thread robot5(tool1, 5);
	thread robot2(tool3, 2);
	robot1.join();
	robot4.join();
	robot3.join();
	robot5.join();
	robot2.join();



	cout << "--------------------------- End Q2 ---------------------------" << endl << endl;
}