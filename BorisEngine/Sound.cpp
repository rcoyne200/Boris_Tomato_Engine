#include "Sound.h"


Sound::Sound(LPCSTR filename, SoundType sound_type)
{
	soundType = sound_type;
	switch (soundType)
	{
		case SFX:
		{
			sound = Mix_LoadWAV(filename);
			if (sound == 0)
			{
				cout << "Sound FX '" << filename << "' could not be loaded. " << SDL_GetError() << endl;
			}
			else
			{
				Mix_VolumeChunk(sound, Util::GetInstance()->GetSFXVolume());
				cout << "Sound FX '" << filename << "' was successfully loaded. " << endl;
			}
		}
		break;
		case MUSIC:
		{
			music = Mix_LoadMUS(filename);
			cout <<Mix_GetError()<< endl;
			if (music == 0)
			{
				cout << "Music '" << filename << "' could not be loaded. " << SDL_GetError() << endl;
			}
			else
			{
				cout << "Music '" << filename << "' was successfully loaded. " << endl;
			}
		}
		break;
		default:
			break;
	}
}

Sound::~Sound()
{

}

SoundType Sound::GetSoundType()
{
	return soundType;
}

void Sound::Play()
{
	switch (soundType)
	{
		case SFX:
		{
			Play(Util::GetInstance()->GetSFXVolume());
		}
		break;
		case MUSIC:
		{
			Play(Util::GetInstance()->GetMusicVolume());
		}
		break;
	}
}

void Sound::Play(int volume)
{
	//SetVolume(volume);
	switch (soundType)
	{
		case SFX:
		{
			if (sound)
			{
				Mix_VolumeChunk(sound, volume);
				Mix_PlayChannel(-1, sound, 0);
			}
		}
		break;
		case MUSIC:
		{
			if (music)
			{
				Mix_VolumeMusic(volume);
				Mix_PlayMusic(music, -1);
			}
		}
		break;
	}
}
//
//int Sound::GetVolume()
//{
//	return _volume;
//}
//
//void Sound::SetVolume(int volume)
//{
//	_volume = volume;
//}