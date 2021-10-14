#include "Brick.h"
class Lego : public Brick{
public:
	void draw() {
		std::cout << "Draw Lego Brick" << std::endl;
	}
};

class Clay : public Brick{
public:
	void draw(){
		std::cout << "Draw Clay Brick" << std::endl;
	}
};

class Lime : public Brick{
public:
	void draw(){
		std::cout << "Draw Lime Brick" << std::endl;
	}
};

class Ash : public Brick{
public:
	void draw(){
		std::cout << "Draw Ash Brick" << std::endl;
	}
};