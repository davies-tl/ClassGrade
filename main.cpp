/*
Analysis: (What is being asked of us?)
- Given user input scores, verify that the inputted values are valid
- If the values are not valid, terminate the program
- Use input to find the average final grade and letter
- Output a report for the user

Design:
A) Input
	- Prompt user for their full name including middle initial (if avaliable)
	- Prompt user for their first exam score (0-100)
	- Prompt user for their second exam score (0-100)
	- Prompt user for their third exam score (0-100)
	- Prompt user for their programming assignment score (0.0-100.0)
	- Prompt user for their quiz score (0-100)
	- Final scores are weighted as follows: Test to 60%; Programming Assignment to 30%; Quiz to 10%
B) Process
	- Use getline(cin, studentName) to get full name (with or without middle name)
	- Use if statements to verify that the input values are integers/digits between 0 and 100 inclusive
			cin.fail() to verify that the data entered are integer values (not alphabetical) 
			value < 0 || value > 100
	- Average Test Score = (Score 1 + Score 2 + Score 3) / 3
	- Final Average = (Average Test Score * 0.60) + (Quiz Score * 0.10) + (Programming Assignment Score * 0.30)
	- Use multi if-else statement to assign letter grade
C) Output
	- Requirements from assignment:
		Display the results in nice format
		Labels and values all line up
		Real numbers show only 2 digits after the decimal point
	- If input is invalid, print error message indicating which value was invalid and why; then exit the program
	- Print report including:
		Student Name
		Test Scores
		Test percentage
		Quiz percentage
		Programming Assignment percentage
		Total Course Percentage
		Letter grade for the course
	- Sample report provided (copied exactly from the assignment prompt as is):
		Hello Joe S. Johnsen, here is your report: 
		     Test Scores:                        100, 0, 100
		     Tests percentage:                   40.00
		     Quiz percentage:                    5.00
		     Programming Assignment percentage:  30.00
		     Total Course Percentage:            75.00
		     Letter grade for the course:        C
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	string studentName;
	unsigned int firstTest;		//unasigned tells the system this number will be positive
	unsigned int secondTest;
	unsigned int thirdTest;
	double testAverage;
	double quizGrade;
	double assignmentGrade;
	double finalGrade;
	char letterGrade;
	
	cout << setw(62) << "Final Grade Average Calculator" << endl;
	cout << endl;
	cout << endl;
	
	cout << "Please enter your full name as written on your student ID." << endl;
	cout << "Example: First MI. Last" << endl;
	getline(cin, studentName);
	cout << endl;
	
	cout << "Enter your first test score (0 - 100):" << endl;
	cin >> firstTest;
	cout << endl;
	if (cin.fail()) {		//cin.fail() returns true when an input failure occurs (input is not an integer)
		cout << "Test score 1 is not valid, must be all digits." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}
	if (firstTest < 0 || firstTest > 100) {
		cout << "Test score 1 is not valid, must be between 0 - 100 inclusive." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}

	cout << "Enter your second test score (0 - 100):" << endl;
	cin >> secondTest;
	cout << endl;
	if (cin.fail()) {
		cout << "Test score 2 is not valid, must be all digits." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}
	if (secondTest < 0 || secondTest > 100) {
		cout << "Test score 2 is not valid, must be between 0 - 100 inclusive." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}

	cout << "Enter your third test score (0 - 100):" << endl;
	cin >> thirdTest;
	cout << endl;
	if (cin.fail()) {
		cout << "Test score 3 is not valid, must be all digits." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}
	if (thirdTest < 0 || thirdTest > 100) {
		cout << "Test score 3 is not valid, must be between 0 - 100 inclusive." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}

	cout << "Enter your quiz score (0 - 100)." << endl;
	cin >> quizGrade;
	cout << endl;
	if (cin.fail()) {
		cout << "Quiz score is not valid, must be all digits." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}
	if (quizGrade < 0 || quizGrade > 100) {
		cout << "Quiz score is not valid, must be between 0 - 100 inclusive." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}

	cout << "Enter your programming assignment score (0.0 - 100.0)." << endl;
	cin >> assignmentGrade;
	cout << endl;
	if (cin.fail()) {
		cout << "Programming assignment score is not valid, must be all digits." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}
	if (assignmentGrade < 0 || assignmentGrade > 100) {
		cout << "Programming assignment score is not valid, must be between 0 - 100 inclusive." << endl;
		cout << "Program is terminated." << endl;
		return 0;
	}
		
	cout << setw(56) << "Calculating Final Grade Average..." << endl;
	cout << left << endl;
	
	testAverage = ((double)firstTest + (double)secondTest + (double)thirdTest) / 3.0;		//calculating the average score of all three tests
	testAverage *= 0.60;		//calculating and assigning weighted percentage for final output (*= is value = value * _____)
	quizGrade *= 0.10;
	assignmentGrade *= 0.30;
	finalGrade = testAverage + quizGrade + assignmentGrade;		//adding percentages for final grade total
	if (finalGrade <= 100 && finalGrade >= 90) {		//calculating letter grade based on final grade
		letterGrade = 'A';
	}
	else if (finalGrade >= 80) {
		letterGrade = 'B';
	}
	else if (finalGrade >= 70) {
		letterGrade = 'C';
	}
	else if (finalGrade >= 60) {
		letterGrade = 'D';
	}
	else {
		letterGrade = 'F';
	}
	
	cout << fixed << showpoint << setprecision(2) << endl;		//showpoint tells the system to show decimals on whole numbers (for float/double values only)

	cout << "Hello " << studentName << ", here is your report:" << endl;
	cout << setw(6) << " " << setw(36) << "Test Scores:" << firstTest << ", " << secondTest << ", " << thirdTest << endl;
	cout << setw(6) << " " << setw(36) << "Tests percentage:" << testAverage << endl;
	cout << setw(6) << " " << setw(36) << "Quiz percentage:" << quizGrade << endl;
	cout << setw(6) << " " << setw(36) << "Programming Assignment percentage:" << assignmentGrade << endl;
	cout << setw(6) << " " << setw(36) << "Total Course Percentage:" << finalGrade << endl;
	cout << setw(6) << " " << setw(36) << "Letter grade for the course:" << letterGrade << endl;
	cout << right << endl;
	cout << endl;
	
	cout << setw(72) << "Thank you for using the Final Grade Average Calculator (3.21 Assignment 1)" << endl;
	cout << setw(49) << "Have a wonderful day!" << endl;
	cout << endl;
	cout << endl;
	cout << setw(51) << "Please type enter to exit." << endl;
	getchar();		//double getchar() tells the program not to immediately terminate; waits until it recieves another character
	getchar();		//ignore compiler warning for now
	
	return 0;
} 