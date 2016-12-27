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
	void prepare() {
		glClearColor(25.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

private:

	staticShader shader;
	EntityRenderer *myRender;
	std::map<texturedModel, std::vector<Entity> *>Entities;
};

