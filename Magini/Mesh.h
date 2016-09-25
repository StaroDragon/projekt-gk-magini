#ifndef MESH_H
#define	MESH_H

#include <map>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include "Texture.h"
#include "Vertex.h"

#define INVALID_OGL_VALUE 0xFFFFFFFF
#define INVALID_MATERIAL 0xFFFFFFFF

/**
*Klasa odpowiedzialna za przechowywanie meshow
*/
class Mesh
{
public:
	/**
	*Konstruktor
	*/
	Mesh();
	/**
	*Destruktor
	*/
	~Mesh();
	/**
	*Metoda odpowiadajaca za ladowanie mesha.
	*@param filename sciezka do modelu
	*/
	bool LoadMesh(const std::string& filename);
	/**
	*Metoda odpowiedzialna za renderowanie mesha.
	*/
	void Render();
private:
	/**
	*Metoda odpowiadajaca za inicjalizowanie modelu poprzez inicjalizowanie kolejnych meshow, ktore sa do niego przypisane.
	*@param pScene zawiera caly model podzielony na aiMeshes (czesc Assimp).
	*@param filename sciezka do modelu.
	*/
	bool InitFromScene(const aiScene* pScene, const std::string& filename);

	/**
	*Metoda inicjalizujaca pojedynczy mesh.
	*@param index indeks mesha podczas inicjalizacji.
	*/
	void InitMesh(unsigned int index, const aiMesh* paiMesh);
	/**
	*Metoda inicjalizujaca teksture mesha.
	*@param pScene zawiera caly model podzielony na aiMeshes (czesc Assimp).
	*@param filename sciezka do modelu.
	*/
	bool InitMaterials(const aiScene* pScene, const std::string& filename);

	void Clear();

	/**
	*Struktura przechowujaca informacje na temat jednego mesha
	*/
	struct MeshEntry {
		MeshEntry();

		~MeshEntry();

		void Init(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

		GLuint VB;
		GLuint IB;
		unsigned int NumIndices;
		unsigned int MaterialIndex;
	};

	std::vector<MeshEntry> m_Entries;
	std::vector<Texture*> m_Textures;

};


#endif //MESH_H