#pragma once
#include "Piece.h"

class PieceBoard
{
private:
	//游戏棋盘
	//因为棋盘大小是根据 Setting.ini 中的设置决定的，是不确定的，所以要用动态数组存储
	std::vector<std::vector<Piece*>>* map;
	sf::RenderWindow& window;
	float& dt;

public:
	PieceBoard(sf::RenderWindow& window, float& dt);
	~PieceBoard();
	void updata();
	void render();

};

