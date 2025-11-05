#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// callback function for window resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// handle input
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}


int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed to Initialize GLFW\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Simle Window", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to Create Window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to Initialzie GLAD\n";
			return -1;
		}
		// set callback
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		//Main Loop
		while (!glfwWindowShouldClose(window))
		{
			// handle input
			processInput(window);
			glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();

return 0;
}

