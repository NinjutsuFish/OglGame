#include "stdafx.h"
#include "MasterRender.h"


MasterRender::MasterRender()
{
	myRender = new Renderer(&shader);

}

void MasterRender::Render(Light &sun, Camera &camera) {
	myRender->prepare();
	shader.start();
	shader.loadLight(sun);
	shader.loadViewMatrix(camera);
	myRender->render(Entities);
	shader.stop();
	Entities.clear();


}

void MasterRender::processEntity(Entity entity) {
	texturedModel gTexModel = entity.getModel();

	std::map<texturedModel, std::vector<Entity > *>::iterator batch;

	std::vector<Entity > *entityList;

	batch = Entities.find(gTexModel);
	if (batch == Entities.end()) {
		// need to add new list
		entityList = new std::vector<Entity >();
		Entities[gTexModel] = entityList;
	}
	else
	{
		entityList = Entities[gTexModel];
	}

	entityList->push_back(entity);

}


	MasterRender::~MasterRender() {
	delete myRender;
	};
