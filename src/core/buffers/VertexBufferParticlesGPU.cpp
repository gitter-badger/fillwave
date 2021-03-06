/*
 * VertexBufferParticlesGPU.cpp
 *
 *  Created on: Aug 30, 2014
 *      Author: Filip Wasil
 */

#include <fillwave/core/buffers/VertexBufferParticlesGPU.h>
#include <fillwave/extras/Log.h>

FLOGINIT("VertexBufferParticlesGPU", FERROR | FFATAL)

namespace fillwave {
namespace core {

VertexBufferParticlesGPU::VertexBufferParticlesGPU(
		std::vector<VertexParticleGPU>& particles)
		: VertexBuffer<VertexParticleGPU>(particles, GL_DYNAMIC_COPY) {

}

void VertexBufferParticlesGPU::log() {

}

} /* core */
} /* fillwave */
