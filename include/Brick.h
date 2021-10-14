#include <iostream>
class Brick
{
public:
	Brick(){};
	virtual ~Brick(){};
	virtual void draw() = 0;
};