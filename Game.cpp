#include "Game.h"

void Game::initWindow()
{
	Setting::loadIni();
	this->dt = 0.f;
	this->window.create(sf::VideoMode(Setting::getSet().Set.WindowWidth, Setting::getSet().Set.WindowHeight), "2048", sf::Style::Default);
	this->pieceBoard = new PieceBoard(this->window, this->dt);
}

void Game::updata()
{
	this->dt = this->clock.restart().asSeconds();
	this->checkSFMLEvent();

}

void Game::render()
{
	this->window.clear(sf::Color::Black);

	this->window.display();
}

void Game::checkSFMLEvent()
{
	while (this->window.pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
		{
			this->window.close();
		}break;
		case sf::Event::KeyPressed:
		{

		}break;

		default:
			break;
		}
	}
}

Game::Game()
{
	this->initWindow();
	
}

Game::~Game()
{
	Setting::saveIni();
}

void Game::run()
{
	while (this->window.isOpen())
	{
		this->updata();
		this->render();
	}
}
