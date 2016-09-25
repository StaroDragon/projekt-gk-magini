#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

/**
*Klasa przechowujaca informacje o perspektywie
*/
class PerspectiveInfo
{


public:
	float FOV;
	float width;
	float height;
	float zNear;
	float zFar;
	PerspectiveInfo()
	{
	}
	PerspectiveInfo(float FOV, float width, float height, float zNear, float zFar)
	{
		this->FOV = FOV;
		this->width = width;
		this->height = height;
		this->zNear = zNear;
		this->zFar = zFar;
	}
};
#endif