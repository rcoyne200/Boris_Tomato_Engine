#include "Game.h"

SceneManager* Game::sceneManager = SceneManager::GetInstance();

Game::Game()
{

}

Game::~Game()
{

}

void Game::Initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer)
{
	initialised = true;
	sdlWindow = theSDLWND;
	sdlRenderer = theRenderer;
	//ResourceSetup(theRenderer);
}

void Game::Dispose()
{
	// Delete our OpengL context
	SDL_GL_DeleteContext(sdlWindow);

	// Destroy the window
	SDL_DestroyWindow(sdlWindow);

	// Quit IMG system
	IMG_Quit();

	// Shutdown SDL 2
	SDL_Quit();
}

void Game::Run(string startscene)
{
	if (initialised)
	{
		string currentscene = startscene;
		bool loop = true;
		while (sceneManager->GetScene(currentscene))
		{
			Scene* scene = sceneManager->GetScene(currentscene);
			scene->Initialise(sdlRenderer);
			cout << currentscene << " initialised and will run shortly." << endl;
			currentscene = scene->Run();
		}
		cout << "Game has ran out of scenes to run and hence will end." << endl;
	}
}