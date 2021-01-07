#pragma once

#include <Zork.Core/ANSICodes.hpp>

#include <sstream>
#include <stdexcept>
#include <string>

namespace Zork
{
	/* virtual */ class Exception : public std::runtime_error
	{
	public:
		Exception(const std::string &message) : std::runtime_error(message) {}

		virtual ~Exception() {}

		virtual std::string toString() const { return std::runtime_error::what(); }
	};
} // namespace Zork
