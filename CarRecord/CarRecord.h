#pragma once
#include <string>

using namespace std;

// Struct to store all information about the cars.
struct CarRecord
{
	string car_make; // I think these variable names are self explanitory
	string car_model;
	string car_type;
	int car_year;
	int car_mileage;

	// Default constructor (I know this wasnt necessary but it made my test driver easier)
	CarRecord(){ car_make = ""; car_model = ""; car_type = ""; car_year = 0; car_mileage = 0; }; 

	// Overloaded constructor (I know this wasnt necessary but it made my test driver easier)
	CarRecord(string make, string model, string type, int year, int mileage)
	{ car_make = make; car_model = model; car_type = type; car_year = year; car_mileage = mileage;};
};

typedef CarRecord ItemType; // Typre def statement 

// The nodes
struct NodeType
{
	ItemType info;  // Stores the car record
	NodeType* next; // Will store the address of the next node in the Linked List
};

class UnsortedType
{
public:
	// Default constructor
	// Pre: None.
	// Post: list is empty.
	UnsortedType(); 

	// Destructor
	// Pre: An object exists.
	// Post: The list is destroyed.
	~UnsortedType(); 

	// Copy Constructor (A deep-copy)
	// Pre: An object exists.
	// Post: A copy of the list has been made
	UnsortedType(const UnsortedType &); 

	// Copy Constructor Operator Overload (A deep-copy)
	// Pre: An object exists.
	// Post: A copy of the list has been made
	void operator = (const UnsortedType &);

	// Pre: none
	// Post: If a new node cannot be created, there is no more room in momory and will return true
	bool IsFull() const;

	// Pre: none
	// Post: Returns the length of the list
	size_t lengthIs() const;

	// Pre: list is not empty
	// Post: Returns if there is a item
	bool RetrieveItem(ItemType item) const;

	// Pre: list is not full
	// Post: Item is inserted in the next space
	void InsertItem(ItemType item);

	// Pre: Item exists and list is not empty.
	// Post: If item exists it will be removed, It item does not exits it will retrn false.
	void DeleteItem(ItemType item);

	// Pre: Item exists and list is not empty.
	// Post: It prints all the items
	void print_all() const;

	// Pre: Item exists and list is not empty.
	// Post: It prints the item at index
	void print(int index) const;

	// Pre: Item exists and list is not empty.
	// Post: It prints all the item
	void search(ItemType item) const;

	// Pre: none
	// Post: if the item exits it updates it. If the item doesnt exits it inserts it
	void update(ItemType item);

	// Pre: list is not empty
	// Post: returns the average year of all the cars in the list
	int average();

	// Pre: Im not sure, Probably not empty
	// Post: I really am not sure
	void get_next();

private:
	// Keeps track of how long the list is.
	int length; 

	// The first item in a linked list is refered to as the head.
	NodeType* head;	

	// This function is used to create a new node with the information passed
	// Creates a new node that contains the item of the current node and points to null
	// And Honestly, I'm Not exactly sure I need it, but it works and I'm out of time.
	NodeType* get_node(const ItemType& entry, NodeType* link); 
};

//Operator overloads
bool operator== (const ItemType&, const ItemType&);
bool operator!= (const ItemType&, const ItemType&);
bool operator< (const ItemType&, const ItemType&);
bool operator> (const ItemType&, const ItemType&);