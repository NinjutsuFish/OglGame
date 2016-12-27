#pragma once
#include "Renderer.h"
#include "staticShader.h"
#include "texturedModel.h"
#include "Entity.h"

#include <vector>
#include <map>
class MasterRender

{
public:
	MasterRender();
	~MasterRender();
	void Render(Light &sun, Camera &camera);
	void processEntity(Entity entity);


private:
	staticShader shader;
	Renderer *myRender;
	std::map<texturedModel, std::vector<Entity> *>Entities;
};

