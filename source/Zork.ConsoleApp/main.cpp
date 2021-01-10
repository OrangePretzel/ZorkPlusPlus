#include <iostream>

// #include <SDL/SDL.h>

#include <Zork.Core/App.hpp>

#include "GLFWWindowContext.hpp"

int main(int argc, char** argv)
{
	try
	{
		// Create the window
		const char* windowTitle = "Zork Game!";
		std::unique_ptr<GLFWWindowContext> window = std::make_unique<GLFWWindowContext>(800, 600, windowTitle);

		// Create the app
		Zork::App app(window.get());

		// Run the app
		return app.run(argc, argv);
	}
	catch (const Zork::Exception& ex)
	{
		const std::string header = "====================";
		std::stringstream errorOutput;
		errorOutput << "\n"
					<< header << " BEGIN EXCEPTION " << header << "\n"
					<< ex.toString() << "\n"
					<< header << "  END EXCEPTION  " << header;

		std::cerr << errorOutput.str() << std::endl;
	}
	catch (const std::exception& ex)
	{
		const std::string header = "====================";
		std::stringstream errorOutput;
		errorOutput << "\n"
					<< header << " BEGIN EXCEPTION " << header << "\n"
					<< ex.what() << "\n"
					<< header << "  END EXCEPTION  " << header;

		std::cerr << errorOutput.str() << std::endl;
	}
}