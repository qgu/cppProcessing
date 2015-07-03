/*
 * testing.cpp
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */

#include"matStruct.h"
#include"ADCDecoding.h"

#include<iostream>
using namespace std;

#define BOOST_TEST_MODULE stringtest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

struct fixture{
	Mat<int> testMat;
	Mat<int> desMat;
	fixture(){
			int image[] = {1,2,3,4,5,6};
			testMat.data = image;
			testMat.width = 6;
			testMat.height = 1;
			desMat = ADCDecoding(testMat,desMat);
	}
};

BOOST_FIXTURE_TEST_SUITE (test_ADCDecoding,fixture) // name of the test suite is stringtest

BOOST_AUTO_TEST_CASE (returning_mat_of_same_kind)
{
	BOOST_REQUIRE_EQUAL(testMat.width,desMat.width);
	BOOST_REQUIRE_EQUAL(testMat.height,desMat.height);
}
/*
BOOST_AUTO_TEST_CASE(test_input_is_const){
	BOOST_REQUIRE_EQUAL(testMat.width,desMat.width);
	BOOST_REQUIRE_EQUAL(testMat.height,desMat.height);
}
*/



BOOST_AUTO_TEST_SUITE_END()




