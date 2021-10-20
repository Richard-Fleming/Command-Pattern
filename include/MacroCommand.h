#include "Command.h"
#include <list>
class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
private:
	std::list<Command*>* commands;
};

void MacroCommand::execute(){
	
}