#include "TextureManager.h"

TextureManager* TextureManager::_instance = NULL;


TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	//DeleteTextures();
}

TextureManager* TextureManager::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new TextureManager();
	}
	return _instance;
}

void TextureManager::AddTexture(string textureName,Texture* texture)//(LPCSTR textureName, Texture* texture)
{
	//if (!texture)
	//{
	//	char bitmap[310000];
	//	SDL_RWops* rw = SDL_RWFromMem(bitmap, sizeof(bitmap));
	//	SDL_RWFromMem(
	//	IMG_Load_RW(rw, 4);
	//}
	if (!GetTexture(textureName))
	{
		textureList.insert(make_pair(textureName, texture));
	}
	else
	{
		cout << "Unable to add" << textureName << "because a texture of that name has already been added." << endl;
	}
	cout << "The current texture count is " << Count() << endl;
}

void TextureManager::AddTexture(string textureName, LPCSTR filename)//(LPCSTR textureName, LPCSTR filename)
{
	Texture* texture = new Texture(filename, theSDLRenderer);
	AddTexture(textureName, texture);
	//if (!GetTexture(textureName))
	//{
	//	Texture* texture = new Texture(filename, theSDLRenderer);
	//	textureList.insert(make_pair(textureName, texture));
	//}
	//else
	//{
	//	cout << "Unable to add" << textureName << "because a texture of that name has already been added." << endl;
	//}
}

Texture* TextureManager::GetTexture(string textureName)//(LPCSTR textureName)
{
	map<string, Texture*>::iterator txt = textureList.find(textureName);
	//map<LPCSTR, Texture*>::iterator txt = textureList.find(textureName);
	if (txt != textureList.end())
	{
		return txt->second;
	}
	return NULL;
}

void TextureManager::DeleteTextures()
{
	for (map<string, Texture*>::iterator txt = textureList.begin(); txt != textureList.end(); ++txt)
	//for (map<LPCSTR, Texture*>::iterator txt = textureList.begin(); txt != textureList.end(); ++txt)
	{
		delete txt->second;
	}
}

void TextureManager::SetRenderer(SDL_Renderer* renderer)
{
	theSDLRenderer = renderer;
}

int TextureManager::Count()
{
	return textureList.size();
}