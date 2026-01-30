#include "GameObject.h"
#include "Structs.h"
#pragma once
class Body : public GameObject
{
public:
	Direction GetDirection();
	void SetDirection(Direction newDirection);
	int GetPositionX() { return 0; };
	int GetPositionY() { return 0; };

	void OnCollision() {};
	bool IsCollision() { return 0; };
	void SetPositionX() {};
	void SetPositionY() {};

private:
	Direction direction = Direction::right;
};

