#include "Snake.h"
#include "Structs.h"
#include <iostream>

Snake::Snake() : body(5, Body())
{

}

void Snake::ChangeDirection(Direction newDirection) 
{
	//pass down the previous body's direction
	Direction d1 = newDirection; //parent direction
	Direction d2; //current direction
	for (int i = 0; i < body.size(); i++)
	{
		d2 = body[i].GetDirection();
		body[i].SetDirection(d1);
		d1 = d2;
	}
}

void Snake::PrintSnake() 
{
	std::cout << "Direction: ";
	for (int i = 0; i < body.size(); i++) 
	{
		std::string dir = "";
		Direction d = body[i].GetDirection();
		switch (d)
		{
		case Direction::up:
			dir += "up";
			break;
		case Direction::down:
			dir += "down";
			break;
		case Direction::left:
			dir += "left";
			break;
		case Direction::right:
			dir += "right";
			break;
		default:
			break;
		}

		std::cout << dir;
	}
	std::cout << std::endl;
}