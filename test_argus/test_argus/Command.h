#pragma once

#include <string>
#include <vector>

#include <iostream> // just to derive in childs like stdafx.h

#include <Magick++.h> 

#include <memory>

class ImageMapper {
public:
	std::map< std::string, std::shared_ptr< Magick::Image > > images;

	bool exist(const std::string& name) const {
		return (images.find(name) != images.end());
	}
};


class Command{
public:
	virtual bool ValidSyntaxStage(const std::vector<std::string >& words) = 0;
	virtual void ProcessCommand(const std::vector<std::string >& words, ImageMapper&) = 0;

	virtual ~Command() = default;
};