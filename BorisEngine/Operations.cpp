#include "Operations.h"
#include<iostream>

vector<LPCSTR> Operations::numbers()
{
	vector<LPCSTR> returner;
	returner.push_back("0");
	returner.push_back("1");
	returner.push_back("2");
	returner.push_back("3");
	returner.push_back("4");
	returner.push_back("5");
	returner.push_back("6");
	returner.push_back("7");
	returner.push_back("8");
	returner.push_back("9");
	return returner;
}

LPCSTR Operations::Char_to_LPCSTR(char c)
{
	std::ostringstream ss;
	ss << c;
	return _strdup(ss.str().c_str());
}

//http://www.cplusplus.com/forum/beginner/4967/
string Operations::CharToString(char c)
{
	string str;
	stringstream ss;
	ss << c;
	ss >> str;
	return str;
}

void Operations::CreateFolder(string dirname)
{
	if (!FileExists(dirname))
	{
		if (CreateDirectory(String_to_LPCSTR(dirname), NULL))
		{
			cout << "\"" << dirname << "\" was just created ^_^" << endl;
		}
		else
		{
			cout << "Failed to create \"" << dirname << "\" for some reason :/" << endl;
		}
	}
	else
	{
		cout << "\"" << dirname << "\" already exists" << endl;
	}
}

//https://stackoverflow.com/questions/4316442/stdofstream-check-if-file-exists-before-writing
bool Operations::FileExists(const std::string& filename)
{
	struct stat buf;
	return stat(filename.c_str(), &buf) != -1;
}

SDL_Rect Operations::GetExpandedRect(SDL_Rect rect, int expansion)
{
	return { rect.x - expansion, rect.y - expansion, rect.w + (2 * expansion),rect.h + (4 * expansion) };
}

FloatRect Operations::GetFloatRect(SDL_Rect sdlRect)
{
	return { (float)sdlRect.x,(float)sdlRect.y,(float)sdlRect.w,(float)sdlRect.h };
}

SDL_Rect Operations::GetSDLRect(FloatRect frect)
{
	return {Round(frect.X),Round(frect.Y),Round(frect.W),Round(frect.H)};
}

LPCSTR Operations::Int_to_LPCSTR(int num)
{
	vector<LPCSTR> nums = numbers();
	if (num < 10 && num > -1)
	{
		return nums.at(num);
	}
	cout << num << " isn't between 0 and 9. Needs to be between or equal to these numbers to be valid." << endl;
	return "0";
	//char buffer[20];
	//_itoa_s(num, buffer, 20, 2);
	//LPCSTR p = buffer;
	//return p;
	//#ifdef UNICODE
	//	typedef std::wostringstream tstringstream;
	//#else
	//	typedef std::ostringstream tstringstream;
	//#endif
	//
	//	int volumeLevel = 6;
	//	tstringstream stros;
	//	stros << volumeLevel;
	//	return stros.str().c_str();
}

string Operations::PadNumber(int num, int idealSize)
{
	string strnumber = to_string(num);

	while (strnumber.size() < (decltype(strnumber.size()))idealSize)
	{
		strnumber = "0" + strnumber;
	}
	return strnumber;
}

int Operations::RandomNumber(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int Operations::Round(float value)
{
	return (int)ceil(value);
}

LPCSTR Operations::String_to_LPCSTR(string str)
{
	std::ostringstream ss;
	ss << str;
	return _strdup(ss.str().c_str());
}

void Operations::WaitForMusicToStop()
{
	int num = 0;
	Mix_HaltMusic();
	while (Mix_Playing(-1) != 0)
	{
		num++;
		cout << "Waiting for music to finish. Messaged " << num << " times." << endl;
		if (num > 200)
		{
			break;
		}
	}
}