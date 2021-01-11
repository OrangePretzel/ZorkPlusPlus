#pragma once

#include <iostream>

#define FMT_HEADER_ONLY
#include "fmt/format.h"

#include <Zork.Core/Common.hpp>
#include <Zork.Core/Rendering/IRenderer.hpp>

namespace Zork
{
	class App
	{
	public:
		App(IApplicationContext* appContext) :
			_appContext(appContext)
		{
		}

		int run();

		// Data
	private:
		bool _isRunning{true};
		IApplicationContext* _appContext{nullptr};

		// Logging
	private:
		template <typename S, typename... Args>
		inline void log(const S& format_str, Args&&... args)
		{
			std::cout << fmt::format(format_str, args...) << std::endl;
		}

		// Methods
	public:
	};
} // namespace Zork