#include <iostream>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include <Zork.Core/Common.hpp>

class App
{
private:
	template <typename S, typename... Args>
	void log(const S& format_str, Args&&... args)
	{
		std::cout << fmt::format(format_str, args...) << std::endl;
	}

public:
	int run(int argc, char** argv)
	{
		log("Hello World!");
		return 0;
	}
};

int main(int argc, char** argv)
{
	try
	{
		App app{};
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