/*
 * ADCDecoding.cpp
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */

#include"ADCDecoding.h"

void ADCDecoding(const Mat<int> & src, Mat<int> &des){
	//initialize destination matrix
	//A try-catch block so that dimensions are the same
/*
	if (!(src.width == des.width) && (src.height == des.height)) {
		throw "Dimension mismatch!";
	}
*/
/*
	//algorithm
	int NoOfPixels = des.width * des.height;

	for(int i = 0; i < NoOfPixels; i++){

		int pixel = *(src.data+i);
		int gain = pixel % 4;
		int fineBits = (pixel >> 2) % 256; // the next 8 digits
		int coarseBits = (pixel >> 10) % 32; // the next 5 bits


		*(des.data + i) = gain * (coarseBits * 4 + fineBits * 1); //algorithm
	}
*/

}
