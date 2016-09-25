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
	//!Mesh gracza
	Mesh* mesh; 
	//!Kamera
	Camera* camera; 
	//! Informacje o perspektywie
	PerspectiveInfo perspective; 

	//!Pozostaly czas nietykalnosci
	float invuTime; 
	//!Czy gracz jest nietykalny
	bool invu; 
	//!Ilosc punktow zycia gracza
	int hitpoints; 

	//!Jaki jest stan gry (zakonczony/nieudany)
	int gameState; 
	
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
	/**
	*Metoda odpowiedzialna za przetwarzanie zmian i sprawdzanie kolizji gracza.
	*@param map mapa rozgrywyki
	*@param endpoint obiekt punktu koncowego
	*@param enemies wektor przeciwnikow
	*@param deltaTime delta time do zapewnienia niezaleznosci od fps
	*@param textRenderer wyswietlacz tekstu.
	*/
	void ProcessChange(Map map, Object* endpoint, std::vector<Object*> enemies, int deltaTime,TextRenderer *textRenderer);
	Camera GetCamera();
	PerspectiveInfo GetPerspective();
};
#endif //PLAYER_H