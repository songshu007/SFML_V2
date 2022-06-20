#pragma once

/*
	��Դ������
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

	std::map<std::string, sf::Texture> m_Texture;			//�洢���м��صĲ�����Ϣ
	std::map<std::string, sf::Font> m_Font;					//�洢���м��ص�������Ϣ
	std::map<std::string, sf::SoundBuffer> m_SoundBuffer;	//�洢���м��ص���Ƶ��Ϣ

	static AssetManager* sInstance;
};