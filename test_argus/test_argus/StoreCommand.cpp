#include "StoreCommand.h"

bool StoreCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 2) {
		return true;
	}

	return false;
}

void StoreCommand::ProcessCommand(const std::vector<std::string >& words, ImageMapper& mapper) {
	try {

		if (!mapper.exist(words[0])) {
			throw Magick::Exception(std::string("Object ") + words[0] + " not found");
		}

		auto p_image = mapper.images[words[0]];

		p_image->write(words[1]);

		std::cout << "Store Done" << std::endl;
	}
	catch (const Magick::Exception& e) {
		std::cout << e.what() << std::endl;
	}
}

