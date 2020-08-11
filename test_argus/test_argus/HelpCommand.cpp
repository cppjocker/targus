#include "HelpCommand.h"

static const std::string help_str = "targus - simple program for demonstration image processing toolkit. Several optiones are supported: \n -- load, ld <name>  <filename> \n -- store,s  <name>  <filename> \n -- blur <from> <to> <size> \n -- resize <from> <to>  <new_w> <new_h> \n q, quit, exit. \n ";


bool HelpCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.empty()) {
		return true;
	}

	return false;
}

void HelpCommand::ProcessCommand(const std::vector<std::string >& words) {
	std::cout << help_str << std::endl;
}
