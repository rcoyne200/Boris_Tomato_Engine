#include "SceneManager.h"

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

Scene* SceneManager::GetScene(string scenename)
{
	map<string, Scene*>::iterator scene = scenes.find(scenename);
	if (scene != scenes.end())
	{
		return scene->second;
	}
	return NULL;
}

void SceneManager::AddScene(string scenename, Scene* scene)
{
	if (!GetScene(scenename) && scenename != "")
	{
		scenes.insert(make_pair(scenename, scene));
	}
	if (scenename == "")
	{
		cout << "Using an empty string for a scene name is illegal as this would create a runtime error. Please use a substantive name." << endl;
	}
}