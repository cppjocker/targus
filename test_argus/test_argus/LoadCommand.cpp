#include "LoadCommand.h"

bool LoadCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 2) {
		return true;
	}

	return false;
}

void LoadCommand::ProcessCommand(const std::vector<std::string >& words, ImageMapper& mapper) {
	try {
		std::shared_ptr<Magick::Image> p_image(new Magick::Image());

		p_image->read(words[1]);

		mapper.images[words[0]] = p_image;

		std::cout << "Load Done" << std::endl;
	}
	catch (const Magick::Exception& e) {
		std::cout << e.what() << std::endl;
	}

}
