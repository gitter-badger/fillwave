/*
 * FPSCallback.h
 *
 *  Created on: Jan 1, 2015
 *      Author: Filip Wasil
 */

#ifndef FPSCALLBACK_H_
#define FPSCALLBACK_H_

#include <fillwave/actions/EngineCallback.h>
#include <fillwave/actions/TimeEvent.h>
#include <fillwave/actions/Callback.h>
#include <fillwave/models/Text.h>

namespace fillwave {
class Engine;
namespace actions {

/*! \class FPSCallback
 * \brief ItemCallback to display and refresh FPS as a renderable text.
 */

class FPSCallback: public EngineCallback {
public:
	FPSCallback(pText text);
	virtual ~FPSCallback() = default;
	void perform(Engine* engine, EventType* event);

private:
	pText mText;
	GLfloat mTimePassed;
};

} /* actions */
} /* fillwave */

#endif /* FPSCALLBACK_H_ */
