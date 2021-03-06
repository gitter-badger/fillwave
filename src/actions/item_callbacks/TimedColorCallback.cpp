/*
 * TimedColorCallback.cpp
 *
 *  Created on: 11 lut 2015
 *      Author: filip
 */

#include <fillwave/actions/TimedColorCallback.h>
#include <fillwave/actions/TimeEvent.h>
#include <fillwave/extras/Log.h>

namespace fillwave {
namespace actions {

TimedColorCallback::TimedColorCallback(
		pModel model,
		glm::vec4 endColor,
		GLfloat lifeTime,
		eEasing easing)
		:
				TimedCallback(lifeTime, easing),
				mStartColor(glm::vec4(0.0)),
				mEndColor(endColor),
				mModel(model) {
	mPainter = pPainter(new effects::Painter(mStartColor));
	mModel->addEffect(mPainter);
}

void TimedColorCallback::perform(EventType* event) {
	TimeEventData myData = TimeEvent::getData(event);
	if (getPercentageDone() == 0.0) {
		mPainter->setColor(mStartColor);
	}
	mTimePassed += myData.mTimePassed;
	mPainter->setColor(mStartColor + ease(getPercentageDone()) * mEndColor);
	checkTime(myData.mTimePassed);
	if (mFinished) {
		mModel->removeEffect(mPainter);
	}
}

} /* actions */
} /* fillwave */

