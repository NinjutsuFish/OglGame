#pragma once
#include "Loader.h"
#include "texturedModel.h"
#include "RawModel.h"
#include <vector>
class Terrain
{


#define TSIZE 800
#define TVERTEXCOUNT 128
public:
	Terrain();
	Terrain(int gridX, int gridZ, Loader &Gloader, modelTexture &GTexture);
	~Terrain();
	//GETTERS :(
	RawModel getModel() { return model; }
	modelTexture getTexture() { return texture; }
	int getX() { return x; }
	int getZ() { return z; }

private:
	float x;
	float z;
	RawModel model;
	modelTexture texture;
	RawModel generateTerrain(Loader &gloader);

};

