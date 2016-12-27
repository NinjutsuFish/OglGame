#pragma once
#include "RawModel.h"
#include "modelTexture.h"
#include "stdafx.h"
#include <string>
class texturedModel
{
public:

	bool operator<(const texturedModel& other) const {
		int thisscore = texture.textureID + model.vaoID;
		int otherscore = other.texture.textureID + other.model.vaoID;
		return (thisscore < otherscore);
	}




	texturedModel() { };
	texturedModel(RawModel mymodel, modelTexture mytexture) { model = mymodel; texture = mytexture; };
	~texturedModel() {};
	RawModel getModel() { return model; }
	modelTexture getTexture() { return texture; }

private:
	RawModel model;
	modelTexture texture;
};

