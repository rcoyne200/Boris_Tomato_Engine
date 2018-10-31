#include "Sprite.h"

TextureManager* Sprite::texturemanager = TextureManager::getInstance();
SoundManager* Sprite::soundmanager = SoundManager::GetInstance();

Sprite::Sprite(Texture* _texture)
{
	texture = _texture;
	int textureWidth = texture->getWidth();
	int textureHeight = texture->getHeight();
	SetDimensions(textureWidth, textureHeight);
	SetPosition({ 0,0,(float)textureWidth,(float)textureHeight });
	scale = { 1,1 };
	SetRotation(0);
}

void Sprite::MsgPosition()
{
	cout << "X: " << position.X << " Y: " << position.Y << " W: " << position.W << " H: " << position.H << endl;
}

Sprite::~Sprite()
{

}

//Make the sprite appear in the window at its given position.
void Sprite::Render()
{
	Render(&dimension, &GetPosition());
}

void Sprite::Render(SDL_Rect* source, SDL_Rect* dest)
{
	if (GetSpriteType() == REGULAR)
	{
		texture->Render(source, dest);
	}
	else
	{
		texture->Render(NULL, NULL);
	}
}

void Sprite::RenderRotated(SDL_Rect* source, SDL_Rect* dest)
{
	if (GetSpriteType() == REGULAR)
	{
		texture->Render(source, dest, rotation, &centre);
	}
	else
	{
		texture->Render(NULL, NULL, rotation, &centre);
	}
}

SDL_Rect Sprite::GetPosition()
{
	return Operations::GetSDLRect(position);
}

void Sprite::SetPosition(FloatRect _position)
{
	position = _position;
	centre.x = Operations::Round(position.W / 2);
	centre.y = Operations::Round(position.H / 2);
}

void Sprite::SetPosition(float x, float y)
{
	SetPosition({ x,y,position.W,position.H });
}

Texture* Sprite::GetTexture()
{
	return texture;
}

void Sprite::SetTexture(Texture* _texture)
{
	texture = _texture;
	
	SetDimensions(texture->getWidth(), texture->getHeight());
}

SDL_Rect Sprite::GetDimensions()
{
	return dimension;
}

void Sprite::SetDimensions(SDL_Rect _dimension)
{
	dimension = _dimension;
	width = dimension.w;
	height = dimension.h;
}

void Sprite::SetDimensions(int _width, int _height)
{
	SetDimensions({ 0,0,_width,_height });
}

SDL_Point Sprite::GetCentre()
{
	return centre;
}

void Sprite::SetCentre(SDL_Point _centre)
{
	centre = _centre;
}

Vector2 Sprite::GetScale()
{
	return scale;
}

void Sprite::SetScale(Vector2 _scale)
{
	scale.X *= _scale.X;
	scale.Y *= _scale.Y;
	ScaleSprite();
}

void Sprite::SetScale(float x, float y)
{
	SetScale({ x,y });
}

void Sprite::SetAbsoluteScale(Vector2 _scale)
{
	scale.X = _scale.X;
	scale.Y = _scale.Y;
	ScaleSprite();
}

void Sprite::SetAbsoluteScale(float x, float y)
{
	SetAbsoluteScale({ x,y });
}

float Sprite::GetRotation()
{
	return rotation;
}

void Sprite::SetRotation(float _rotation)
{
	rotation = _rotation;
}

void Sprite::ScaleSprite()
{
	SetPosition({position.X,position.Y,dimension.w*scale.X,dimension.h*scale.Y});
}

bool Sprite::IsActive()
{
	return active;
}

void Sprite::SetActive(bool _active)
{
	active = _active;
}

void Sprite::Translate(Vector2 translation)
{
	SetPosition({( position.X + translation.X),(position.Y + translation.Y),position.W,position.H });
}

bool Sprite::CollidesWith(SDL_Rect* boundary)
{
	return SDL_HasIntersection(&GetPosition(), boundary);
}

bool Sprite::CollidesWith(Sprite* otherSprite)
{
	if (!IsActive() || !otherSprite->IsActive())
	{
		return false;
	}
	return CollidesWith(&Operations::GetExpandedRect(otherSprite->GetPosition(),10));
}
//Left mouse button pressed on the position of the sprite.
bool Sprite::Clicked(SDL_Point* mouseposition)
{
	return IsActive() && SDL_PointInRect(mouseposition, &GetPosition());
}

void Sprite::SetSpriteType(SpriteType type)
{
	sprite_type = type;
}

SpriteType Sprite::GetSpriteType()
{
	return sprite_type;
}