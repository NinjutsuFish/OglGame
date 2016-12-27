#include "stdafx.h"
#include "Terrain.h"


Terrain::Terrain(int gridX, int gridZ, Loader &Gloader, modelTexture &GTexture){
	texture = GTexture;
	x = gridX*TSIZE;
	z = gridZ*TSIZE;
	model = generateTerrain(Gloader);

}
Terrain::Terrain() {

}
RawModel Terrain::generateTerrain(Loader &gloader) {
	int count = TVERTEXCOUNT * TVERTEXCOUNT;
	//define Vectors for coords needed to generate 
	std::vector<float>vertices;
	std::vector<float>Normals;
	std::vector<float>TextureCoords;
	std::vector<GLuint>indices;
	

	//generation llop
	for (int i = 0; i < TVERTEXCOUNT; i++) {
		for (int j = 0; j < TVERTEXCOUNT; j++) {
			vertices.push_back((float)j / ((float)TVERTEXCOUNT - 1)*TSIZE);
			vertices.push_back(0);
			vertices.push_back((float)i / ((float)TVERTEXCOUNT - 1)*TSIZE);
			Normals.push_back(0);
			Normals.push_back(1);
			Normals.push_back(0);
			TextureCoords.push_back((float)j / ((float)TVERTEXCOUNT - 1));
			TextureCoords.push_back((float)i / ((float)TVERTEXCOUNT - 1));
		}//FOR J
	}//FOR I
	for (int gz = 0; gz < TVERTEXCOUNT - 1; gz++) {
		for (int gx = 0; gx < TVERTEXCOUNT - 1; gx++) {
			int topLeft = (gz*TVERTEXCOUNT) + gx;
			int topRight = topLeft + 1;
			int bottomLeft = ((gz + 1)*TVERTEXCOUNT) + gx;
			int bottomRight = bottomLeft + 1;
			indices.push_back(topLeft);
			indices.push_back(bottomLeft);
			indices.push_back(topRight);
			indices.push_back(topRight);
			indices.push_back(bottomLeft);
			indices.push_back(bottomRight);
		}//gx
	}//gz
	return gloader.LoadToVAO2(vertices, indices, TextureCoords, Normals);

}

Terrain::~Terrain()
{
}
