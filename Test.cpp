/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#include "calculate.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}


		//OUR TESTS
		testcase.setname("OUR TESTS")
		.CHECK_OUTPUT(calculateBullAndPgia("1234", "9999"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("9999", "1234"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("9999", "9999"), "4,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234", "1111"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1111", "1234"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1998", "4937"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4937", "1998"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1231", "1113"), "1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1113", "1231"), "1,2")
		.CHECK_OUTPUT(calculateBullAndPgia("1112", "2111"), "2,2")
		.CHECK_OUTPUT(calculateBullAndPgia("2111", "1112"), "2,2");

		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=75, true);
		}

		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=50, true);
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=30, true);
		}
		
		

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

