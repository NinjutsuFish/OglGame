#include "stdafx.h"
#include"Renderer.h"



Renderer::Renderer(staticShader * shader)
{
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	localShader = shader;
	createProjectionMatrix();
	shader -> start();
	
	shader -> loadprojectionMatrix(projectionMatrix);
	shader -> stop();
}
/*
void Renderer::renderOld(Entity myEntity, staticShader * Shader,Camera camera) {
	texturedModel model = myEntity.getModel();
	RawModel modelraw = model.getModel();
	modelTexture bob = model.getTexture();
	glBindVertexArray(modelraw.getvaoid());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glm::mat4 Matrix = Math::CreateTransformationMatrix(myEntity.getPos(),myEntity.getRotx(), myEntity.getRoty(), myEntity.getRotz(),myEntity.getScale());
	
	Shader->loadTransformationMatrix(Matrix);
	
	Shader->loadShineVariales(bob.getShineDamper(), bob.getReflectivity());
	Shader->loadViewMatrix(camera);
	//std::cout << "Damper :" << ModelT.getShineDamper() << "  Reflecitivty:" << ModelT.getReflectivity() << std::endl;

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getTexture().getID());
	
	glDrawElements(GL_TRIANGLES, modelraw.getvertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	
}
 Old Render Method
 */
void Renderer::createProjectionMatrix(){
	projectionMatrix = glm::perspectiveFov((float)FOV,// FOV
		(float)ScreenWidth,
		(float)ScreenHeight,
		(float)NEAR_PLANE,
		(float)FAR_PLANE);
	
}

void Renderer::preparedTexturedModel(texturedModel model){
	RawModel modelraw = model.getModel();
	modelTexture bob = model.getTexture();
	glBindVertexArray(modelraw.getvaoid());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	localShader->loadShineVariales(bob.getShineDamper(), bob.getReflectivity());
	

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model.getTexture().getID());


}

void Renderer::render(std::map<texturedModel, std::vector<Entity> *> entities) {
	for (std::map<texturedModel, std::vector<Entity>*>::iterator ii = entities.begin(); ii != entities.end(); ++ii) {
		texturedModel gmodel = (*ii).first;
		preparedTexturedModel(gmodel);
		std::vector<Entity>* batch = (*ii).second;
		for (int i = 0; i < batch->size(); i++) {
			prepareInstance(batch->at(i));
		
			glDrawElements(GL_TRIANGLES, gmodel.getModel().getvertexCount(), GL_UNSIGNED_INT, 0);
		}
		unbindTexturedModel();

	}

}

void Renderer::unbindTexturedModel(){
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);

}
void Renderer::prepareInstance(Entity entity){
	glm::mat4 Matrix = Math::CreateTransformationMatrix(entity.getPos(), entity.getRotx(), entity.getRoty(), entity.getRotz(), entity.getScale());

	localShader->loadTransformationMatrix(Matrix);

}

Renderer::~Renderer()
{
}
