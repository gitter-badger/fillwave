/*
 * TimedEmiterUpdateCallback.cpp
 *
 *  Created on: Nov 9, 2014
 *      Author: filip
 */

#include <fillwave/actions/TimedEmiterUpdateCallback.h>
#include <fillwave/actions/TimeEvent.h>
#include <fillwave/extras/Log.h>

namespace fillwave {
namespace actions {

TimedEmiterUpdateCallback::TimedEmiterUpdateCallback(
		pEmiterPoint emiter,
		GLfloat timeToFinish,
		eEasing easing)
		: TimedCallback(timeToFinish, easing), mTimePassed(0.0), mEmiter(emiter) {

}

void TimedEmiterUpdateCallback::performTime(TimeEventData& data) {
	mTimePassed += data.mTimePassed;
	mEmiter->update(mTimePassed);
}

} /* actions */
} /* fillwave */
