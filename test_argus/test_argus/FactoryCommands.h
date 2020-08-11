#pragma once

#include "Command.h"

#include <memory>

typedef enum {
	CommandTypes_Load = 0,
	CommandTypes_Store,
	CommandTypes_Blur,
	CommandTypes_Resize,
	CommandTypes_Help,
	CommandTypes_Exit,
	CommandTypes_Wrong

}CommandTypes;


class FactoryCommands {
public: 
	static std::shared_ptr<Command> createCommand(CommandTypes);
};