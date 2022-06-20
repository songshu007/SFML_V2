#include "PieceBoard.h"

PieceBoard::PieceBoard(sf::RenderWindow& window, float& dt)
	:window(window), dt(dt)
{
	this->map = new std::vector<std::vector<Piece*>>(Setting::getSet().Set.BlockYnum, std::vector<Piece*>(Setting::getSet().Set.BlockXnum));

	// init map
	for (int y = 0; y < Setting::getSet().Set.BlockYnum; y++)
	{
		for (int x = 0; x < Setting::getSet().Set.BlockXnum; x++)
		{
			this->map->at(y).at(x) = new Piece(x, y, this->map, this->dt, this->window);
		}
	}

}

PieceBoard::~PieceBoard()
{
}

void PieceBoard::updata()
{
}

void PieceBoard::render()
{
}
