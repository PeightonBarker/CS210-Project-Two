//Peighton Barker CS210 5-3 Assignment

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Function without additional monthly deposits
void withoutAddMonthlyDeposits(double t_initialInvestment, int t_annualInterest, int t_numberOfYears) {
	double interestChange = 0.0; //Declares and initializes interestChange with 0
	double startingAmount = t_initialInvestment; //Sets startingAmount to t_initialInvestment
	double endingAmount; //Declares variable endingAmount
	double yearEndEarnedInterest; //Declares variable yearEndEarnedInterest
	int i; //Declares int i
	int j; //Declares int j

	//For loop that loops number of years user entered
	for (i = 0; i < t_numberOfYears; ++i) {
		yearEndEarnedInterest = 0.0; //Sets yearEndEarnedInterest to 0 at the start of each year
		cout << setw(6) << right << i + 1; //Outputs year in year column
		//For loop that loops for months 1-12 in the year
		for (j = 0; j < 12; ++j) {
			interestChange = startingAmount * ((t_annualInterest / 100.0) / 12.0); //Calculates interest without monthly deposit
			yearEndEarnedInterest += interestChange; //Adds interest after each month
			endingAmount = startingAmount + interestChange; //Calculates ending amount after each month
			startingAmount = endingAmount; //Sets starting amount to ending amount to begin the loop again
		}
		cout << setw(23) << right << fixed << setprecision(2) << endingAmount; //Outputs ending amount under year end balance column
		cout << setw(29) << right << fixed << setprecision(2) << yearEndEarnedInterest << endl; //Outputs yearEndEarnedInterest under respective column
		cout << endl;
	}
}

//Function with additional monthly deposits
void withAddMonthlyDeposits(double t_initialInvestment, double t_monthlyDeposit, int t_annualInterest, int t_numberOfYears) {
	double interestChange = 0.0; //Declares and initializes interestChange with 0
	double startingAmount = t_initialInvestment; //Sets startingAmount to t_initialInvestment
	double endingAmount; //Declares variable endingAmount
	double yearEndEarnedInterest; //Declares variable yearEndEarnedInterest
	int i; //Declares int i
	int j; //Declares int j

	//For loop that loops number of years user entered
	for (i = 0; i < t_numberOfYears; ++i) {
		yearEndEarnedInterest = 0.0; //Sets yearEndEarnedInterest to 0 at the start of each year
		cout << setw(6) << right << i + 1; //Outputs year in year column
		//For loop that loops for months 1-12 in the year
		for (j = 0; j < 12; ++j) {
			interestChange = (startingAmount + t_monthlyDeposit) * ((t_annualInterest / 100.0) / 12.0); //Calculates interest with monthly deposit
			yearEndEarnedInterest += interestChange; //Adds interest after each month
			endingAmount = startingAmount + t_monthlyDeposit + interestChange; //Calculates ending amount after each month
			startingAmount = endingAmount; //Sets starting amount to ending amount to begin the loop again
		}
		cout << setw(23) << right << fixed << setprecision(2) << endingAmount; //Outputs ending amount under year end balance column
		cout << setw(29) << right << fixed << setprecision(2) << yearEndEarnedInterest << endl; //Outputs yearEndEarnedInterest under respective column
		cout << endl;
	}
}

//Function to format user data entry
void formatDataEntry() {
	cout << setfill('*') << setw(36) << "" << endl;
	cout << setfill('*') << setw(12) << "" << " Data Entry " << setfill('*') << setw(12) << "" << endl;
}

//Function to format column names
void formatColumns() {
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
	cout << setw(6) << right << "Year";
	cout << setw (23) << right << "Year End Balance($)";
	cout << setw(29) << right << "Year End Earned Interest($)" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
}

//Main function
int main() {
	double initialInvestment; //Declares variable initialInvestment
	double monthlyDeposit; //Declares variable monthlyDeposit
	int annualInterest; //Declares variable annualInterest
	int numberOfYears; //Declares variable numberOfYears
	char userContinue = 'y'; //Declares variable userContinue

	formatDataEntry(); //Calls function
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment; //Gets user input
	//While loop keeps looping until user enters a positive number
	while (initialInvestment < 0) {
		cout << "Please enter a positive number" << endl;
		cout << "Initial Investment Amount: ";
		cin >> initialInvestment; //Gets user input again until 0 or greater
	}
	cout << endl << "Monthly Deposit: ";
	cin >> monthlyDeposit; //Gets user input
	//While loop keeps looping until user enters a positive number
	while (monthlyDeposit < 0) {
		cout << "Please enter a positive number" << endl;
		cout << "Monthly Deposit: ";
		cin >> monthlyDeposit; //Gets user input again until 0 or greater
	}
	cout << endl << "Annual Interest: ";
	cin >> annualInterest; //Gets user input
	//While loop keeps looping until user enters a positive number
	while (annualInterest < 0) {
		cout << "Please enter a positive number" << endl;
		cout << "Annual Interest: ";
		cin >> annualInterest; //Gets user input again until 0 or greater
	}
	cout << endl << "Number of Years: ";
	cin >> numberOfYears; //Gets user input
	//While loop keeps looping until user enters a positive number
	while (numberOfYears < 0) {
		cout << "Please enter a positive number" << endl;
		cout << "Number of Years: ";
		cin >> numberOfYears; //Gets user input again until 0 or greater
	}
	cout << endl;
	system("pause"); //Displays "Press any key to continue..."
	cout << endl;

	//While loop keeps looping until user doesn't want to see any more reports
	while (userContinue == 'y') {
		cout << " Balance and Interest Without Additional Monthly Deposits " << endl;
		formatColumns(); //Calls function
		withoutAddMonthlyDeposits(initialInvestment, annualInterest, numberOfYears); //Calls function
		cout << endl;

		cout << "  Balance and Interest With Additional Monthly Deposits  " << endl;
		formatColumns(); //Calls function
		withAddMonthlyDeposits(initialInvestment, monthlyDeposit, annualInterest, numberOfYears); //Calls function
		cout << endl;

		cout << "Would you like to see another report? (enter y/n)"; //Asks user for input
		cin >> userContinue;
		//If input is n, output Goodbye! and quits the program
		if (userContinue == 'n') {
			cout << "Goodbye!";
			break;
		}
		cout << endl;

		formatDataEntry();
		cout << "Initial Investment Amount: ";
		cin >> initialInvestment; //Gets user input
		//While loop keeps looping until user enters a positive number
		while (initialInvestment < 0) {
			cout << "Please enter a positive number" << endl;
			cout << "Initial Investment Amount: ";
			cin >> initialInvestment; //Gets user input again until 0 or greater
		}
		cout << endl << "Monthly Deposit: ";
		cin >> monthlyDeposit; //Gets user input
		//While loop keeps looping until user enters a positive number
		while (monthlyDeposit < 0) {
			cout << "Please enter a positive number" << endl;
			cout << "Monthly Deposit: ";
			cin >> monthlyDeposit; //Gets user input again until 0 or greater
		}
		cout << endl << "Annual Interest: ";
		cin >> annualInterest; //Gets user input
		//While loop keeps looping until user enters a positive number
		while (annualInterest < 0) {
			cout << "Please enter a positive number" << endl;
			cout << "Annual Interest: ";
			cin >> annualInterest; //Gets user input again until 0 or greater
		}
		cout << endl << "Number of Years: ";
		cin >> numberOfYears; //Gets user input
		//While loop keeps looping until user enters a positive number
		while (numberOfYears < 0) {
			cout << "Please enter a positive number" << endl;
			cout << "Number of Years: ";
			cin >> numberOfYears; //Gets user input again until 0 or greater
		}
		cout << endl;
		system("pause"); //Displays "Press any key to continue..."
		cout << endl;
	}

	return 0; //Return statement
}