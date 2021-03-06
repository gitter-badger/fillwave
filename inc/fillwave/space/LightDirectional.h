/*
 * LightDirectional.h
 *
 *  Created on: Nov 30, 2014
 *      Author: filip
 */

#ifndef LIGHTDIRECTIONAL_H_
#define LIGHTDIRECTIONAL_H_

#include <fillwave/space/CameraOrthographic.h>
#include <fillwave/space/Light.h>
#include <fillwave/management/TextureManager.h>

namespace fillwave {
class Engine;
namespace space {

/*! \struct LightDirectioData
 * \brief Light UBO data.
 */

struct LightDirectioData {
	GLfloat position[4];
	GLfloat intensity[4];
	GLfloat mvp[16];
};

/*! \class LightDirectional
 * \brief Light with Orthographic projection.
 */

class LightDirectional: public Light {
public:
	LightDirectional(
			pTexture2DRenderable shadowTexture,
			glm::vec3 position,
			glm::quat rotation,
			glm::vec4 intensity,
			pEntity entity);
	virtual ~LightDirectional() = default;

	pTexture2DRenderable getShadowTexture();

	pCameraOrthographic getShadowCamera();

	void updateShadowCamera();

	void log();

private:
	pCameraOrthographic mShadowCamera;
	pTexture2DRenderable mShadowTexture;
};

} /* space */
typedef std::shared_ptr<space::LightDirectional> pLightDirectional;
} /* fillwave */

#endif /* LIGHTDIRECTIONAL_H_ */
