#include <Zork.Core/App.hpp>

#include <Zork.Core/Rendering/OpenGL/OpenGLRenderer.hpp>

#include <chrono>
using Clock = std::chrono::high_resolution_clock;

int Zork::App::run()
{
	std::unique_ptr<IRenderer> renderer = std::make_unique<Zork::OpenGLRenderer>(_appContext);

	auto startTime = Clock::now();

	_isRunning = true;
	while (_isRunning)
	{
		// Update time
		auto now = Clock::now();
		float elapsed_ms = (float)(std::chrono::duration_cast<std::chrono::microseconds>(now - startTime)).count() / 1000;

		// Update the application context (i.e. poll window events)
		_appContext->update();
		if (_appContext->hasAppRequestedClose() || elapsed_ms > 10000)
		{
			_isRunning = false;
			// We will let the loop finish and close on the next iteration
		}

		renderer->render();
	}

	return 0;
}
