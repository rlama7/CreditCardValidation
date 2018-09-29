/**
 * @file		main.cpp
 * @author		Inst. Duc Ta
 * @author		Ratna Lama
 * @date		7/5/2018
 * @version		1.10.0
	
 * @brief 		CSC340 Part II : Credit Card Validation
 * 
 * @section		DESCRIPTION
 * 
 * A program to validate Credit Cards
 * 
 * Algorithm:
 * 1.) If the credit card number exceeds 16 digits then the card is invalid
 * 2.) Checks for every seceond digit from right to left. If doubling a digit reults 
 * 		in a two-digit number, add the two digits to get a single digit number
 * 3.) Next sum all single digit from step 2.
 * 4.) Add all digits in odd places from right to left in the card number
 * 5.) Sum the results from step 4.
 * 6.) If the sum of the result from step #3 and #5 is divisible by 10, the 
 * 		credit card number is valid; otherwise, it is invalid.
 */
 
#include <iostream>
#include <string>		// string
#include <vector>		// vector
#include <algorithm>	// reverse
#include <cstring>		// for c-style string functions
#include <cctype> 		// for character-based functions
#include <iomanip>		// manipulator; setw()
#include <iterator>		// iterator

using namespace std;

// Function Prototype
bool isvalidcc(const string&);

// Main Function
int main() {	
	//
	// PLEASE DO NOT CHANGE main()
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};
	
	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2)  << i << " " 
			 << setw(17) << *itr 
			 << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}
	
	return 0;

} // end main function

// Function isvalidcc
bool isvalidcc(const string& cc_num) {
	
	string str = cc_num; 	// Makes copy of credit card number so we don't change refrence value
	
	int credit_card_num_length = str.length();	// Length of credit card number
	
	int sum_even_position {};
	int sum_odd_position {};
	
	if(credit_card_num_length >16) {	// Checks if the length of the credit card number is > 16
		return false;
		
	} else {
		
		for (int i=0; i<credit_card_num_length; ++i) {
		int digit = str.at(i)-'0';		// Converts char to int
		
		if (i%2 == 0) {					// Checks for digit at even position
			sum_even_position += digit * 2;	// Add :  digit*2 for (0-4) and 
			
			if(digit >= 5) {			// Subtract : digit*2 - 9 for (5-9)
				sum_even_position -= 9;				
			}		
		} else {
			sum_odd_position += digit; 	// // Checks for digit at odd position
		}
	}
	return ((sum_even_position + sum_odd_position) % 10 == 0);
		
	}
	
} // end isvalidcc