// ---------------------------------------------------------------
// Programming Assignment:	CIS170C Lab 7
// Developer: iGageit
// Date Written: 2020-12-12	
// Purpose:	Store and retrieve names and addresses in a
//			sequential text file in CSV format. 
// ---------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// function prototypes
void EnterAndWriteAddresses(void); //Accept address records from user, write to file
void ReadAndDisplayAddresses(void); //Read address records from file, display

const string ADDRESS_FILE_NAME = "Address.csv"; // file name for address data file

// main program -- displays main menu and processes user selection
int main()

{
	int choice;

	cout << "Address Record Application" << endl << endl;

	// loop that continues until the user exits
	do
	{
		// main menu loop here with options for
		cout << "Please choose one of the following options: " << endl;
		cout << "1) Enter new address records" << endl;
		cout << "2) Display address records" << endl;
		cout << "3) Exit the program" << endl;
		cout << "Enter choice: ";
		cin >> choice;


		if (choice == 1) // input addresses and write to file
		{
			EnterAndWriteAddresses();
		}
		else if (choice == 2) // read address from file and output to console
		{
			ReadAndDisplayAddresses();
		}
		else if (choice != 3)
		{
			// Display error message if invalid choice is entered
			cout << "Invalid choice ---- please enter 1, 2 or 3" << endl;
		}

		cout << endl;
	} while (choice != 3);

	cout << "Thank you for using the Address Record Application." << endl;
	system("pause");

	return 0;
}

// Enter address records and write to address file
void EnterAndWriteAddresses(void)
{

	// Declare variables for name and address fields
	string name, street, city, state, zip;
	char choice;
	// Open address file for output using ofstream()
	ofstream fout(ADDRESS_FILE_NAME, std::ofstream::app); // open file in append mode
	// Loop to accept and write addresses
	do
	{
		cin.ignore(100, '\n'); // ignore \n left by cin
		// Prompt user to enter name and address fields
		cout << endl << "Name: ";
		getline(cin, name);
		cout << "Street Address: ";
		getline(cin, street);
		cout << "City: ";
		getline(cin, city);
		cout << "State: ";
		getline(cin, state);
		cout << "Zip Code: ";
		getline(cin, zip);
		// Write entered data to address file separated by commas
		fout << name << "," << street << "," << city << "," << state << "," << zip;
		// Ask user if more addresses to enter
		cout << "Enter another address (Y/N)? ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
			fout << endl;
	} while (choice == 'y' || choice == 'Y'); // Repeat loop while user responds 'Y' or 'y'

	// Close address file
	fout.close();

}

// Read records from address file and display to user
void ReadAndDisplayAddresses(void)
{

	string name, street, city, state, zip;

	ifstream inputAddress(ADDRESS_FILE_NAME); // open address file for input

	if (inputAddress.is_open()) {

		//read and display all records from address file
		while (getline(inputAddress, name, ',')) { //read name field

			getline(inputAddress, street, ','); //read street field
			getline(inputAddress, city, ','); // read city field
			getline(inputAddress, state, ','); // read state field
			getline(inputAddress, zip, '\n'); // read zip field

			// output the fields to console
			cout << endl << left << setw(20) << "Name: " << name << endl;
			cout << left << setw(20) << "Street address: " << street << endl;
			cout << left << setw(20) << "City: " << city << endl;
			cout << left << setw(20) << "State: " << state << endl;
			cout << left << setw(20) << "Zip Code: " << zip << endl;

		}

		inputAddress.close(); //close address file

	}

}

//end of program
