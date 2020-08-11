#include "LoadCommand.h"

bool LoadCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 2) {
		return true;
	}

	return false;
}

void LoadCommand::ProcessCommand(const std::vector<std::string >& words) {
	std::cout << "Load" << std::endl;
}
