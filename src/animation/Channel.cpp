/*
 * Channel.cpp
 *
 *  Created on: Jul 10, 2014
 *      Author: filip
 */

#include <fillwave/animation/Channel.h>

#include <fillwave/extras/Conversion.h>

#include <fillwave/extras/Log.h>

FLOGINIT("Channel", FERROR | FFATAL)

namespace fillwave {
namespace animation {

Channel::Channel(fNodeAnim* assimpChannel) {
	mAffectedNodeName = assimpChannel->mNodeName.C_Str();

	for (int i = 0; i < assimpChannel->mNumPositionKeys; i++) {
		Key<glm::vec3> keyTranslation(assimpChannel->mPositionKeys[i].mTime,
				assimpToGlmVec3(assimpChannel->mPositionKeys[i].mValue));
		mKeysTranslation.push_back(keyTranslation);
	}

	for (int i = 0; i < assimpChannel->mNumRotationKeys; i++) {
		Key<glm::quat> keyQuaternion(assimpChannel->mRotationKeys[i].mTime,
				assimpToGlmQuat(assimpChannel->mRotationKeys[i].mValue));
		mKeysRotation.push_back(keyQuaternion);
	}

	for (int i = 0; i < assimpChannel->mNumScalingKeys; i++) {
		Key<glm::vec3> keyScaling(assimpChannel->mScalingKeys[i].mTime,
				assimpToGlmVec3(assimpChannel->mScalingKeys[i].mValue));
		mKeysScaling.push_back(keyScaling);
	}

	FLOG_DEBUG(
			" Added an animation channel \n name: %s \n keys S: %lu keys R: %lu keys P: %lu",
			mAffectedNodeName.c_str(), mKeysScaling.size(), mKeysRotation.size(),
			mKeysTranslation.size());
}

} /* animation */
} /* fillwave */
