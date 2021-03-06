/*
 * Renderable.h
 *
 *  Created on: May 24, 2015
 *      Author: Filip Wasil
 */

#ifndef INC_FILLWAVE_MODELS_RELOADABLE_H_
#define INC_FILLWAVE_MODELS_RELOADABLE_H_

#include <fillwave/core/buffers/VertexArray.h>
#include <fillwave/core/texturing/Sampler.h>

namespace fillwave {
class Engine;
namespace models {

/*! \class Reloadable
 * \brief Encapsulates Renderable objects.
 */

class Reloadable {
public:
	Reloadable(Engine* engine);

	virtual ~Reloadable() = default;

	virtual void initBuffers() = 0;

	virtual void initPipeline() = 0;

	virtual void initUniformsCache() = 0;

	virtual void initVAO() = 0;

	virtual void initVBO() = 0;

	void reload();

protected:
	pVertexArray mVAO;

	pSampler mSampler;
};

} /* models */
} /* fillwave */

#endif /* INC_FILLWAVE_MODELS_RELOADABLE_H_ */
