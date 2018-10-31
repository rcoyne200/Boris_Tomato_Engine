#include "Util.h"

Util* Util::_instance = NULL;

Util::Util()
{
	currentMusic = "";
}

Util::~Util()
{

}

Util* Util::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Util();
	}
	return _instance;
}

void Util::Reset()
{
	_instance = new Util();
	_instance->SetMusicVolume(musicvolume);
	_instance->SetSFXVolume(sfxvolume);
	cout << "Current health is: " << _instance->GetHealth() << endl;
}

void Util::IncreasePoints(int amount)
{
	points += amount;
}

int Util::GetPoints()
{
	return points;
}

int Util::GetSFXVolume()
{
	return sfxvolume;
}

void Util::SetSFXVolume(int volume)
{
	sfxvolume = volume;
	cout << "SFX volume has been set to " << volume << "." << endl;
}

int Util::GetMusicVolume()
{
	return musicvolume;
}

void Util::SetMusicVolume(int volume)
{
	musicvolume = volume;
	Mix_VolumeMusic(volume);
	cout << "Music volume has been set to " << volume << "." << endl;
}

string Util::GetCurrentMusic()
{
	return currentMusic;
}

void Util::SetCurrentMusic(string currentmusic)
{
	currentMusic = currentmusic;
}

void Util::IncreaseHealth(int amount)
{
	health += amount;
	if (health > max_health)
	{
		health = max_health;
	}
	if (health < 0)
	{
		health = 0;
	}
	cout << "Current health is: " << health << endl;
}

int Util::GetHealth()
{
	return health;
}