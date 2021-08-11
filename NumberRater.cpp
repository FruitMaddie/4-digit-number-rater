#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//used for evaluating 2 digit numbers.
double pairRate(int pair) {
	if (pair < 0 || pair > 99) { return -1000; }
	
	switch (pair){
		case 32:
			cout << "\t" << pair << " is a power of 2! Epic! " << endl;
			return 2.5;
		case 1:
		case 4:
		case 9:
		case 25:
		case 36:
		case 49:
		case 81:
			cout << "\t";
			cout << setw(2) << setfill('0') << pair;
			cout << " is a perfect square! How polygonal. " << endl;
			return 2.25;
		case 16:
		case 64:
			cout << "\t" << pair << " is a power of 2! AND A SQUARE??? HOLY SHIT!! " << endl;
			return 3;
		case 27:
		case 50:
		case 75:
		case 20:
		case 15:
		case 21:
		case 45:
		case 12:
		case 24:
		case 48:
		case 96:
			cout << "\t" << pair << " is a very good number. " << endl;
			return 2;
		case 56:
		case 40:
		case 80:
		case 60:
		case 14:
			cout << "\t" << pair << " is a nice number. " << endl;
			return 1.5;
		case 42:
			cout << "\t42 is the meaning of the universe." << endl;
			return 1.75;
		case 72:
		case 35:
		case 28:
		case 63:
		case 52:
		case 18:
		case 10:
			cout << "\t" << pair << " is a cool number. " << endl;
			return 1;
		case 0:
		case 69:
			cout << "\t";
			cout << setw(2) << setfill('0') << pair;
			cout << " is uncreative. Get real. " << endl;
			return 0;
		case 2:
		case 3:
		case 5:
		case 7:
		case 11:
		case 13:
		case 17:
		case 19:
		case 23:
		case 29:
		case 31:
		case 37:
		case 41:
		case 43:
		case 47:
		case 53:
		case 59:
		case 61:
		case 67:
		case 71:
		case 73:
		case 79:
		case 83:
		case 89:
		case 97:
			cout << "\t" << pair << " is a prime number. kinda okay. " << endl;
			return 0.75;
	}
	
	if (pair%5 == 0) {
		cout << "\t" << pair << " is a multiple of 5! " << endl;
		if (pair == 55) {
			cout << "\t" << pair << " is a set of twins! " << endl;
		}
		return 1;
	}
	
	if (pair/10 == pair%10) {
		cout << "\t" << pair << " is a set of twins! " << endl;
		return 1;
	}
	return 0;
}

double rate(int input) {
  //input is from 0-9999 inclusive
  if (input < 0 || input > 9999) { return -1; }
  
  cout << "Your number is ";
  cout << setw(4) << setfill('0') << input;
  cout << ": " << endl;
  
  if (input == 1488) {
	  cout << "\tNazis are only good as target practice. Get real. -10000000/10. " << endl;
	  return -1000;
  }
  
  int digit1 = (int) input  / 1000;
  int digit2 = ((int) input / 100) % 10;
  int digit3 = ((int) input / 10)  % 10;
  int digit4 = input % 10;
  
  int firstPair  = digit1 * 10 + digit2;
  int secondPair = digit3 * 10 + digit4;
  
  int firstTriplet  = digit1 * 100 + digit2 * 10 + digit3;
  int secondTriplet = digit2 * 100 + digit3 * 10 + digit4;
  
  double score = 0;
  
/*
 *   5/10 Points |  Whole Number Analysis
 */
  
  if (digit1 == 1) { cout << "\tFirst digit is a 1. Clean." << endl; score++; }
  
  if (input == 1024 || input == 2048 || input == 4096 || input == 8192) {
	  cout << "\tFour digit power of 2! Amazing! We love to see it! " << endl;
	  score += 4;
  } else if (input == 1984 || input == 6969 || input == 420 || input == 1337) {
	  cout << "\t";
	  cout << setw(4) << setfill('0') << input;
	  cout << " is not creative. Get real. " << endl;
	  if (input == 1984) {
		  cout << "\tLiterally 1984." << endl; score++;
	  } else if (input == 1337) {
		  cout << "\tGamer detected. " << endl;
	  }
  } else if (firstTriplet == 512  || firstTriplet  == 256 || firstTriplet  == 128) {
	  cout << "\tThere is a power of 2 among us. ";
	  cout << setw(3) << setfill('0') << firstTriplet;
	  cout << " is fresh. " << endl;
	  score += 3.5;
  } else if (secondTriplet == 512 || secondTriplet == 256 || secondTriplet == 128) {
	  cout << "\tThere is a power of 2 among us. ";
	  cout << setw(3) << setfill('0') << secondTriplet;
	  cout << " is fresh. " << endl;
	  score += 3.5;
  //xxxx
  } else if (digit1 == digit2 && digit2 == digit3 && digit3 == digit4) {
	  cout << "\tFour in a row! ";
	  if (digit1 == 1 || digit1 == 4 || digit1 == 7 || digit1 == 8) {
		  cout << digit1 << " isn't the best repeating digit tbh. " << endl;
		  score += 2.25;
	  } else if (digit1 == 0) {
		  cout << "0 is not a creative number. " << endl;
	  } else {
		  cout << digit1 << " is a great digit to repeat. " << endl;
		  score += 3;
	  }
  //xxyy
  } else if (digit1 == digit2 && digit3 == digit4) {
	  cout << "\tThere's a pair of twins! Lovely. " << endl;
	  score += 3.25;
  //the repeating triplets, first
  } else if (digit1 == digit2 && digit2 == digit3) {
	  cout << "\tThree in a row! ";
	  if (digit1 == 1 || digit1 == 4 || digit1 == 7 || digit1 == 8) {
		  cout << digit1 << " isn't the best repeating digit tbh. " << endl;
		  score += 1;
	  } else if (digit1 == 0) {
		  cout << "Starting with three 0's isn't the best look. " << endl;
		  score += 0.5;
	  } else {
		  cout << digit1 << " is a great digit to repeat. " << endl;
		  score += 2;
	  }
  //second triplet
  } else if (digit2 == digit3 && digit3 == digit4) {
	  cout << "\tThree in a row! ";
	  if (digit1 == 1 || digit1 == 4 || digit1 == 7 || digit1 == 8) {
		  cout << digit2 << " isn't the best repeating digit tbh. " << endl;
		  score += 1;
	  } else if (digit2 == 0) {
		  cout << "A thousand! Decimal moment. " << endl;
		  score += 1.5;
	  } else {
		  cout << digit2 << " is a great digit to repeat. " << endl;
		  score += 2;
	  }
  //xyyx
  } else if (digit1 == digit4 && digit2 == digit3) {
	  cout << "\tThese twins are a little bit derpy, with " << digit2 << digit3 << " inside " << digit1 << digit4 << ". Still neato. " << endl;
	  score += 3;
  //xyxy
  } else if (digit1 == digit3 && digit2 == digit4) {
	  cout << "\tDual numbers! Friends! " << endl;
	  score += 3;
  //xyyz
  } else if (digit2 == digit3) {
	  cout << "\tMiddle Twins! " << digit2 << digit3 << " is in a " << digit1 << digit4 << " sandwich! " << endl;
	  score += 2.25;
  //420 check
  } else if (digit1 == 4 && digit2 == 2 && digit3 == 0) {
	  cout << "\t420 is uncreative. Get real. " << endl;
	  score += 0.25;
  } else if (digit2 == 4 && digit3 == 2 && digit4 == 0) {
	  cout << "\t420 is uncreative. Get real. " << endl;
	  score += 0.25;
  }
  
  //ascending and descending
  if (digit1 < digit2 && digit2 < digit3 && digit3 < digit4) {
	  cout << "\tIt's in ascending order! Impressive! " << endl;
	  score += 0.5;
  } else if (digit1 <= digit2 && digit2 <= digit3 && digit3 <= digit4) {
	  cout << "\tIt's in almost ascending order. Kinda cool. " << endl;
	  score += 0.25;
  } else if (digit1 > digit2 && digit2 > digit3 && digit3 > digit4) {
	  cout << "\tIt's in descending order! Impressive! " << endl;
	  score += 0.5;
  } else if (digit1 >= digit2 && digit2 >= digit3 && digit3 >= digit4) {
	  cout << "\tIt's in almost descending order. Kinda cool. " << endl;
	  score += 0.25;
  }
  
/*
 *   4/10 Points |  Pair Analysis
 */
  
  cout << "\tThe pairs within ";
  cout << setw(4) << setfill('0') << input;
  cout << " are ";
  cout << setw(2) << setfill('0') << firstPair;
  cout << " and ";
  cout << setw(2) << setfill('0') << secondPair;
  cout << ". " << endl;
  double firstScore = pairRate(firstPair);
  double secondScore;
  if (firstPair == secondPair) {
	  cout << "\tThe two pairs are the same! So they get the same score. And a little bonus, as a treat. " << endl;
	  secondScore = firstScore;
	  score += 0.25;
  } else {
	  secondScore = pairRate(secondPair);
  }
  
  if (firstScore == 0 && secondScore == 0 && input != 6969) {
	cout << "\tThose number pairs kinda blow :/ " << endl;
  } else if (firstScore == 0 && firstPair != 69 && firstPair != 0) {
	  cout << "\t";
	  cout << setw(2) << setfill('0') << firstPair;
	  cout << " sucked. " << endl;
  } else if (secondScore == 0 && secondPair != 69 && secondPair != 0 && firstPair != secondPair) {
	  cout << "\t";
	  cout << setw(2) << setfill('0') << secondPair;
	  cout << " sucked. " << endl;
  }
  
  score += firstScore;
  score += secondScore;
  
/*
 *   1/10 Points |  Digit Analysis
 */
 
 if (digit1 % 2 == 0 || digit2 % 2 == 0 || digit3 % 2 == 0 || digit4 % 2 == 0) {
	 cout << "\tThis number has at least 1 even digit. Thank God. " << endl;
	 score++;
 }
  
   if (digit1 % 2 != 0 && digit2 % 2 != 0 && digit3 % 2 != 0 && digit4 % 2 != 0) {
	 cout << "\tThis number only has odd digits. Odds drool and drool is hot " << endl;
	 score++;
 }
 
 if (digit1 == 5 || digit2 == 5 || digit3 == 5 || digit4 == 5) {
	 cout << "\tThis number has a 5 in it. Pentagonal! " << endl;
	 score++;
 }
  
  if(digit1 == digit4 && digit2 == digit3){
                   cout << "\tSymetric number! Pretty." <<endl;
                   score++;
  }
 
cout << "The score for ";
cout << setw(4) << setfill('0') << input;
cout << " is " << score << "/10. " << endl;
  return score;
} 

int main(int argc, char *argv[]) {
	int input;
	if (argc > 1) {
		input = atoi(argv[1]);
	} else {
		cout << "Enter your number: ";
		cin >> input;
		cout << "\n";
	}
	rate(input);
	return 0;
}
