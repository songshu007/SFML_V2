#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Setting.h"

enum Dir
{
	UP,
	DOWN, 
	LEFT,
	RIGHT
};

class Piece
{
private:
	std::vector<std::vector<Piece*>>* map;
	sf::RectangleShape shape;
	sf::RenderWindow& window;
	float& dt;
	// 相对于map棋子的位置
	int map_x = 0;
	int map_y = 0;

public:
	Piece(int map_x, int map_y, std::vector<std::vector<Piece*>>* map, float& dt, sf::RenderWindow& win);
	~Piece();
	void updata();
	void render();
	void move(Dir dir);

};

