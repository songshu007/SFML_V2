#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	if (sInstance != nullptr) abort();
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	// ����Ƿ��Ѿ����ع�����ͼ
	auto& mapText = sInstance->m_Texture;
	auto TextFind = mapText.find(filename);

	if (TextFind == mapText.end()) 
	{
		// ���û�м��ع�����ͼ������ظ���ͼ
		auto& textrue = mapText[filename];	// textrue Ϊ��һ�� sf::Texture ��ָ��
		textrue.loadFromFile(filename);
		return textrue;
	}
	else 
	{
		// ������ع�����ͼ��ֱ�ӷ���
		return TextFind->second;
	}
}
sf::Font& AssetManager::GetFont(std::string const& filename)
{
	// ����Ƿ��Ѿ����ع�������
	auto& mapText = sInstance->m_Font;
	auto TextFind = mapText.find(filename);

	if (TextFind == mapText.end())
	{
		// ���û�м��ع������壬����ظ�����
		auto& textrue = mapText[filename];
		textrue.loadFromFile(filename);
		return textrue;
	}
	else
	{
		// ������ع������壬ֱ�ӷ���
		return TextFind->second;
	}
}
sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{
	// ����Ƿ��Ѿ����ع�
	auto& mapText = sInstance->m_SoundBuffer;
	auto TextFind = mapText.find(filename);

	if (TextFind == mapText.end())
	{
		// ���û�м��ع��������
		auto& textrue = mapText[filename];
		textrue.loadFromFile(filename);
		return textrue;
	}
	else
	{
		// ������ع���ֱ�ӷ���
		return TextFind->second;
	}
}
