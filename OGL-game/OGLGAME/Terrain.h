#pragma once
class Terrain
{
#define TSIZE 800
#define TVertexCount 128

#include "Loader.h"
#include "modelTexture.h"
#include "RawModel.h"
public:
	Terrain();
	Terrain(int Gridx, int GridZ, Loader &loader, modelTexture &texture);
	~Terrain();

private:
	float x;
	float z;
	RawModel model;
	modelTexture texture;
};

