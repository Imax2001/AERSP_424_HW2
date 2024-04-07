#include "Q2.h"
#include "Tools.h"
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

void Q2() {
	cout << "-------------------------- Begin Q2 --------------------------" << endl;
	//robot one will grab tool 1 and then tool 2
	thread robot1(tool1, 1);
	//robot 4 then will grab tools 4 and 5
	thread robot4(tool4, 4);
	// robot 3 will grab tool 3 and then wait to grab tool 4 when robot 4 is done with it
	thread robot3(tool3, 3);
	//robot 5 will wait to grab tool 1 when robot 4 is done with it and then grab tool 5
	thread robot5(tool1, 5);
	// robot 2 will wait to grab tool 3 when robot 3 is done with it and then grab tool 2
	thread robot2(tool3, 2);
	robot1.join();
	robot4.join();
	robot3.join();
	robot5.join();
	robot2.join();



	cout << "--------------------------- End Q2 ---------------------------" << endl << endl;
}