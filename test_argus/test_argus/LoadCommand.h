#pragma once

#include "Command.h"


class LoadCommand : public Command {
protected:
	virtual bool ValidSyntaxStage(const std::vector<std::string >& words);
	virtual void ProcessCommand(const std::vector<std::string >& words);
};