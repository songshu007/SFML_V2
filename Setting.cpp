#include "Setting.h"

Setting* Setting::sInstance = nullptr;

void Setting::WritePrivateProfileInt(LPCWSTR lpAppName, LPCWSTR lpKeyName, int data, LPCWSTR lpFileName)
{
	auto b = std::to_wstring(data);
	auto c = b.c_str();
	WritePrivateProfileString(lpAppName, lpKeyName, c, lpFileName);
}

Setting::Setting(const std::string& file)
{
	if (sInstance != nullptr) abort();
	sInstance = this;

	CHAR buffer[1024];
	GetModuleFileNameA(NULL, buffer, 1024);	// 获取当前程序路径
	size_t i = strlen(buffer);
	while (buffer[i] != '\\') {
		i--;
	}
	buffer[i + 1] = 0;
	strcat_s(buffer, file.c_str());
	memset(this->SettingFile, 0, sizeof(this->SettingFile));
	MultiByteToWideChar(CP_ACP, 0, buffer, (int)strlen(buffer) + 1, this->SettingFile,
		sizeof(this->SettingFile) / sizeof(this->SettingFile[0]));

}

Setting::~Setting()
{
}

const allset_& Setting::getSet()
{
	return sInstance->setting;
}

void Setting::loadIni()
{
	sInstance->setting.Set.WindowWidth = GetPrivateProfileInt(L"Setting", L"Window_Width", 600, sInstance->SettingFile);
	sInstance->setting.Set.WindowHeight = GetPrivateProfileInt(L"Setting", L"Window_Height", 800, sInstance->SettingFile);
	sInstance->setting.Set.BlockWidth = GetPrivateProfileInt(L"Setting", L"Block_Size", 150, sInstance->SettingFile);
	sInstance->setting.Set.BlockHeight = GetPrivateProfileInt(L"Setting", L"Block_Size", 150, sInstance->SettingFile);
	sInstance->setting.Set.BlockXnum = GetPrivateProfileInt(L"Setting", L"Block_Num", 4, sInstance->SettingFile);
	sInstance->setting.Set.BlockYnum = GetPrivateProfileInt(L"Setting", L"Block_Num", 4, sInstance->SettingFile);
}

void Setting::saveIni()
{
	sInstance->WritePrivateProfileInt(L"Setting", L"Window_Width", sInstance->setting.Set.WindowWidth, sInstance->SettingFile);
	sInstance->WritePrivateProfileInt(L"Setting", L"Window_Height", sInstance->setting.Set.WindowHeight, sInstance->SettingFile);
	sInstance->WritePrivateProfileInt(L"Setting", L"Block_Size", sInstance->setting.Set.BlockWidth, sInstance->SettingFile);
	sInstance->WritePrivateProfileInt(L"Setting", L"Block_Num", sInstance->setting.Set.BlockXnum, sInstance->SettingFile);
}
