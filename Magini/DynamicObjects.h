#ifndef DYNAMICOBJ_H
#define	DYNAMICOBJ_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"
#include "MainShader.h"
#include "Map.h"
#include "GameDefs.h"
#include "Object.h"


/**
*Klasa abstrakcyjna przeznaczona dla wszystkich obiektow dynamicznych. Definiuje dla nich podstawowe operacje
*/
class DynamicObject: public Object
{
protected:
	float xv;//!Predkosc pozioma
	float yv;//!Predkosc pionowa
	int direction;//!Zwrot

	bool canJump;//!Czy obiekt potrafi podskoczyc
	bool walking;//!Czy obiekt znajduje sie obecnie w ruchu

	/**
	*Metoda do wykrywania kolizji z obiektami statycznymi
	*@param object z ktorym sprawdzana zostaje kolizja
	*@param[out] rightCol, leftCol, upCol, downCol referencje przechowywujace informacje o kolizjach z danym kierunkiem
	*/
	bool StaticCollision(Object* object, Object* &rightCol, Object* &leftCol, Object* &upCol, Object* &downCol);

	/**
	*Metoda do sprawdzania kolizji dynamicznych
	*/
	bool DynamicCollision(Object* object);
	bool DynamicCollision(Object* object, float x, float y, float z);
	bool DynamicCollision(Object* object, float x, float xMax, float y, float yMax, float z, float zMax);
	/**
	*Metoda sluzaca w debuggowaniu, wyswietla prostokat kolizyjny. Nie jest wybitnie przetestowana i moze zle dzialac.
	*/
	void DrawBox(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, std::vector<Shader*> shaders, glm::mat4 VP);
	
public:
	/**
	*Metoda do wykonania ruchu w prawo
	*/
	void MoveRight();
	/**
	*Metoda do wykonania ruchu w lewo
	*/
	void MoveLeft();
	/**
	*Metoda do wykonania skoku
	*/
	void Jump();
	/**
	*Metoda do zatrzymania obiektu.
	*/
	void Stop();
	/**
	*Metoda wirtualna do przetwarzania zmian w klatkach
	*@param map mapa gry
	*@param deltaTime delta time uzywany do redukcji zaleznosci od ilosci klatek na sekunde.
	*/
	virtual void ProcessChange(Map map, int deltaTime);


};
#endif //DYNAMICOBJ_H

