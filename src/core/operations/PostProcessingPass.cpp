/*
 * PostProcessingPass.cpp
 *
 *  Created on: 4 mar 2015
 *      Author: filip
 */

#include <fillwave/core/operations/PostProcessingPass.h>

namespace fillwave {
namespace common {

PostProcessingPass::PostProcessingPass(
		pProgram program,
		GLuint width,
		GLuint height,
		pTexture2DRenderableDynamic frame,
		GLfloat lifetime)
		: Finishable(lifetime), mFrame(frame), mProgram(program) {
}

pTexture2DRenderableDynamic PostProcessingPass::getFrame() const {
	return mFrame;
}

pProgram PostProcessingPass::getProgram() const {
	return mProgram;
}

} /* common */
} /* fillwave */
