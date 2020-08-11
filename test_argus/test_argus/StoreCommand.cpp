#include "StoreCommand.h"

bool StoreCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 2) {
		return true;
	}

	return false;
}

void StoreCommand::ProcessCommand(const std::vector<std::string >& words) {
	std::cout << "Store" << std::endl;
}

