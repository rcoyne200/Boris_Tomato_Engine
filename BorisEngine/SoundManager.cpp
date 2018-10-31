#include "SoundManager.h"

SoundManager* SoundManager::_instance = NULL;

SoundManager::SoundManager()
{
	Initialise();
}

bool SoundManager::Initialise()
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		cout << "SDL_Init_AUDIO Failed: " << SDL_GetError() << endl;
		return false;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
	{
		cout << "Mix_OpenAudio Failed: " << SDL_GetError() << endl;
		return false;
	}
	return true;
}

SoundManager::~SoundManager()
{
	DeleteSounds();
	Mix_CloseAudio();
	Mix_Quit();
}

SoundManager* SoundManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new SoundManager();
	}
	return _instance;
}

Sound* SoundManager::GetSound(string soundname)//(LPCSTR soundname)
{
	map<string, Sound*>::iterator sound = sounds.find(soundname);
	//map<LPCSTR, Sound*>::iterator sound = sounds.find(soundname);
	if (sound != sounds.end())
	{
		return sound->second;
	}
	return NULL;
}

void SoundManager::AddSound(string soundname, LPCSTR filename, SoundType soundtype)//(LPCSTR soundname, LPCSTR filename, SoundType soundtype)
{
	if (!GetSound(soundname))
	{
		Sound* newsound = new Sound(filename,soundtype);
		sounds.insert(make_pair(soundname, newsound));
	}
}

void SoundManager::DeleteSounds()
{
	for (map<string, Sound*>::iterator sound = sounds.begin(); sound != sounds.end(); ++sound)//(map<LPCSTR, Sound*>::iterator sound = sounds.begin(); sound != sounds.end(); ++sound)
	{
		delete sound->second;
	}
}