#include "Body.h"
#include <vector>
#pragma once

class Snake : public GameObject
{
public:
	Snake();
	void ChangeDirection(Direction newDirection);
	void Move() {};

	void OnCollision() {};
	int GetPositionX() { return 0; };
	int GetPositionY() { return 0; };
	bool IsCollision() { return 0; };
	void PrintSnake();
	void Grow() {};

private:
	std::vector<Body> body;
	Direction m_direction;

};