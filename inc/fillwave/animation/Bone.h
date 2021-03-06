/*
 * Bone.h
 *
 *  Created on: Jun 23, 2014
 *      Author: Filip Wasil
 */

#ifndef BONE_H_
#define BONE_H_

#include <fillwave/models/Entity.h>
#include <fillwave/Assets.h>

namespace fillwave {

namespace animation {
class Bone;
}

typedef std::shared_ptr<animation::Bone> pBone;

namespace animation {

/*! \class Bone
 * \brief Entity used by BoneManager to perform animation.
 */

class Bone: public models::Entity {
public:
	Bone(fBone* assimpBone);
	virtual ~Bone() = default;

	void childrenUpdate();

	std::string getName() const;
	glm::mat4 getOffsetMatrix() const;
	glm::mat4 getGlobalOffsetMatrix() const;

	void setName(std::string name);
	void setOffsetMatrix(glm::mat4 m);
	void setGlobalOffsetMatrix(glm::mat4 m);

	void log();

private:
	std::string mName;
	glm::mat4 mOffsetMatrix;
	glm::mat4 mGlobalOffsetMatrix;
};

} /* animation */
} /* fillwave */

#endif /* BONE_H_ */
