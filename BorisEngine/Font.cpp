#include "Font.h"

Font::Font(LPCSTR filename, int fontSize,SDL_Renderer* _renderer) : Font(filename,fontSize,_renderer,{0,0,0,0},{255,255,255,255})
{

}

Font::Font(LPCSTR filename, int fontSize, SDL_Renderer* _renderer, SDL_Color text_colour, SDL_Color background_colour)
{
	renderer = _renderer;
	ttfFont = TTF_OpenFont(filename, fontSize);
	textColour = text_colour;
	backgroundColour = background_colour;
	if (!ttfFont)
	{
		ttfFont = {};
		cout << " Failed to load \""<<filename<<"\" font : " << SDL_GetError() << endl;
		//delete ttfFont;
	}
}

Font::~Font()
{
	delete ttfFont;
}

TTF_Font* Font::GetFont()
{
	return ttfFont;
}

Texture* Font::CreateTextTexture(LPCSTR text, TextType text_type)//, SDL_Color text_colour, SDL_Color background_colour)
{
	SDL_Surface* surface = NULL;
	if (ttfFont)
	{
		switch (text_type)
		{
			case SOLID:
				surface = TTF_RenderText_Solid(ttfFont, text, textColour);
				break;
			case BLENDED:
				surface = TTF_RenderText_Blended(ttfFont, text, textColour);
				break;
			case SHADED:
				surface = TTF_RenderText_Shaded(ttfFont, text, textColour, backgroundColour);
				break;
			default:
				break;
		}
		SDL_Texture* sdltexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		return new Texture(sdltexture, renderer);
	}
	return Texture::NANTexture(renderer);
}