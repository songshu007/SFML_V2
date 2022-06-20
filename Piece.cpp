#include "Piece.h"

Piece::Piece(int map_x, int map_y, std::vector<std::vector<Piece*>>* map, float& dt, sf::RenderWindow& win)
	:map(map), dt(dt), window(win)
{

}

Piece::~Piece()
{
}

void Piece::updata()
{
}

void Piece::render()
{
}

void Piece::move(Dir dir)
{
}
