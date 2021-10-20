#include <iostream>
#include "Brick Factories.h"

class Command
{
public:
	virtual ~Command(){};
	virtual void execute() = 0;
protected:
	Command(){};
	Lego lego;
	Clay clay;
	Lime lime;
	Ash ash;
};

class LegoCommand: public Command
{
public:
	virtual void execute(){lego.legoSnap();}
};
class ClayCommand: public Command
{
public:
	virtual void execute(){clay.clayForm();}
};
class LimeCommand: public Command
{
public:
	virtual void execute(){lime.limeBreak();}
};
class AshCommand: public Command
{
public:
	virtual void execute(){ash.ashMix();}
};