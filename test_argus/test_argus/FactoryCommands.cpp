#include "FactoryCommands.h"

#include "LoadCommand.h"
#include "StoreCommand.h"
#include "BlurCommand.h"
#include "ResizeCommand.h"
#include "ExitCommand.h"
#include "HelpCommand.h"


std::shared_ptr<Command> FactoryCommands::createCommand(CommandTypes command_type) {

	if (command_type == CommandTypes_Load) {
		return std::shared_ptr<Command>( new LoadCommand() );
	}
	else if (command_type == CommandTypes_Store) {
		return std::shared_ptr<Command>( new StoreCommand() );
	}
	else if (command_type == CommandTypes_Blur) {
		return std::shared_ptr<Command>( new BlurCommand() );
	}
	else if (command_type == CommandTypes_Resize) {
		return std::shared_ptr<Command>( new ResizeCommand() );
	}
	else if (command_type == CommandTypes_Help) {
		return std::shared_ptr<Command>( new HelpCommand() );
	}
	else if (command_type == CommandTypes_Exit) {
		return std::shared_ptr<Command>( new ExitCommand() );
	}
	else {
		return NULL;
	}

}