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
			//declare more variables
			ConstantChooser c0{"0"};
		//adding more TESTS
		testcase.setname("100 percent bullseye")
		.CHECK_OUTPUT(calculateBullAndPgia("9999","9999"), "4,0")
		.CHECK_OUTPUT(calculateBullAndPgia("8787","8787"), "4,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("55","55"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("57","57"), "2,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1234567","1234567"), "7,0")
		.CHECK_OUTPUT(calculateBullAndPgia("852852852","852852852"), "9,0")
		;

		testcase.setname("short and long chooser-guesser combinations")
		.CHECK_OUTPUT(calculateBullAndPgia("9","8"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("87","79"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("789654","000124"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("000000","111111"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("8888777999","5700000000"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("987654321","123456789"), "1,8") //only 5 is bull, all others are pgia
		.CHECK_OUTPUT(calculateBullAndPgia("852852851","852852857"), "8,0")
		.CHECK_OUTPUT(calculateBullAndPgia("1573","1875"), "2,1")	   // 2 bull, 1 pgia
		;

		testcase.setname("play function")
		.CHECK_EQUAL(play(c1234, g1234, 4, 5), 1) //guesser should win in 1 turn even with max turns of 5 and not 100.
		.CHECK_EQUAL(play(c9999, g9999, 4, 5), 1) //1 turn winning
		.CHECK_EQUAL(play(c1234, g12345, 1, 5), 0) // chooser loses technical
		.CHECK_EQUAL(play(c0, g12345, 1, 100), 101) // guesser loses technical
;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
