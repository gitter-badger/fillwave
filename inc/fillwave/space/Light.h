/*
 * Light.h
 *
 *  Created on: 17 Apr 2014
 *      Author: Filip Wasil
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include <fillwave/core/rendering/Texture2DRenderable.h>
#include <fillwave/models/Entity.h>

namespace fillwave {
namespace space {

#define MAX_LIGHTS       4
#define USED_LIGHT_SLOTS 4
#if(USED_LIGHT_SLOTS > MAX_LIGHTS)
#error "used light slots can not be grater than available lights"
#endif

/*! \struct LighUniformData
 * \brief Light UBO data.
 */

struct LighUniformData {
	GLfloat position[4];
	GLfloat intensity[4];
	GLfloat mvp[16];
};

/*! \struct LightAttenuationData
 * \brief Light attenuation data.
 */
struct LightAttenuationData {
	GLfloat mLinear;
	GLfloat mExp;
};

/*! \class Light
 * \brief Base for all lights.
 */

class Light: public models::Moveable {
public:
	Light(glm::vec3 position, glm::vec4 intensity, pEntity entity = pEntity());
	virtual ~Light() = default;

	void updateEntity();

	/* getAttenuation
	 *
	 * \brief set the light attenuation.
	 *
	 */

	void setAttenuation(LightAttenuationData& attenuation);

	/* setAttenuation
	 *
	 * \brief get the light attenuation.
	 *
	 */

	LightAttenuationData getAttenuation();

	/* setIntensity
	 *
	 * \brief set the light intensity 4x float (R,G,B,A)
	 *
	 */

	void setIntensity(glm::vec4 intensity);

	/* getIntensity
	 *
	 * \brief get the light intensity 4x float (R,G,B,A)
	 *
	 */

	glm::vec4 getIntensity();

	/* setEntity
	 *
	 * \brief set the entity assigned to this light
	 *
	 */

	void setEntity(pEntity entity);

	/* getEntity
	 *
	 * \brief returns the entity assigned to this light
	 *
	 */

	pEntity getEntity();

	/*
	 * log
	 *
	 * \brief log
	 */

	void log();

protected:
	pEntity mEntity;
	glm::vec4 mIntensity;
	LightAttenuationData mAttenuation;
};

} /* space */
typedef std::shared_ptr<space::Light> pLight;
} /* fillwave */

#endif /* LIGHT_H_ */
