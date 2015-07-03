/*
 * matStruct.h
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */

#ifndef MATSTRUCT_H_
#define MATSTRUCT_H_

template<typename T>
	struct Mat{
		int width, height;
		T* data;
	};

#endif /* MATSTRUCT_H_ */
