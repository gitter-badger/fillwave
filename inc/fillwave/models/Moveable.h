/*
 * Moveable.h
 *
 *  Created on: Jun 2, 2014
 *      Author: Filip Wasil
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_

#include <fillwave/OpenGL.h>
#include <fillwave/Math.h>

namespace fillwave {
namespace models {

/*! \class Moveable
 * \brief Base for every object which has a 3D position.
 */

class Moveable {
public:
	Moveable(glm::vec3 translation = glm::vec3(0.0), glm::quat rotation =
			glm::quat(1.0, 0.0, 0.0, 0.0));
	virtual ~Moveable() = default;

	void moveTo(glm::vec3 coordinates);
	void moveToX(GLfloat distance);
	void moveToY(GLfloat distance);
	void moveToZ(GLfloat distance);
	void moveBy(glm::vec3 coordinates);
	void moveByX(GLfloat distance);
	void moveByY(GLfloat distance);
	void moveByZ(GLfloat distance);
	void moveInDirection(glm::vec3 direction);
	glm::vec3 getTranslation();

	void scaleTo(GLfloat scale);
	void scaleTo(glm::vec3 scale);
	void scaleToX(GLfloat scale);
	void scaleToY(GLfloat scale);
	void scaleToZ(GLfloat scale);
	glm::vec3 getScale();

	void rotateTo(glm::quat rotation);
	void rotateTo(const glm::vec3 &axis, GLfloat angle);
	void rotateBy(const glm::vec3 &axis, GLfloat angle);
	void rotateByX(float angle);
	void rotateByY(float angle);
	void rotateByZ(float angle);
	glm::quat getRotation();

	void updateMatrixCache();

	GLboolean isRefresh();
	void resetRefresh();

protected:
	glm::fvec3 mTranslation;
	glm::quat mRotation;
	glm::vec3 mScale;
	glm::mat4 mModelMatrixCache;

	/* Refresh should be always set by us, but reset by the others */
	GLboolean mRefresh;
};

} /* models */
} /* fillwave */

#endif /* MOVEABLE_H_ */
