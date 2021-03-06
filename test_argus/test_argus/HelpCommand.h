#pragma once

#include "Command.h"


class HelpCommand : public Command {
protected:
	virtual bool ValidSyntaxStage(const std::vector<std::string >& words);
	virtual void ProcessCommand(const std::vector<std::string >& words, ImageMapper&);
};