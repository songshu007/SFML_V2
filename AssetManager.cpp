#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	if (sInstance != nullptr) abort();
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	// 检查是否已经加载过该贴图
	auto& mapText = sInstance->m_Texture;
	auto TextFind = mapText.find(filename);

	if (TextFind == mapText.end()) 
	{
		// 如果没有加载过该贴图，则加载该帖图
		auto& textrue = mapText[filename];	// textrue 为另一个 sf::Texture 的指针
		textrue.loadFromFile(filename);
		return textrue;
	}
	else 
	{
		// 如果加载过该贴图，直接返回
		return TextFind->second;
	}
}
sf::Font& AssetManager::GetFont(std::string const& filename)
{
	// 检查是否已经加载过该字体
	auto& mapText = sInstance->m_Font;
	auto TextFind = mapText.find(filename);

	if (TextFind == mapText.end())
	{
		// 如果没有加载过该字体，则加载该字体
		auto& textrue = mapText[filename];
		textrue.loadFromFile(filename);
		return textrue;
	}
	else
	{
		// 如果加载过该字体，直接返回
		return TextFind->second;
	}
}
sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{
	// 检查是否已经加载过
	auto& mapText = sInstance->m_SoundBuffer;
	auto TextFind = mapText.find(filename);

	if (TextFind == mapText.end())
	{
		// 如果没有加载过，则加载
		auto& textrue = mapText[filename];
		textrue.loadFromFile(filename);
		return textrue;
	}
	else
	{
		// 如果加载过，直接返回
		return TextFind->second;
	}
}
