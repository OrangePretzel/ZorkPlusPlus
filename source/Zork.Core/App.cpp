#include <Zork.Core/App.hpp>

#include <map>

// Normalize trims and lowercases the input string
void normalizeString(std::string& str)
{
	// Trim left: erase from beginning to first non-space character
	str.erase(
		str.begin(),
		std::find_if(
			str.begin(),
			str.end(),
			[](unsigned char ch) { return !std::isspace(ch); }));

	// Trim right: erase from last non-space character to end
	str.erase(
		std::find_if(
			str.rbegin(),
			str.rend(),
			[](unsigned char ch) { return !std::isspace(ch); })
			.base(),
		str.end());

	// Lowercase the string
	std::transform(
		str.begin(),
		str.end(),
		str.begin(),
		[](unsigned char ch) { return std::tolower(ch); });
}

std::map<std::string, Zork::CommandTypes> commandMap{
	{"quit", Zork::CommandTypes::Quit},
	{"exit", Zork::CommandTypes::Quit},

	{"f", Zork::CommandTypes::Forward},
	{"foreward", Zork::CommandTypes::Forward},
	{"forward", Zork::CommandTypes::Forward},
	{"b", Zork::CommandTypes::Back},
	{"back", Zork::CommandTypes::Back},
	{"backward", Zork::CommandTypes::Back},
};

void getCommand(Zork::Command& command)
{
	std::string input;
	std::getline(std::cin, input);
	normalizeString(input);

	if (commandMap.find(input) != commandMap.end())
	{
		command.type = commandMap[input];
	}
	else
	{
		command.type = Zork::CommandTypes::None;
	}
}

int Zork::App::run(int argc, char** argv)
{
	Command command{};

	_isRunning = true;
	while (_isRunning)
	{
		getCommand(command);
		performCommand(command);
		printState();
	}

	return 0;
}

void Zork::App::printState()
{
	static const int length = 20;
	static const std::string frameHoriztonal = '+' + std::string(length, '-') + '+';
	log(frameHoriztonal);
	log('|' + std::string(_state.progress, '=') + std::string(length - _state.progress, ' ') + '|');
	log(frameHoriztonal);
}

void Zork::App::performCommand(const Command& command)
{
	switch (command.type)
	{
	case Zork::CommandTypes::Quit:
		_isRunning = false;
		break;

	case Zork::CommandTypes::Forward:
		_state.progress = std::min(_state.progress + 1, 20);
		break;

	case Zork::CommandTypes::Back:
		_state.progress = std::max(_state.progress - 1, 0);
		break;

	default:
		// Do nothing
		log("Nothing happened.");
		break;
	}
}
