#pragma once
#include "Piece.h"

class PieceBoard
{
private:
	//��Ϸ����
	//��Ϊ���̴�С�Ǹ��� Setting.ini �е����þ����ģ��ǲ�ȷ���ģ�����Ҫ�ö�̬����洢
	std::vector<std::vector<Piece*>>* map;
	sf::RenderWindow& window;
	float& dt;

public:
	PieceBoard(sf::RenderWindow& window, float& dt);
	~PieceBoard();
	void updata();
	void render();

};

