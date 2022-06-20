#pragma once

/*
	资源管理类
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <map>

class AssetManager
{
public:
	AssetManager();

	static sf::Texture& GetTexture(std::string const& filename);
	static sf::Font& GetFont(std::string const& filename);
	static sf::SoundBuffer& GetSoundBuffer(std::string const& filename);

private:

	std::map<std::string, sf::Texture> m_Texture;			//存储所有加载的材质信息
	std::map<std::string, sf::Font> m_Font;					//存储所有加载的字体信息
	std::map<std::string, sf::SoundBuffer> m_SoundBuffer;	//存储所有加载的音频信息

	static AssetManager* sInstance;
};