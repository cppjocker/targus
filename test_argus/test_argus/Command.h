#pragma once

#include <string>
#include <vector>

#include <iostream> // just to derive in childs like stdafx.h

class Command{
public:
	virtual bool ValidSyntaxStage(const std::vector<std::string >& words) = 0;
	virtual void ProcessCommand(const std::vector<std::string >& words) = 0;

};