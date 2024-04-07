#include "Q4.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include<cmath>

using namespace std;

int Q4() {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(500, 500, "hi", NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_LINES);
		// Draw X and Y axis
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(
			-1.0, 0.0);
		glVertex2f(1.0, 0.0);
		glVertex2f(0.0, 1.0);
		glVertex2f(0.0,
			-1.0);
		// Plot sine curve
		glColor3f(0.0, 1.0, 0.0);
		float prev_x =
			-1;
		float prev_y = 0;

		// THE GAUSSIAN!!!!!!!!!!!!!!!!!!!!!!!
		for (float i = -1; i < 1; i += 0.001) {
			float x = i;
			float y = 0.5 * exp(- (i * i) / (2 * 0.2 * 0.2));
			glVertex2f(prev_x, prev_y);
			glVertex2f(x, y);
			prev_x = x;
			prev_y = y;
		}
		glEnd();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
