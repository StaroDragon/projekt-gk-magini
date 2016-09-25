#ifndef PLAYER_H
#define	PLAYER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"
#include "Mesh.h"
#include "DynamicObjects.h"
#include "TextRenderer.h"
#include "Camera.h"
#include "Map.h"
#include "Perspective.h"

/**
*Klasa gracza
*/
class Player :public DynamicObject
{
private:
	Mesh* mesh; //!Mesh gracza
	Camera* camera; //! Kamera
	PerspectiveInfo perspective; //! Informacje o perspektywie

	float invuTime; //!Pozostaly czas nietykalnosci
	bool invu; //!Czy gracz jest nietykalny
	int hitpoints; //!Ilosc punktow zycia gracza

	int gameState; //!Jaki jest stan gry (zakonczony/nieudany)
	
	/**
	*Metoda ktora koryguje kamere do pozycji gracza
	*/
	void AdjustCamera();

	/**
	*Metoda wyswietlajaca UI
	*/
	void DisplayUI(TextRenderer *textRenderer); 


public:
	Player();
	Player(float x, float y, float z);
	~Player();
	void Render(std::vector<Shader*> shaders, glm::mat4 VP);
	void ChangePosition(float x, float y, float z);
	void ProcessChange(Map map, Object* endpoint, std::vector<Object*> enemies, int deltaTime,TextRenderer *textRenderer);
	Camera GetCamera();
	PerspectiveInfo GetPerspective();
};
#endif //PLAYER_H