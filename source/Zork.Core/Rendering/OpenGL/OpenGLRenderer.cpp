#include <Zork.Core/Rendering/OpenGL/OpenGLRenderer.hpp>

#define GL3W_IMPLEMENTATION
#include <gl3w/gl3w.h>

void clearOpenGLErrors()
{
	while (glGetError() != GL_NO_ERROR)
	{
		// Ignore
	}
}

void Zork::OpenGLRenderer::render()
{
	clearOpenGLErrors();

	// Update viewport size
	int width, height;
	getAppContext()->getContextSize(width, height);
	glViewport(0, 0, width, height);
	glDepthRange(0.00001, 10);

	// Clear backbuffer
	const float clearColor[3] = {0.3f, 0.3f, 0.8f};
	glClearColor(clearColor[0], clearColor[1], clearColor[2], 1.0);
	glClearDepth(1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	getAppContext()->swapBuffers();
}