#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <direct.h>
#include <SFML/Graphics.hpp>

struct set_
{
	int WindowWidth = 600;
	int WindowHeight = 800;
	int BlockWidth = 150;
	int BlockHeight = 150;
	int BlockXnum = 4;
	int BlockYnum = 4;
};

struct color_classic
{
	// 获取方块颜色
	const sf::Color& getTileColor(int score)
	{
		static const sf::Color colors[] = {
			sf::Color(214, 205, 196, 255),		// empty
			sf::Color(238, 228, 218),			// 2^1 == 2
			sf::Color(236, 224, 200),			// 2^2 == 4
			sf::Color(242, 177, 121),			// 2^3 == 8
			sf::Color(245, 149, 99),			// 2^4 == 16
			sf::Color(246, 124, 95),			// 2^5 == 32
			sf::Color(246, 94, 59),				// 2^6 == 64
			sf::Color(237, 207, 114),			// 2^7 == 128
			sf::Color(237, 204, 97),			// 2^8 == 256
			sf::Color(237, 200, 80),			// 2^9 == 512
			sf::Color(237, 197, 63),			// 2^10 == 1024
			sf::Color(237, 194, 46),			// 2^11 == 2048
		};
		return colors[score];
	}
};

struct color_
{
	color_classic classic;	// 经典颜色
};

struct allset_
{
	set_ Set;
	color_ Color;

};

class Setting
{
private:
	allset_ setting;
	
	WCHAR SettingFile[1024];	// 程序配置文件所在位置

	// 向 ini 配置文件写 int 类型的数据
	void WritePrivateProfileInt(LPCWSTR lpAppName, LPCWSTR lpKeyName, int data, LPCWSTR lpFileName);
public:
	Setting(const std::string& file);
	~Setting();
	static const allset_& getSet();
	static void loadIni();
	static void saveIni();
	static Setting* sInstance;
};
