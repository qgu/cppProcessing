/*
 * ADCDecoding.cpp
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */

#include"ADCDecoding.h"

void ADCDecoding(const Mat<int> & src, Mat<int> &des){

	//Throw exception if dimensions are not the same
	if(src.width != des.width)
		if(src.height != des.height)
			throw dimension_mismatch_exception{};

	int NoOfPixels = des.width * des.height;

	for(int i = 0; i < NoOfPixels; i++)
	{
		int pixel = *(src.data+i);
		*(des.data + i) = ADCDecodingAlgorithm(pixel);
	}
}

int ADCDecodingAlgorithm(int pixel){
	int gain = pixel % 4;
	int fineBits = (pixel >> 2) % 256; // the next 8 digits
	int coarseBits = (pixel >> 10) % 32; // the next 5 bits

	int result = gain * (coarseBits * 4 + fineBits * 1); //algorithm
	return result;
}




