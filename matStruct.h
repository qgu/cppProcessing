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
/////////////////////////////////////////////////////////////////////
		Mat() {
			height = 1;
			width = 1;
			data = new T[width * height];
		}
		~Mat(){
			delete [] data;
		}
////////////////////////////////////////////////////////////////////
		void setMat(int h, int w){
			width = w;
			height = h;
			data = new T[width * height];
		}
	};

#endif /* MATSTRUCT_H_ */
