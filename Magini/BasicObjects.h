#ifndef BASICOBJ_H
#define	BASICOBJ_H

#include "Map.h"
#include "GameDefs.h"
#include "Object.h"

class DynamicObject: public Object
{
protected:
	float xv;
	float yv;
	bool canJump;

	bool FloorCollision(float tx, float ty, Map map);
	bool WallCollision(float tx, float ty, Map map);
	bool StaticCollision(Map map);
	bool DynamicCollision();
	
public:


};
#endif //BASICOBJ_H



