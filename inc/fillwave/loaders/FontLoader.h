/*
 * FontLoader.h
 *
 *  Created on: Aug 9, 2014
 *      Author: Filip Wasil
 */

#ifndef FONTLOADER_H_
#define FONTLOADER_H_

#include <fontGenerator.h>

namespace fillwave {
namespace loader {

/*! \class FontLoader
 * \brief Loads fonts fromttf files.
 */

class FontLoader {
public:
	FontLoader() = default;
	virtual ~FontLoader() = default;
	void load(std::string name);
};

} /* loader */
} /* fillwave */

#endif /* FONTLOADER_H_ */
