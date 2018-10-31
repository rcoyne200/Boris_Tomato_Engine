#ifndef _Operations_H
#define _Operations_H

#include <cstring>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>
#include <map>
#include <algorithm>
#include<string>

using namespace std;

//A struct representing a rectangle using float values for X,Y, Width, and Height.
typedef struct
{
	float X;
	float Y;
	float W;
	float H;
}FloatRect;

//A class used to contain a bunch of miscellaneous subroutines.
class Operations
{
	public:
		//Get an SDL_Rect value from a given FloatRect value.
		static SDL_Rect GetSDLRect(FloatRect frect);
		//A method which rounds a float value and returns the resulting integer.
		static int Round(float value);
		//Get a FloatRect value from a given SDL_Rect value.
		static FloatRect GetFloatRect(SDL_Rect sdlRect);
		//A method which returns a random number between the two given values.
		static int RandomNumber(int min, int max);
		//A method which returns an SDL_Rect which has been augmented by a given amount.
		static SDL_Rect GetExpandedRect(SDL_Rect rect, int expansion);
		//A method which returns a string representing a given number
		//padded with 0s to show a given amount of digits.
		static string PadNumber(int num, int idealsize);
		//A method which returns an LPCSTR value representing a given integer.
		static LPCSTR Int_to_LPCSTR(int num);
		//A method which returns an LPCSTR value representing a string.
		static LPCSTR String_to_LPCSTR(string str);
		//A method which returns an LPCSTR value representing a character.
		static LPCSTR Char_to_LPCSTR(char c);
		//A method which returns a boolean representing
		//whether or not a given file path exists.
		static bool FileExists(const string &filename);
		//A method which returns a string representing a character.
		static string CharToString(char c);
		//A method which loops until there is no audio playing on
		//any sdl audio channels.
		static void WaitForMusicToStop();
		//A method which creates a given directory if
		//it doesn't already exist.
		static void CreateFolder(string dirname);
	private:
		//An array containing LPCSTR values representing
		//the digits 0-9.
		static vector<LPCSTR> numbers();
};

#endif