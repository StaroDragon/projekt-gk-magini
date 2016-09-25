#include <fstream>
#include "Map.h"
#include "Player.h"
#include "Spikes.h"


void Map::RenderMap(std::vector<Shader*> shaders, glm::mat4 VP)
{
	for (int i = 0; i < staticObjects.size(); i++)
	{
		staticObjects[i]->Render(shaders,VP);
	}
}

bool Map::LoadMap(std::string filename, Object* player, Object* endpoint, std::vector<Object*> &enemies)
{
	mapWidth = -1;
	mapHeight = -1;
	std::fstream file;
	file.open(filename);
	if (file.is_open())
	{
		file >> mapWidth;
		file >> mapHeight;
		tile = new int*[mapWidth];
		for (int i = 0; i < mapWidth; i++)
		{
			tile[i] = new int[mapHeight];
		}
		for (int i = mapHeight-1; i>=0; i--)
		{
			for (int j = 0; j < mapWidth; j++)
			{
				file >> tile[j][i];
			}
		}
		file.close();
		CreateMapObjects(player,endpoint,enemies);
		return true;
	}
	else
	{
		return false;
	}
	
}

int Map::GetTileValue(int x, int y)
{
	return tile[x][y];
}

void Map::CreateMapObjects(Object* player, Object* endpoint, std::vector<Object*> &enemies)
{
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			switch (tile[i][j])
			{
			case EMPTY_SPACE:
				break;
			case BASIC_TILE:
				staticObjects.push_back(new BasicTile(i*TILE_WIDTH, j*TILE_HEIGHT, TILE_DEPTH));
				break;
			case PLAYER:
				player->ChangePosition(i*TILE_WIDTH, j*TILE_HEIGHT, TILE_DEPTH); // Stworzyc obiekt gracza i przypisac do przekazywanego parametru
				tile[i][j] = EMPTY_SPACE; // Usuniecie twardo przypisanej pozycji gracza z mapy.
				break;
			case ENDPOINT:
				endpoint->ChangePosition(i*TILE_WIDTH, j*TILE_HEIGHT, TILE_DEPTH);
				tile[i][j] = EMPTY_SPACE;
				break;
			case SPIKES:
				Spikes* tSpikes = new Spikes(i*TILE_WIDTH, j*TILE_HEIGHT, TILE_DEPTH);
				enemies.push_back(tSpikes);
				tile[i][j] = EMPTY_SPACE;
				break;
			}
		}
	}
}

Map::~Map()
{

}