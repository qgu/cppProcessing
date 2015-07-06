/*
 * test_ADCDecoding.cpp
 *
 *  Created on: 6 Jul 2015
 *      Author: pqm78245
 */

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

/*
struct fixturePoint{
		Mat<int> testMat;
		Mat<int> desMat;
		fixturePoint(){
			//initialize data array.
					testMat.height = 1;
					testMat.width = 1;
					int* testImage = new int[testMat.width * testMat.height];
					testMat.data = testImage;

					desMat.width = 1;//= testMat.width;
					desMat.height = 1; //= testMat.height;
					int* desImage = new int[desMat.width * desMat.height];
					desMat.data = desImage;

					//run the function
					ADCDecoding(testMat, desMat);
		}

		~fixturePoint(){
			delete [] testMat.data;
			delete [] desMat.data;
		}
};
*/
/*
struct fixturePoint{
	Mat<int> testMat;
	Mat<int> desMat;
	fixturePoint(){
		//initialize data array.
			testMat.setMat(1,1);
			desMat.setMat(1,1);

		//run the function
			ADCDecoding(testMat, desMat);
	}
	~fixturePoint(){
		delete [] testMat.data;
		delete [] desMat.data;
	}
};
*/
struct fixtureSmall{
	Mat<int> testMat;
	Mat<int> desMat;
	fixtureSmall(){
		//initialize data array.
			testMat.setMat(3,4);
			desMat.setMat(3,4);

		//run the function
			ADCDecoding(testMat, desMat);
	}
	~fixtureSmall(){
		delete [] testMat.data;
		delete [] desMat.data;
	}
};

int helper(int coarse, int fine, int gain){
	int output = gain * (coarse * 4 + fine * 1);
	return output;
}

/*
struct fixtureBig{
		Mat<int> testMat;
		Mat<int> desMat;
		fixtureSmall(){
			int* testImage = new int{1,2,3,4,5,6};
			testMat.data = testImage;
			testMat.height = 3;
			testMat.width = 4;

			desMat.width = testMat.width;
			desMat.height = testMat.height;
			int* desImage = new int[desMat.width * desMat.height];
			desMat.data = desImage;
		}
		~fixtureSmall(){
			delete [] testMat.data;
			delete [] desMat.data;
		}
};
*/


BOOST_FIXTURE_TEST_SUITE (test_ADCDecoding_small_image,fixtureSmall) // name of the test suite is stringtest

	//small images 3 * 4
/*
	BOOST_AUTO_TEST_CASE ( should_throw_exception_if_width_and_height_are_not_the_same_as_input	)
	{
		BOOST_REQUIRE_THROW(,20);
	}
*/
/*
	BOOST_AUTO_TEST_CASE (returning_mat_of_same_height_and_width)
	{
		BOOST_REQUIRE_EQUAL(testMat.width,desMat.width);
		BOOST_REQUIRE_EQUAL(testMat.height,desMat.height);
	}
*/

	BOOST_AUTO_TEST_CASE (output_pixel_is_of_right_type)
	{
		BOOST_CHECK_EQUAL(sizeof(*(testMat.data)),sizeof(*(desMat.data)));
	}

	BOOST_AUTO_TEST_CASE (output_pixel_is_non_negative)
	{
		for(int i=0;i<testMat.height * desMat.width;i++){
			//location of first occurrence does not matter.
			BOOST_CHECK_GE(*(testMat.data+i),0);
		}
	}

	BOOST_AUTO_TEST_CASE (the_central_bit_should_return_valid_numbers)
	{
		//use manually calculated data to verify
		// 0 		-> 	0
		// 32767 	->	1137
		*(testMat.data + 5) = 0;
		*(testMat.data + 6) = 32767;
		ADCDecoding(testMat, desMat);
		BOOST_CHECK_EQUAL(0, *(desMat.data + 5));
		BOOST_CHECK_EQUAL(1137, *(desMat.data + 6));
	}
BOOST_AUTO_TEST_SUITE_END()

/*
BOOST_FIXTURE_TEST_SUITE (test_ADCDecoding_point_image, fixturePoint)
	//testing the algorithm for different boundary cases
	BOOST_AUTO_TEST_CASE ( should_return_B_when_input_is_A )
	{
		//the test data used are manually computed using
		//output = gain * ( coarseBits * 4 + fineBits * 1 )
		/*	Considering boundary cases and a random number in between
		 *
		 *  input		binary					coarse		fine	gain	output
		 *  0			0000,0000,0000,0000		0			0		0		0
		 *  32767		0111,1111,1111,1111		31			255		3		1137
		 *  21853		0101,0101,0101,1101		21			87		1		171
		 */
/*		*(testMat.data) = 0;
		ADCDecoding(testMat, desMat);
		BOOST_CHECK_EQUAL(helper(0,0,0), *(desMat.data));

		*(testMat.data) = 32767;
		ADCDecoding(testMat, desMat);
		BOOST_CHECK_EQUAL(helper(31,255,3), *(desMat.data));

		*(testMat.data) = 21853;
		ADCDecoding(testMat, desMat);
		BOOST_CHECK_EQUAL(helper(21,87,1), *(desMat.data));
	}

BOOST_AUTO_TEST_SUITE_END()

*/




