/*
 * TimedRotateCallback.h
 *
 *  Created on: 13 May 2014
 *      Author: Filip Wasil
 */

#ifndef ROTATECALLBACK_H_
#define ROTATECALLBACK_H_

#include <fillwave/actions/TimedCallback.h>
#include <fillwave/models/Entity.h>

namespace fillwave {
namespace actions {

/*! \class TimedRotateCallback
 * \brief TimedCallback to rotate Entity at certain angle in certain time.
 */

class TimedRotateCallback: public TimedCallback {
public:
	TimedRotateCallback(
			pEntity entity,
			glm::vec3 axis,
			GLfloat angle,
			GLfloat lifeTime,
			eEasing easing = eEasing::None);

	virtual ~TimedRotateCallback() = default;

	/*	perform
	 * \brief Performs ItemCallback action
	 */

	void performTime(TimeEventData& data);

protected:
	pEntity mEntity;

private:
	glm::quat mStartRotation;
	GLfloat mStartAngle;
	GLfloat mEndAngle;
	glm::vec3 mAxis;
};

} /* actions */
} /* fillwave */

#endif /* ROTATECALLBACK_H_ */
