#ifndef MAP_H
#define	MAP_H

#include <glm/glm.hpp>
#include <vector>
#include <string>
#include "Object.h"
#include "GameDefs.h"
#include "StaticObject.h"
#include "Shader.h"

/**
*Klasa odpowiedzialna za przechowywanie informacji o mapie
*/
class Map
{
private:
	
	int **tile;//!Dwuwymiarowa tablica dynamiczna przechowujaca informacje o budowie mapy
	int mapWidth;//!Szerokosc mapy
	int mapHeight;//!Wysokosc mapy
	std::vector<Object*> staticObjects; //! Wektor przechowujacy informacje o obiektach statycznych
	/**
	*Metoda odpowiedzialna za zczytywanie pozycji obiektow dynamicznych z pliku i konwertowanie ich na obiekty w programie z odpowiednia pozycja.
	*@param[out] player zwracany obiekt gracza.
	*@param[out] endpoint zwracany punkt koncowy mapy.
	*@param[out] enemies zwracany wektor wypelniony wrogami znajdujacymi sie na mapie.
	*/
	void CreateMapObjects(Object* player, Object* endpoint, std::vector<Object*> &enemies);
public:
	~Map();
	/**
	*Metoda odpowiedzialna za ladowanie mapy z pliku tekstowego.
	*@param filename sciezka do pliku mapy.
	*@param player przekazywany do CreateMapObjects wskaznik dla obiektu gracza.
	*@param endpoint przekazywany do CreateMapObjects wskaznik dla obiektu punktu koncowego
	*@param enemies przekazywany do CreateMapObject wektor z przeciwnikami.
	*/
	bool LoadMap(std::string filename, Object* player, Object* endpoint, std::vector<Object*> &enemies);
	/**
	*Metoda odpowiedzialna za renderowanie wszystkich obiektow statycznych na mapie.
	*@param shaders wektor przechowujacy shadery.
	*@param VP macierz widoku i projekcji potrzebna do rendera
	*/
	void RenderMap(std::vector<Shader*> shaders, glm::mat4 VP);
	int GetTileValue(int x, int y);
	std::vector<Object*> GetObjects()
	{
		return staticObjects;
	}
};
#endif //MAP_H