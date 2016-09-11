/*
	Almost all of this is not my code.
	This is my completion of an OpenGL tutorial. 
	Source: www.learnopengl.com
	
	-Ryan Samlalsingh-
*/


//This enables the static GLEW libl
#define GLEW_STATIC

//GLEW is the OpenGL extention wrangler library
//	The purpose of GLEW is to facilitate finding the location of OpenGL functions implemented	
//	by the driver developer
#include <GL/glew.h>

//GLFW is a library allowing creation of OpenGL contexts and receival of inputs
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	//Initialize GLFW
	if(glfwInit() == GL_FALSE){
		cout << "glfwInit failed\n";
		return -1;
	}

	//Setting GLFW options

	//User must have OpenGL 3.3 or greater, as noted below
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Using OpenGL legacy functions is not available in the core profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//OpenGL context should not be resizable
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(800,600,"LearnOpenGL", NULL, NULL);

	if (window == NULL){
		cout << "Did not create GLFW window\n";
		//Terminate every window and free all resources
		glfwTerminate();
	
		return -2;
	}

	//Make the context of the GLFW window the main context of current thread
	glfwMakeContextCurrent(window);

	//Setting glewExperimental to true enables modern GLEW functionality
	// 	This is useful to ensure compatibility with OpenGL core profile

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK){
		cout << "GLEW could not be initialized\n";
		return -3;
	}

	//Now, OpenGL must know the size of the rendering window
	//	Take viewport dimensions from GLFW instead of hardcoding to 
	//	ensure the code works on high DPI screens as well
	
	//Note: If the viewport is made smaller than GLFW dimensions,
	//	we can put other things in the remaining space...

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	cout << width << "x" << height << endl;


	//First 2 arguments are the location of lower left corner of window
	//	Last arguments are the dimensions of the viewport
	glViewport(0,0,width,height);

	//My addition: float controlling colour
	GLfloat colour = 0.5;
	GLbyte is_ascending = 0;

	//The game loop: keeps the OpenGL window alive until it is instructed to close
	while (!glfwWindowShouldClose(window)){
		//While not scheduled to close (!glfwWindowShouldClose()):
		//	Poll for events such as keypresses;
		//	Swap the color buffer

		glfwPollEvents();
		glfwSwapBuffers(window);

		
		//My own code for window colour changing is below
		//glClearColor effectively sets background colour value
		//glClear sets the colour values of the window to match
		glClearColor(sin(colour),cos(colour),0,tan(colour));
		glClear(GL_COLOR_BUFFER_BIT);
		if(is_ascending == 0){
			colour -= 0.01;
			if (colour == 0.1){
				is_ascending = 1;
			}
		} else if (colour == 0.9){
			is_ascending = 0;
		} else {
			colour += 0.01;
		}

		//cout << "Main loop\n";
	}

	//The game loop has exited, terminate and free up resources
	glfwTerminate();
	cout << "Exiting...\n";
	return 0;
}

/* Extended notes:
	The colour buffer holds all of the colour values for each pixel at a given time.
	If there was a single buffer, there would be lots of flickering as each pixel 
	would change colour one by one on the screen. Windowing applications often use a double
	buffer to prevent this: the front buffer is displayed while the back buffer is loaded. 
	Then, the buffers are "swapped" and all the new pixel colours are displayed at once.
*/	