/*
 * matStruct.h
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */

#ifndef MATSTRUCT_H_
#define MATSTRUCT_H_

template<typename T>
	class Mat
	{
		int width, height;
		T* data;

		void setMatSize(int h, int w)
		{
			delete [] data;
			width = w;
			height = h;
			data = new T[width * height];
		}

		Mat()
		{
			data = new T[1];
			setMatSize(1,1);
		}

		Mat(int x, int y)
		{
			data = new T[1];
			setMatSize(x,y);
		}

		~Mat()
		{
			delete [] data;
		}
};

#endif /* MATSTRUCT_H_ */
