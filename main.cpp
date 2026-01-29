#include <SDL3/SDL.h>
#include <vector>
#include <random>
#include <iostream>
void PlaceFood(std::vector<std::vector<int>> &grid) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disty(0, grid.size()-1);
	std::uniform_int_distribution<> distx(0, grid[0].size()-1);

	int x = distx(gen);
	int y = disty(gen);
	grid[y][x] = 1;
}

void drawGrid(std::vector<std::vector<int>> grid)
{
	for (const auto row : grid)
	{
		for (const auto col : row) \
		{
			std::cout << col << " ";
		}
		std::cout << std::endl;
	}
}

int main() 
{
	std::vector<std::vector<int>> grid(5, std::vector<int>(3, 0));
	PlaceFood(grid);
	drawGrid(grid);
}

