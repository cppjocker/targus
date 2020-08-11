#include "ResizeCommand.h"

bool ResizeCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 4) {
		return true;
	}

	return false;
}

void ResizeCommand::ProcessCommand(const std::vector<std::string >& words) {
	std::cout << "Resize" << std::endl;
}
