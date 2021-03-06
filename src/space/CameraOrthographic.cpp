/*
 * CameraOrthographic.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: filip
 */

#include <fillwave/space/CameraOrthographic.h>
#include <fillwave/extras/Log.h>

FLOGINIT("CameraOrthographic", FERROR | FFATAL)

namespace fillwave {
namespace space {

CameraOrthographic::CameraOrthographic()
		: Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::quat()) {

	mCullingBox.mProjectionBottom = 10.0f;
	mCullingBox.mProjectionFar = 10.0f;
	mCullingBox.mProjectionLeft = 10.0f;
	mCullingBox.mProjectionNear = 10.0f;
	mCullingBox.mProjectionRight = 10.0f;
	mCullingBox.mProjectionTop = 10.0f;

	updateProjection();
}

CameraOrthographic::CameraOrthographic(
		glm::vec3 position,
		glm::quat rotation,
		GLfloat left,
		GLfloat right,
		GLfloat bottom,
		GLfloat top,
		GLfloat near,
		GLfloat far)
		: Camera(position, rotation) {

	mCullingBox.mProjectionBottom = bottom;
	mCullingBox.mProjectionFar = far;
	mCullingBox.mProjectionLeft = left;
	mCullingBox.mProjectionNear = near;
	mCullingBox.mProjectionRight = right;
	mCullingBox.mProjectionTop = top;

	updateProjection();
}

void CameraOrthographic::updateProjection() {
	mProjectionMatrix = glm::ortho(mCullingBox.mProjectionLeft,
			mCullingBox.mProjectionRight, mCullingBox.mProjectionBottom,
			mCullingBox.mProjectionTop, mCullingBox.mProjectionNear,
			mCullingBox.mProjectionFar);

	mRefreshProjection = GL_FALSE;
}

/*
 * getProjectionNearPlane
 *
 * \brief get the projection near plane distance
 *
 */

GLfloat CameraOrthographic::getProjectionNearPlane() {
	return mCullingBox.mProjectionNear;
}

/*
 * getProjectionFarPlane
 *
 * \brief get the projection far plane distance
 *
 */

GLfloat CameraOrthographic::getProjectionFarPlane() {
	return mCullingBox.mProjectionFar;
}

} /* space */
} /* fillwave */

