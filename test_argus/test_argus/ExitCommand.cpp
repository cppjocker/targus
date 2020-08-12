#include "ExitCommand.h"

bool ExitCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.empty()) {
		return true;
	}

	return false;
}

void ExitCommand::ProcessCommand(const std::vector<std::string >& words, ImageMapper&) {
	exit(0); // shit style but we use that to not disturb architecture
}
