#include "BasicObjects.h"

bool DynamicObject::StaticCollision(Map map)
{
	if (xv > 0)
	{
		if (WallCollision(x+xv,y,map)) //Prawo
		{

		}
		else
		{
			x += xv;
		}
	}
	else if (xv < 0)
	{
		if (WallCollision(x+xv,y,map)) //Lewo
		{

		}
		else
		{
			x += xv;
		}
	}

	if (yv < 0)
	{
		if (FloorCollision(x,x+yv,map)) //Sufit
		{

		}
		else
		{
			y += yv;
			//yv += grav;
		}

	}
	else
	{
		if (FloorCollision(x,y+yv,map)) //Podloga
		{

		}
		else
		{
			y += yv;
			//yv += grav;
			canJump = false;
		}
	}
	return false;
}
bool DynamicObject::WallCollision(float tx,float ty,Map map)
{
	float fixedY = ty - (width / 2);
	float endY = ty + (width / 2);

	int tileX = static_cast<int> (tx / TILE_WIDTH); // Sprawdzic czy zaokraglanie w dol nie jest zbyt duza przesada.
	int tileY = static_cast<int> (ty / TILE_HEIGHT);

	while (fixedY <= endY)
	{
		if (map.GetTileValue(tileX, tileY) != EMPTY_SPACE)
		{
			return true;
		}
		tileY++;
		fixedY += TILE_HEIGHT;
	}
	return false;
}
bool DynamicObject::FloorCollision(float tx, float ty, Map map)
{
	float fixedX = tx - (height / 2);
	float endX = tx + (height / 2);

	int tileX = static_cast<int> (tx / TILE_WIDTH);
	int tileY = static_cast<int> (ty / TILE_HEIGHT);

	while (fixedX <= endX)
	{
		if (map.GetTileValue(tileX,tileY))
		{
			return true;
		}
		tileX++;
		fixedX += TILE_WIDTH;
	}

	return false;
}