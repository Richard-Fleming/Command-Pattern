#include "Brick.h"
class Lego : public Brick{
public:
	void legoSnap() {
		std::cout << "Snap Lego Brick" << std::endl;
	}
	void draw() {
		std::cout << "Draw Lego Brick" << std::endl;
	}
};

class Clay : public Brick{
public:
	void clayForm(){
		std::cout << "Form Clay Brick" << std::endl;
	}
	void draw() {
		std::cout << "Draw Clay Brick" << std::endl;
	}
};

class Lime : public Brick{
public:
	void limeBreak(){
		std::cout << "Break Off Lime Brick" << std::endl;
	}
	void draw() {
		std::cout << "Draw Lime Brick" << std::endl;
	}
};

class Ash : public Brick{
public:
	void ashMix(){
		std::cout << "Mix Ash Brick" << std::endl;
	}
	void draw() {
		std::cout << "Draw Ash Brick" << std::endl;
	}
};