#include "BlurCommand.h"

#include "utility.h"

bool BlurCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 3) {
		return true;
	}

	return false;
}

void BlurCommand::ProcessCommand(const std::vector<std::string >& words, ImageMapper& mapper) {
	try {

		if (!mapper.exist(words[0])) {
			throw Magick::Exception(std::string("Object ") + words[0] + " not found");
		}
		int blur_size = 0;

		STR2INT_ERROR err = str2int(blur_size, words[2].c_str());

		if(err == STR2INT_INCONVERTIBLE)
		{
			throw Magick::Exception(std::string("Blur size is not an integer number") );
		}

		else if (err != STR2INT_SUCCESS) 
		{
			throw Magick::Exception(std::string("number overflow"));
		}

		if (blur_size <= 0) {
			throw Magick::Exception(std::string("Blur size must be positive"));
		}

		if ((blur_size % 2) == 0) {
			throw Magick::Exception(std::string("Blur size must be odd"));
		}

		auto p_image = mapper.images[words[0]];

		std::shared_ptr<Magick::Image> p_copy_image ( new Magick::Image() );
		*p_copy_image = *p_image;


		double radius = (blur_size - 1) / 2; // remove central point and calculate only from one side
		double sigma = radius / 3; // 3 sigma


		p_copy_image->blur(radius, sigma);

		mapper.images[words[1]] = p_copy_image;

		std::cout << "Blur Done" << std::endl;
	}
	catch (const Magick::Exception& e) {
		std::cout << e.what() << std::endl;
	}
}
