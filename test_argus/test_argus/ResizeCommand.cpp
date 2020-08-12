#include "ResizeCommand.h"

#include "utility.h"


bool ResizeCommand::ValidSyntaxStage(const std::vector<std::string >& words) {
	if (words.size() == 4) {
		return true;
	}

	return false;
}

static void process_int_conversion(STR2INT_ERROR err, int size)
{
	if (err == STR2INT_INCONVERTIBLE)
	{
		throw Magick::Exception(std::string("Blur size is not an integer number"));
	}

	else if (err != STR2INT_SUCCESS)
	{
		throw Magick::Exception(std::string("number overflow"));
	}

	if (size <= 0) {
		throw Magick::Exception(std::string("Blur size must be positive"));
	}

}

void ResizeCommand::ProcessCommand(const std::vector<std::string >& words, ImageMapper& mapper) {

	try {
		if (!mapper.exist(words[0])) {
			throw Magick::Exception(std::string("Object ") + words[0] + " not found");
		}
		int width = 0;
		int height = 0;

		STR2INT_ERROR err = str2int(width, words[2].c_str());
		process_int_conversion(err, width);

		STR2INT_ERROR err1 = str2int(height, words[3].c_str());
		process_int_conversion(err1, height);


		auto p_image = mapper.images[words[0]];

		std::shared_ptr<Magick::Image> p_copy_image(new Magick::Image());
		*p_copy_image = *p_image;

		Magick::Geometry geom(width, height);
		geom.aspect(true);

		p_copy_image->resize(geom);


		mapper.images[words[1]] = p_copy_image;

		std::cout << "Resize Done" << std::endl;

	}
	catch (const Magick::Exception& e) {
		std::cout << e.what() << std::endl;
	}
}
