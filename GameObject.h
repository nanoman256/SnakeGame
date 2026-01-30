#pragma once
class GameObject
{
public:
	virtual int GetPositionX() = 0;
	virtual int GetPositionY() = 0;
	virtual void OnCollision() = 0;
	virtual bool IsCollision() = 0;
};

