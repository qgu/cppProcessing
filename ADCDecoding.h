/*
 * ADCDecoding.h
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */

#ifndef ADCDECODING_H_
#define ADCDECODING_H_

#include"matStruct.h"
#include<exception>

void ADCDecoding(const Mat<int> &, Mat<int> &);
class dimension_mismatch_exception: public std::exception{};


#endif /* ADCDECODING_H_ */
