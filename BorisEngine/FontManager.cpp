#include "FontManager.h"

FontManager* FontManager::_instance = NULL;

FontManager::FontManager()
{
	if (TTF_Init() != 0)
	{
		cout << "TTF_Init() Failed: " << SDL_GetError() << endl;
	}
}

FontManager::~FontManager()
{

}

FontManager* FontManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new FontManager();
	}
	return _instance;
}

void FontManager::AddFont(string fontname, Font* font)
{
	if (!GetFont(fontname))
	{
		fonts.insert(make_pair(fontname, font));
	}
}

Font* FontManager::GetFont(string fontname)
{
	map<string, Font*>::iterator font = fonts.find(fontname);
	if (font != fonts.end())
	{
		return font->second;
	}
	return NULL;
}