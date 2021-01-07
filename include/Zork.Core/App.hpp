#pragma once

#include <iostream>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include <Zork.Core/Common.hpp>

namespace Zork
{
	struct GameState
	{
		int progress{0};
	};

	enum class CommandTypes
	{
		None,
		Quit,

		Forward,
		Back,
	};

	struct Command
	{
		CommandTypes type;
	};

	class App
	{
	public:
		int run(int argc, char** argv);

		// Data
	private:
		bool _isRunning{true};
		GameState _state{};

		// Logging
	private:
		template <typename S, typename... Args>
		inline void log(const S& format_str, Args&&... args)
		{
			std::cout << fmt::format(format_str, args...) << std::endl;
		}

		// Methods
	public:
		void printState();
		void performCommand(const Command& command);
	};
} // namespace Zork