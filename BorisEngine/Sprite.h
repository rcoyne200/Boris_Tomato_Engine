#ifndef  _SPRITE_H
#define _SPRITE_H

#include<SDL.h>
#include"Texture.h"
#include "TextureManager.h"
#include"Operations.h"
#include"Util.h"
#include "SoundManager.h"

//A struct which represents an onscreen position using an X and Y value.
typedef struct
{
	float  X;
	float  Y;
}Vector2;

//An enumeration which represents the two different types of sprites.
enum SpriteType {BACKGROUND, REGULAR};

class Sprite
{
	public:
		//Constructor, takes a pointer to a "Texture" to be used for its appearance and dimensions.
		Sprite(Texture* _texture);
		//Destructor method.
		~Sprite();
		//A method which renders this sprite.
		void Render();
		//A method which renders this sprite using given source and destination rectangles.
		void Render(SDL_Rect* source, SDL_Rect* dest);
		//A method which renders this sprite using given source and destination rectangles
		//whilst factoring in a rotation.
		void RenderRotated(SDL_Rect* source, SDL_Rect* dest);
		//A method which returns the current location and dimensions of this sprite.
		SDL_Rect GetPosition();
		//A method that sets the current location and dimensions using a given FloatRect value.
		void SetPosition(FloatRect _position);
		//A method that sets the current location and dimensions using given X and Y values.
		void SetPosition(float x, float y);
		//A method which returns the pointer to the "Texture" instance of this class.
		Texture* GetTexture();
		//A method which sets the current texture of this class.
		void SetTexture(Texture* texture);
		//A method which returns the dimensions of this sprite.
		SDL_Rect GetDimensions();
		//A method that sets the dimensions of this sprite using an SDL_Rect value.
		void SetDimensions(SDL_Rect _dimension);
		//A method that sets the dimensions of this sprite using given width and height values.
		void SetDimensions(int width, int height);
		//A method which returns an SDL_Point which represents the centre of this sprite.
		SDL_Point GetCentre();
		//A method which sets the centre of this sprite using an SDL_Point.
		void SetCentre(SDL_Point _centre);
		//A method which returns a Vector2 representing the scale of the sprite.
		Vector2 GetScale();
		//A method which adjusts the scale of the sprite using a Vector2 value.
		void SetScale(Vector2 _scale);
		//A method which adjusts the scale of the sprite using separate X and Y values.
		void SetScale(float x, float y);
		//A method which returns a float representing the current rotation
		//of the sprite.
		float GetRotation();
		//A method which sets the current rotation of the sprite.
		void SetRotation(float _rotation);
		//A method which returns a boolean representing
		//whether or not the sprite is active.
		bool IsActive();
		//A method which sets the current active state
		//depending on the given boolean value.
		void SetActive(bool _active);
		//A method which moves the sprite a certain amount
		//depending on the given Vector2 value.
		void Translate(Vector2 translation);
		//A method which outputs the current position of the sprite.
		void MsgPosition();
		//A method which returns a boolean value which represents
		//whether or not this sprite collides with a given SDL_Rect.
		bool CollidesWith(SDL_Rect* boundary);
		//A method which returns a boolean value which represents
		//whether or not this sprite collides with another one.
		bool CollidesWith(Sprite* sprite);
		//A method which returns a boolean value that represents
		//whether or not the mouse has clicked this sprite using
		//its current position.
		bool Clicked(SDL_Point* mouseposition);
		//A method which sets the current sprite type.
		void SetSpriteType(SpriteType type);
		//A method which returns the current sprite type.
		SpriteType GetSpriteType();
		//A method which sets the scale of the sprite using a Vector2 value.
		void SetAbsoluteScale(Vector2 _scale);
		//A method which sets the scale of the sprite using separate X and Y values.
		void SetAbsoluteScale(float x, float y);
	protected:
		//A pointer to an instance of "TextureManager".
		static TextureManager* texturemanager;
		//A pointer to an instance of "SoundManager".
		static SoundManager* soundmanager;
	private:
		//A value representing the centre of the sprite.
		SDL_Point centre;
		//A value representing the original dimensions of the sprite.
		SDL_Rect dimension;
		//A value representing the scale of the sprite.
		Vector2 scale;
		//A value representing the rotation of the sprite.
		float rotation;
		//A value representing the sprite's texture.
		Texture* texture;
		//A value representing the width of the sprite.
		int width;
		//A value representing the height of the sprite.
		int height;
		//A method which adjusts the size and position of
		//the sprite depending on its scale.
		void ScaleSprite();
		//A boolean which represents whether or not this
		//sprite is active.
		bool active = false;
		//A FloatRect which is used to represent 
		//the position and dimensions of the sprite
		FloatRect position;
		//A value representing the sprite's current type.
		SpriteType sprite_type = REGULAR;
};

#endif // ! _SPRITE_H