#include "BlurCommand.h"

bool BlurCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 3) {
		return true;
	}

	return false;
}

void BlurCommand::ProcessCommand(const std::vector<std::string >& words) {
	std::cout << "Blur" << std::endl;
}
