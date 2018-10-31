// Windows & SDL 
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <SDL.h>
// Image Texture loading library
#include <SDL_image.h>
// Font loading library
#include <SDL_ttf.h>

// STL Container & Algorithms
#include <vector>
#include <map>
#include <algorithm>

#include"Texture.h"

#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

//Create a class used to store pointers to instances of "Texture" so that they can be easily accessed when necessary.
class TextureManager
{
	public:
		//A method which returns a pointer to the only
		//instance of this class.
		static TextureManager* getInstance();
		//A method which adds a texture by loading one from
		//a given file path.
		void AddTexture(string texturename, LPCSTR theFilename);
		//A method which adds a given texture.
		void AddTexture(string texturename, Texture* texture);
		//A method which returns a pointer to an instance
		//of "Texture" depending on the given name.
		Texture* GetTexture(string textureName);
		//A method which deletes all stored textures.
		void DeleteTextures();
		//A method which sets the sdl renderer.
		void SetRenderer(SDL_Renderer* renderer);
		//A method which returns the amount of textures
		//that have been stored.
		int Count();
	private:
		//Constructor, private so that an instance can't be
		//created outside of this class.
		TextureManager();
		//Destructor method.
		~TextureManager();
		//A pointer to the only instance of this class.
		static TextureManager* _instance;
		//A map which uses strings (texture names) as keys
		//and pointers to instances of "Texture" as values.
		map<string, Texture*> textureList;
		//The sdl renderer.
		SDL_Renderer* theSDLRenderer;
};

#endif