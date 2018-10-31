#include "Scene.h"

FontManager* Scene::fontmanager = FontManager::GetInstance();
TextureManager* Scene::textureManager = TextureManager::getInstance();
SoundManager* Scene::soundManager = SoundManager::GetInstance();

Scene::Scene(string backgroundimagename)
{
	Texture* backTexture = textureManager->GetTexture(backgroundimagename);
	if (backTexture)
	{
		background = AddSprite(backTexture, 0);
		background->SetActive(true);
		background->SetSpriteType(BACKGROUND);
	}
}

Scene::~Scene()
{
	DeleteSprites();
}

Sprite* Scene::AddSprite(Texture* texture, int layer)
{
	Sprite* sprite = new Sprite(texture);
	AddSprite(sprite, layer);
	return sprite;
}

void Scene::AddSprite(Sprite* sprite, int layer)
{
	if (layer > layers - 1)
	{
		layers = layer + 1;
	}
	if (layer < 0)
	{
		layer = 0;
	}
	if (LayerExists(layer))
	{
		GetSpritesOfLayer(layer)->push_back(sprite);
	}
	else
	{
		vector<Sprite*>* spritearray = new vector<Sprite*>();
		spritearray->push_back(sprite);
		layered_sprites.insert(make_pair(layer, spritearray));
	}
}

void Scene::DeleteSprites()
{
	for (map<int, vector<Sprite*>*>::iterator i = layered_sprites.begin(); i != layered_sprites.end(); i++)
	{
		delete i->second;
	}
}

float Scene::GetDeltaTime()
{
	float currentTime = (float)SDL_GetTicks();
	float milliseconds = (currentTime - previousTimeStamp) / 60;
	previousTimeStamp = currentTime;
	return milliseconds;
}

SDL_Renderer* Scene::GetRenderer()
{
	return _renderer;
}

vector<Sprite*>* Scene::GetSpritesOfLayer(int layer)
{
	map<int, vector<Sprite*>*>::iterator i = layered_sprites.find(layer);
	if (i != layered_sprites.end())
	{
		return i->second;
	}
	vector<Sprite*>* empty = new vector<Sprite*>();
	return empty;
}

void Scene::Initialise(SDL_Renderer* renderer)
{
	_renderer = renderer;
	initialised = true;
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(_renderer);
	nextscene = "";
	layered_sprites.clear();
	//DeleteSprites();
	AddSprite(background, 0);
	if (GetMusicName() != Util::GetInstance()->GetCurrentMusic())
	{
		Mix_HaltMusic();
		if (soundManager->GetSound(GetMusicName()))
		{
			Util::GetInstance()->SetCurrentMusic(GetMusicName());
			soundManager->GetSound(GetMusicName())->Play();
		}
	}
}

void Scene::DeleteSprite(Sprite* sprite,int layer)
{
	vector<Sprite*>* sprites = GetSpritesOfLayer(layer);
	for (vector<Sprite*>::iterator i = sprites->begin(); i < sprites->end(); i++)
	{
		if ((*i) == sprite)
		{
			sprites->erase(i);
			break;
		}
	}
}

//int Scene::GetSpriteIteratorIndex(vector<Sprite*>::iterator iter,int layer)
//{
//	vector<Sprite*>* sprites = GetSpritesOfLayer(layer);
//	int index = std::distance(sprites->begin(), iter);
//	if (index < sprites->size())
//	{
//		return index;
//	}
//	return -1;
//}

bool Scene::LayerExists(int layer)
{
	vector<Sprite*>* sprites = GetSpritesOfLayer(layer);
	return sprites->size() > 0;
}

void Scene::Render()
{
	SDL_RenderClear(_renderer);
	for (int layer = 0; layer < layers; layer++)
	{
		vector<Sprite*>* sprites = GetSpritesOfLayer(layer);
		for (vector<Sprite*>::iterator i = sprites->begin(); i < sprites->end(); i++)
		{
			if ((*i)->IsActive())
			{
				(*i)->Render();
			}
		}
	}
	SDL_RenderPresent(_renderer);
}

//Launch the scene
string Scene::Run()
{
	if (initialised)
	{
		bool loop = true;
		while (loop && nextscene == "")
		{
			float elapsedTime = GetDeltaTime();
			//float fps = 1.0f / (elapsedTime / 1000.0f);
			//cout << fps << endl;
			loop = GetInput();
			if (loop)
			{
				Update(elapsedTime);
				Render();
			}
		}
	}
	return nextscene;
}

void Scene::SetNextScene(string scenename)
{
	nextscene = scenename;
}

string Scene::GetMusicName()
{
	return musicName;
}

void Scene::SetMusicName(string musicname)
{
	musicName = musicname;
}