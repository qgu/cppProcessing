/*
 * testing.cpp
 *
 *  Created on: 3 Jul 2015
 *      Author: pqm78245
 */
/*
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
	int numOfPixels;
	fixture(){
			//read in from established source data file;
			int image[] = {1,-11,1,2,3,4,5,6};
			//initialising
			testMat.data = image;
			testMat.width = 6;
			testMat.height = 1;
			numOfPixels = testMat.width * testMat.height;
			ADCDecoding(testMat,desMat);
	}
};

BOOST_FIXTURE_TEST_SUITE (test_ADCDecoding,fixture) // name of the test suite is stringtest

	//first level testing. No information about the algorithm.
	BOOST_AUTO_TEST_CASE (returning_mat_of_same_height_and_width)
	{
		BOOST_REQUIRE_EQUAL(testMat.width,desMat.width);
		BOOST_REQUIRE_EQUAL(testMat.height,desMat.height);
	}

	BOOST_AUTO_TEST_CASE (output_pixel_is_of_right_type)
	{
		BOOST_WARN_EQUAL(sizeof(*(testMat.data)),sizeof(*(testMat.data)));
	}

	BOOST_AUTO_TEST_CASE (output_pixel_is_non_negative)
	{
		for(int i=0;i<numOfPixels;i++){
			//location of first occurrence does not matter.
			BOOST_REQUIRE_LE(*(testMat.data+i),0);
		}
	}

	//second level testing. Algorithm in place.
	BOOST_AUTO_TEST_CASE (test_against_established_values)
	{
		//read in files

		//compare value. can use BOOST_REQUIRE_EQUAL for int type
		BOOST_REQUIRE_EQUAL(testMat.width,desMat.width);
		//close files
	}

BOOST_AUTO_TEST_SUITE_END()


*/

