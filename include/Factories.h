#include "Brick Factories.h"
class Factory{
public:
	virtual Brick* CreateLego() = 0;
	virtual Brick* CreateClay() = 0;
	virtual Brick* CreateLime() = 0;
	virtual Brick* CreateAsh() = 0;
};

class BrickFactory : public Factory{
public: 
	Brick* CreateLego(){
		return new Lego;
	}
	Brick* CreateClay(){
		return new Clay;
	}
	Brick* CreateLime(){
		return new Lime;
	}
	Brick* CreateAsh(){
		return new Ash;
	}
};