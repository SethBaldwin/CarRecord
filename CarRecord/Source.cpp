// SETH BALDWIN
// CS-217 DATA STRUCTURES & ALGORITHMS
// FOR: PROF. BO KIM


#include "CarRecord.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void readFile(UnsortedType&);

int main()
{
	// In to take user input to continue
	int cont;

	// List used to store the info in the file read as well as inputted.
	UnsortedType carlist;

	// A pre-made car record to be input into the list. Could be done with user input very simply With a few variables.
	CarRecord userIn("Jeep", "Wrangler", "SUV", 2002, 12345);

	// A second pre-made car record to be input into the list.
	CarRecord userIn2("Ford", "Raptor", "Truck", 2002, 12345);

	// TEST COPY CONSTRUCTOR 
	UnsortedType testCopy(carlist);
	testCopy.InsertItem(userIn2);

	// TEST OVERLOADED = COPY CONSTRUCTOR
	UnsortedType testCopy2 = testCopy;
		//By printing testCopy at 0 i can confirm both copy constructors work.
	testCopy.print(0);

	// DESTRUCTOR
	testCopy.~testCopy();
	testCopy2.~testCopy2();

	cout << "Would you like to run this test driver? Yes(1) No(2) \n";
	cin >> cont;

	if (cont == 2)
		return 0;

	cout << "\nThank you for starting the test driver! \n\n\n";

	cout << "~~~~~~~~~~ READING FILE ~~~~~~~~\n";
	// Reads in file and stored information into car list.
	readFile(carlist);
	// Little loading bar that is completely unnecessary
	Sleep(700); cout << "\t . "; Sleep(700); cout << " . "; Sleep(700); cout << " . "; Sleep(700); cout << " . ";  
	Sleep(700); cout << " . \n\n"; Sleep(900);
	cout << "~~~~~ FILE SUCCESSFULLY READ! ~~~~~\n\n";
	cout << "  Press enter to print the list. \n";
	cin.get();
	cin.get();

	// Calls the print all function that will display all the items in the carlist
	carlist.print_all();
	
	// Adds the pre-made item
	cout << "Press enter to add a 2002 Jeep Wrangler with 12345 miles to the list. \n";
	cout << "(This will use InsertItem(item) to put that record into the list) \n\n";
	cin.get();

	// INSERT ITEM
	carlist.InsertItem(userIn);
	carlist.print_all();
	cout << "You will see the Jeep has been added in the proper location. \n\n";

	//RETRIEVE ITEM
	cout << "I will now call the RetrieveItem function on that same item and \n";
	cout << "display that variable returned. It is a bool function. \n\n";
	cout << carlist.RetrieveItem(userIn) << endl << endl; 
	cout << "As you can see a 1 was returned indicating it was found. \n\n";
	cout << "I will now call same RetrieveItem function on an item \n";
	cout << "that is not in the list. IT will return 0\n\n";
	cout << carlist.RetrieveItem(userIn2) << endl << endl;
	cout << "Press enter to continue \n\n";
	cin.get();

	//DELETE ITEM
	cout << "I will now call the DeleteItem function on an the item added and print.\n\n";
	cout << " Press enter: ";
	cin.get();
	carlist.DeleteItem(userIn);
	carlist.print_all();
	cout << "You will see the jeep is no longer in the list\n\n";
	cout << " Press enter: \n\n";
	cin.get();

	// ISFULL
	cout << "I will now test the IsFull Function\n";
	cout << "It will return 1 if it is full and 0 if it is not.\n\n";
	cout << carlist.IsFull() << endl << endl;
	cout << " Press enter: \n\n";
	cin.get();

	// LENGTH
	cout << "I will now test the LengthIs Function\n";
	cout << "It will return The length of the list.\n\n";
	cout << carlist.lengthIs() << endl << endl;
	cout << " Press enter: \n\n";
	cin.get();

	// print(x)
	cout << "I will call the print function to print a specific index\n";
	cout << "In this case i will print index 0 which is the Acura\n";
	carlist.print(0);
	cout << " Press enter: \n\n";
	cin.get();

	// SEARCH
	cout << "I will insert a new item with a Ford Raptor in it.\n";
	cout << "Specifically, 2002 Ford Raptor with 12345 miles\n";
	cout << "Then, i will use the search function to look for, and print it.\n\n";
	carlist.InsertItem(userIn2);
	carlist.search(userIn2);
	cout << " Press enter: \n\n";
	cin.get();

	// UPDATE
	CarRecord userIn3("Ford", "Raptor", "Truck", 1929, 54321);
	cout << "I will now test the Update function.\n";
	cout << "I have created a new record similar to the last one except:\n";
	cout << "It now is year 1929 and has 54321 miles\n";
	cout << "Then, i will the whole list.\n\n";
	cout << " Press enter: \n\n";
	cin.get();
	carlist.update(userIn3);
	carlist.print_all();
	cout << "You will see the info for the Ford has changed: \n\n";
	cout << " Press enter: \n\n";
	cin.get();

	// AVERAGE
	cout << "I will print the average car year: \n\n";
	cout << carlist.average() << endl << endl;
	cout << " Press enter: \n\n";
	cin.get();
	

	// OPERATOR OVERLOADS
	CarRecord a("Ford", "Raptor", "Truck", 2002, 12345);
	CarRecord b("Ford", "Mustang", "Coupe", 2002, 12345);
	CarRecord c("Jeep", "Wrangler", "SUV", 2002, 12345);
	cout << "I will demonstrait the outputs of my overloaded operators here: \n";
	cout << "Item a will be: Ford Raptor \n";
	cout << "Item b will be: Ford Mustang \n";
	cout << "Item c will be: Jeep Wrangler \n \n";

	cout << "Is a < b. Expected 0 (false) \n";
	cout << (a < b) << endl << endl;

	cout << "Is a > b. Expected 1 (true) \n";
	cout << (a > b) << endl << endl;

	cout << "Is a < c. Expected 1 (true) \n";
	cout << (a < c) << endl << endl;

	cout << "Is a == a. Expected 1 (true) \n";
	cout << (a == a) << endl << endl;

	cout << "Is a != c. Expected 1 (true) \n";
	cout << (a != c) << endl << endl;

	cout << "END OF PROGRAM";
	cin.get();
	cin.get();
	return 0;
}

// Reads in the specified file
void readFile(UnsortedType &inList)
{
	CarRecord newRecord;
	string line;
	ifstream inFile;
	inFile.open("record2.txt");

	while (!inFile.eof()){
		inFile >> line;
		newRecord.car_make = line;
		
		inFile >> line;
		newRecord.car_model = line;

		inFile >> line;
		newRecord.car_type = line;

		inFile >> line;
		newRecord.car_year = atoi(line.c_str());

		inFile >> line;
		newRecord.car_mileage = atoi(line.c_str());

		inList.InsertItem(newRecord);
	}

	
	inFile.close();
}