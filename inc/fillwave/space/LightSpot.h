/*
 * LightSpot.h
 *
 *  Created on: Nov 30, 2014
 *      Author: Filip Wasil
 */

#ifndef LIGHTSPOT_H_
#define LIGHTSPOT_H_

#include <fillwave/space/Light.h>
#include <fillwave/space/CameraPerspective.h>
#include <fillwave/management/TextureManager.h>

namespace fillwave {
namespace space {

/*! \class LightSpot
 * \brief Light implementing directional torch.
 */

class LightSpot: public Light {
protected:
	pCameraPerspective mShadowCamera;
	pTexture2DRenderable mShadowTexture;

public:
	LightSpot(
			pTexture2DRenderable shadowTexture,
			glm::vec3 position,
			glm::quat rotation,
			glm::vec4 intensity,
			pEntity entity = pEntity());

	virtual ~LightSpot() = default;

	pTexture2DRenderable getShadowTexture();

	pCameraPerspective getShadowCamera();

	void updateShadowCamera();

	void log();

};

} /* space */
typedef std::shared_ptr<space::LightSpot> pLightSpot;
} /* fillwave */

#endif /* LIGHTSPOT_H_ */
