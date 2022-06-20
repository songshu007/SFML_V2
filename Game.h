#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Piece.h"
#include "Setting.h"
#include "PieceBoard.h"

class Game
{
private:
	void initWindow();
	void updata();
	void render();
	void checkSFMLEvent();

private:
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	float dt;
	PieceBoard* pieceBoard;

public:
	Game();
	~Game();
	void run();

};

