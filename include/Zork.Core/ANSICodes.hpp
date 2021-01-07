#pragma once

#include <string>

namespace Zork
{
	// TODO: The following constants should be wrapped in a static struct/class/namespace?

	inline const std::string ANSI_ESCAPE_START = "\u001b[";
	inline const std::string ANSI_ESCAPE_END = "m";

	inline const std::string ANSI_RESET = ANSI_ESCAPE_START + "0" + ANSI_ESCAPE_END;

	inline const std::string ANSI_BLACK = ANSI_ESCAPE_START + "30" + ANSI_ESCAPE_END;
	inline const std::string ANSI_RED = ANSI_ESCAPE_START + "31" + ANSI_ESCAPE_END;
	inline const std::string ANSI_GREEN = ANSI_ESCAPE_START + "32" + ANSI_ESCAPE_END;
	inline const std::string ANSI_YELLOW = ANSI_ESCAPE_START + "33" + ANSI_ESCAPE_END;
	inline const std::string ANSI_BLUE = ANSI_ESCAPE_START + "34" + ANSI_ESCAPE_END;
	inline const std::string ANSI_MAGENTA = ANSI_ESCAPE_START + "35" + ANSI_ESCAPE_END;
	inline const std::string ANSI_CYAN = ANSI_ESCAPE_START + "36" + ANSI_ESCAPE_END;
	inline const std::string ANSI_WHITE = ANSI_ESCAPE_START + "37" + ANSI_ESCAPE_END;

	inline const std::string ANSI_GREY = ANSI_ESCAPE_START + "30;1" + ANSI_ESCAPE_END;

	inline const std::string ANSI_UNDERLINE = ANSI_ESCAPE_START + "4" + ANSI_ESCAPE_END;
} // namespace Zork