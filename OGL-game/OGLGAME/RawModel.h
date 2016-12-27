#pragma once
#include "GL/glew.h"
class RawModel
{
public:
	RawModel() {
		vaoID = 0;
		vertexCount = 0;
	}

	RawModel(int a, int b) {
		vaoID = a;
		vertexCount = b;
	};

	int getvaoid(){
		return vaoID;
	};
	int getvertexCount() {
		return vertexCount;
	};
	int vaoID;
private:

	int vertexCount;
};

