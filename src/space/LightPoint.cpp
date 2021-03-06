/*
 * LightPoint.cpp
 *
 *  Created on: Nov 30, 2014
 *      Author: filip
 */

#include <fillwave/space/LightPoint.h>
#include <fillwave/extras/Log.h>

FLOGINIT("LightPoint", FERROR | FFATAL)

namespace fillwave {
namespace space {

LightPoint::LightPoint(
		pTexture3DRenderable shadowTexture,
		glm::vec3 position,
		glm::vec4 intensity,
		pEntity entity)
		:
				Light(position, intensity, entity),
				mShadowTexture(shadowTexture),
				mEntity(entity),
				mSphere(1.0, 10, 10) {
	mFaceCameras[GL_TEXTURE_CUBE_MAP_POSITIVE_X] = pCameraPerspective(
			new CameraPerspective(position,
					glm::normalize(
							glm::angleAxis(glm::radians(90.0f),
									glm::normalize(glm::vec3(0.0, 1.0, 0.0)))
									* glm::angleAxis(glm::radians(180.0f),
											glm::normalize(glm::vec3(1.0, 0.0, 0.0)))),
					glm::radians(90.0), 1.0, //1440.0/900.0,
					0.1, 1000.0)), mFaceCameras[GL_TEXTURE_CUBE_MAP_NEGATIVE_X] =
			pCameraPerspective(
					new CameraPerspective(position,
							glm::normalize(
									glm::angleAxis(glm::radians(-90.0f),
											glm::normalize(glm::vec3(0.0, 1.0, 0.0)))
											* glm::angleAxis(glm::radians(180.0f),
													glm::normalize(
															glm::vec3(1.0, 0.0, 0.0)))),
							glm::radians(90.0), 1.0, //1440.0/900.0,
							0.1, 1000.0)), mFaceCameras[GL_TEXTURE_CUBE_MAP_POSITIVE_Y] =
			pCameraPerspective(
					new CameraPerspective(position,
							glm::normalize(
									glm::angleAxis(glm::radians(90.0f),
											glm::normalize(glm::vec3(1.0, 0.0, 0.0)))),
							glm::radians(90.0), 1.0, //1440.0/900.0,
							0.1, 1000.0)), mFaceCameras[GL_TEXTURE_CUBE_MAP_NEGATIVE_Y] =
			pCameraPerspective(
					new CameraPerspective(position,
							glm::normalize(
									glm::angleAxis(glm::radians(-90.0f),
											glm::normalize(glm::vec3(1.0, 0.0, 0.0)))),
							glm::radians(90.0), 1.0, //1440.0/900.0,
							0.1, 1000.0)), mFaceCameras[GL_TEXTURE_CUBE_MAP_POSITIVE_Z] =
			pCameraPerspective(
					new CameraPerspective(position,
							glm::normalize(
									glm::angleAxis(glm::radians(180.0f),
											glm::normalize(glm::vec3(0.0, 0.0, 1.0)))),
							glm::radians(90.0), 1.0, //1440.0/900.0,
							0.1, 1000.0)), mFaceCameras[GL_TEXTURE_CUBE_MAP_NEGATIVE_Z] =
			pCameraPerspective(
					new CameraPerspective(position,
							glm::normalize(
									glm::angleAxis(glm::radians(180.0f),
											glm::normalize(glm::vec3(0.0, 1.0, 0.0)))
											* glm::angleAxis(glm::radians(180.0f),
													glm::normalize(
															glm::vec3(0.0, 0.0, 1.0)))),
							glm::radians(90.0), 1.0, //1440.0/900.0,
							0.1, 1000.0));
}

void LightPoint::setEntity(pEntity entity) {
	mEntity = entity;
}

pTexture3DRenderable LightPoint::getShadowTexture() {
	return mShadowTexture;
}

/*
 * getEntity
 * \brief get the entity assigned to this light
 */

pEntity LightPoint::getEntity() {
	return mEntity;
}

pCameraPerspective LightPoint::getShadowCamera(GLenum id) { //xxx this should be a unique pointer
	if (mFaceCameras.count(id) == 1) {
		return mFaceCameras[id];
	} else {
		FLOG_FATAL(
				"Can not get shadow camera. This should never happen. Good bye ...");
		return pCameraPerspective();
	}
}

void LightPoint::updateShadowCamera() {
	if (mEntity) {
		mTranslation = mEntity->getTranslation();
	}
	for (auto it : mFaceCameras) {
		if (it.second->getTranslation() != mTranslation) {
			it.second->moveTo(mTranslation);
			it.second->update();
		}
	}
}

} /* space */
} /* fillwave */
