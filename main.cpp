#include <SDL3/SDL.h>
#include <vector>
#include <random>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include "Snake.h"

void PlaceFood(std::vector<std::vector<int>> &grid) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disty(0, grid.size()-1);
	std::uniform_int_distribution<> distx(0, grid[0].size()-1);

	int x = distx(gen);
	int y = disty(gen);
	grid[y][x] = 2;
}

/*void DrawGrid(std::vector<std::vector<int>> grid, Snake s)
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (s.x == j && s.y == i)
				std::cout << 1 << " ";
			else
				std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
*/
void clearScreen() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(hConsole, ' ', cellCount, { 0, 0 }, &count);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, { 0, 0 }, &count);
	SetConsoleCursorPosition(hConsole, { 0, 0 });
}

int main()
{
	std::vector<Direction> movements = {Direction::left, Direction::left, Direction::left, Direction::right};
	Snake newSnake;
	for (Direction d : movements) 
	{
		newSnake.PrintSnake();
		newSnake.ChangeDirection(d);
	}
	//SDL_Quit();
}

