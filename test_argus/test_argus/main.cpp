#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <cassert>

#include <algorithm>
#include <cctype>

#include "FactoryCommands.h"
#include "Command.h"

#include <Magick++.h> 

static const std::string usage_str = "Usage: command supports next options.\n -- load, ld <name>  <filename> \n -- store,s  <name>  <filename> \n -- blur <from> <to> <size> \n -- resize <from> <to>  <new_w> <new_h> \n q, quit, exit. \n ";


static CommandTypes parse_stage(const std::string& next_line, std::vector<std::string >& words)
{
	std::stringstream ss(next_line);

	std::string first_word;

	ss >> first_word;

	std::transform(first_word.begin(), first_word.end(), first_word.begin(),
		[](unsigned char c) { return std::tolower(c); });

	CommandTypes current_command;

	// parse first stage
	if (first_word == "ld" || first_word == "load") {
		current_command = CommandTypes_Load;
	}
	else if (first_word == "s" || first_word == "store") {
		current_command = CommandTypes_Store;
	}
	else if (first_word == "blur" ) {
		current_command = CommandTypes_Blur;
	}

	else if (first_word == "resize") {
		current_command = CommandTypes_Resize;
	}
	else if (first_word == "help" || first_word == "h") {
		current_command = CommandTypes_Help;
	}
	else if (first_word == "q" || first_word == "quit" || first_word == "exit") {
		current_command = CommandTypes_Exit;
	}
	else {
		current_command = CommandTypes_Wrong;
	}

	words.clear();

	while (!ss.eof()) {
		std::string next_word;
		ss >> next_word;

		if (next_word.empty()) {
			return current_command;
		}

		words.push_back(next_word);
	}

	return current_command;
}



int main(int argc, char** argv) {
	Magick::InitializeMagick(*argv);

	while (true) {

		std::string next_line;

		std::getline(std::cin, next_line);

		std::vector<std::string > words;

		CommandTypes command_type = parse_stage(next_line, words);
		auto current_command = FactoryCommands::createCommand(command_type);

		if (current_command == NULL) {
			std::cout << usage_str;
			continue;
		}

		bool is_valid = current_command->ValidSyntaxStage(words);

		if (!is_valid) {
			std::cout << usage_str;
			continue;
		}

		current_command->ProcessCommand(words);
	}

	return 0;
}