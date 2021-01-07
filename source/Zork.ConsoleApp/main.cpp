#include <iostream>

#include <Zork.Core/App.hpp>

int main(int argc, char** argv)
{
	try
	{
		Zork::App app{};
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

		// #ifdef _DEBUG
		// 		// Wait for user to close the application
		// 		std::cout << "Press ENTER to continue..." << std::endl;
		// 		std::getchar();
		// #endif

		return -1;
	}
}