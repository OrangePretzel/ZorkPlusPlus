#pragma once

// Include GLFW
#define NOMINMAX // Disable the windows.h min/max macros
#include <gl3w/gl3w.h>

#include <GLFW/glfw3.h>

#include <Zork.Core/Common.hpp>
#include <Zork.Core/Rendering/IRenderer.hpp>

#include <iostream>

void glfwErrorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << error << description << std::endl;
}

class GLFWWindowContext : public Zork::IApplicationContext
{
public:
	GLFWWindowContext(const int width, const int height, const char* title)
	{
		glfwSetErrorCallback(glfwErrorCallback);

		if (!glfwInit())
		{
			throw Zork::Exception("Failed to initialize GLFW");
		}

		// Set window settings
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

#if __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		// Create the window
		_window = glfwCreateWindow(
			width,
			height,
			title,
			nullptr, /* monitor (for fullscreen) */
			nullptr /* window to share resources with */);
		if (_window == nullptr)
		{
			throw Zork::Exception("Failed to create GLFW window");
		}

		glfwMakeContextCurrent(_window);
		glfwSwapInterval(1); // vsync

		// Load OpenGL function pointers
		gl3w_init();

		// Initialize input handlers

		// Setting callbacks to member functions (that's why the redirect is needed)
		// Input is handled using GLFW, for more info see
		// http://www.glfw.org/docs/latest/input_guide.html
		// glfwSetWindowUserPointer(m_window, this);
		// auto key_redirect = [](GLFWwindow* wnd, int _0, int _1, int _2, int _3) { ((World*)glfwGetWindowUserPointer(wnd))->on_key(wnd, _0, _1, _2, _3); };
		// auto cursor_pos_redirect = [](GLFWwindow* wnd, double _0, double _1) { ((World*)glfwGetWindowUserPointer(wnd))->on_mouse_move(wnd, _0, _1); };
		// glfwSetKeyCallback(m_window, key_redirect);
		// glfwSetCursorPosCallback(m_window, cursor_pos_redirect);
	}

	~GLFWWindowContext()
	{
		if (_window != nullptr)
		{
			glfwDestroyWindow(_window);
		}

		glfwTerminate();
	}

public:
	bool hasAppRequestedClose() override
	{
		return glfwWindowShouldClose(_window) == GL_TRUE;
	}

	void getContextSize(int& width, int& height) override
	{
		glfwGetWindowSize(_window, &width, &height);
	}

	void update() override
	{
		glfwPollEvents();
	}

	void swapBuffers() override
	{
		glfwSwapBuffers(_window);
	}

private:
	GLFWwindow* _window;
};
