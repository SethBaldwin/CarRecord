#include "CarRecord.h"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

									/********************************************

													CONSTRUCTORS

									*********************************************/

// Default constructor
// Pre: None.
// Post: list is empty.
UnsortedType::UnsortedType()
{
	// The first item in a linked list is refered to as the head.
	// In the Default constructor it will be NULL as it has just been created.
	head = NULL; 

	// Keeps track of how long the list is.
	// In the Default constructor it will be 0 as it has just been created.
	length = 0;
}

// Destructor
// Pre: An object exists.
// Post: The list is destroyed.
UnsortedType::~UnsortedType()
{
	// ptr will be used as a pointer to traverse each object in the list 
	NodeType* ptr = head; 

	//If the list is empty it will not delete any items
	while (head != NULL){

		// Points the next object
		ptr = head->next;

		// Deletes the head
		delete head;

		// Makes head what ptr was pointing to
		head = ptr;
	}
}

// Copy Constructor (A deep-copy)
// Pre: An object exists.
// Post: A copy of the list has been made
UnsortedType::UnsortedType(const UnsortedType& acopy) 
{
	// 2 Nodetype pointer that will be used to reference the current and previous node
	NodeType* ptr;
	NodeType* last;

	//Checks if acopy is empty
	if (acopy.head == NULL){
		// If it is, it makes another empty list.
		head = NULL;
	}
	else{
		// Makes the information stored in head = to the info stored in acopy's head.
		// It sets the next pointer = to NULL because it doesnt know whre to point to yet
		head = get_node(acopy.head->info, NULL);

		// Sets last = head
		last = head;

		// Sets ptr to point to the item after head
		ptr = acopy.head->next;

		// Checks if the ptr is pointing to nothing
		// If the list contained only 1 item it would stop here
		while (ptr != NULL){
			// These statements go though the items in acopy and copys them to the new list
			last->next = get_node(ptr->info, NULL);
			last = last->next;
			ptr = ptr->next;
		}
	}
}

// This function is used to create a new node with the information passed
NodeType* UnsortedType::get_node(const ItemType& info, NodeType* next)
{
	// Makes a new, temporary node
	NodeType* temp = new NodeType;

	// temp's info will be stored as the info passed to it.
	temp->info = info;
	// temp's next will be stored as the next passed to it.
	temp->next = next;
	return temp;
}

// Copy Constructor Operator Overload (A deep-copy)
// Pre: An object exists.
// Post: A copy of the list has been made
void UnsortedType::operator= (const UnsortedType& acopy)
{
	//Czech for self-assignment
	if (this == &acopy) return;


	//*** Same as the copy constructor ***//


	// 2 Nodetype pointer that will be used to reference the current and previous node
	NodeType* ptr;
	NodeType* last;

	//Checks if acopy is empty
	if (acopy.head == NULL){
		// If it is, it makes another empty list.
		head = NULL;
	}
	else{
		// Makes the information stored in head = to the info stored in acopy's head.
		// It sets the next pointer = to NULL because it doesnt know whre to point to yet
		head = get_node(acopy.head->info, NULL);

		// Sets last = head
		last = head;

		// Sets ptr to point to the item after head
		ptr = acopy.head->next;

		// Checks if the ptr is pointing to nothing
		// If the list contained only 1 item it would stop here
		while (ptr != NULL){
			// These statements go though the items in acopy and copys them to the new list
			last->next = get_node(ptr->info, NULL);
			last = last->next;
			ptr = ptr->next;
		}
	}
}



									/********************************************

													Member Functions

									*********************************************/


// Pre: none
// Post: If a new node cannot be created, there is no more room in momory and will return true
bool UnsortedType::IsFull() const{
	// ptr is used as a local pointer.
	NodeType* ptr;
	ptr = new NodeType();
	if (ptr == NULL)
		return true;
	delete ptr;
	
	return false;
}

// Pre: none
// Post: Returns the length of the list
size_t UnsortedType::lengthIs() const{
	return length;
}

// Pre: list is not empty
// Post: Returns if there is a item
bool UnsortedType::RetrieveItem(ItemType item) const{
	// ptr will be used as a pointer to traverse each object in the list 
	NodeType* ptr = head;

	// The lop will continue to run as long as the node does not point to null
	while (ptr != NULL){
		// This statement checks if the car's make and model are the same
		if (ptr->info.car_make == item.car_make && ptr->info.car_model == item.car_model)
			return true;
		
		// Goes to the next pointer if they are not the same
		ptr = ptr->next;
	}

	// If the item cannot be found than false is returned
	return false;
}

// Pre: list is not full
// Post: Item is inserted in the next space
void UnsortedType::InsertItem(ItemType item){
	// ptr will be used as a pointer to traverse each object in the list 
	NodeType* ptr = head;
	// prev points to the last node so if an object needs to be inserted after it we can change what it points to
	NodeType* prev;

	//The new item to be inserted
	NodeType* temp = new NodeType;

	//For an empty list
	if (head == NULL){
		temp->info = item;	// Temp's info is now = item
		temp->next = head;	// Temp points to head
		head = temp;		// Head is now = to temp
		length++;			// Increments length
	}
	else {
		//IF ITEM SHOULD COME BEFORE HEAD - IM PRETTY SURE THIS IS GOOD
		if (item < head->info){
			temp->info = head->info;// Saves heads info into temp
			head->info = item;		// Saves item into head's info
			temp->next = head->next;// Makes temp point to what head is pointing to
			head->next = temp;		// Makes head point to temp
			length++;				// Increments length
		}
		else{
			while (item > ptr->info){ // While item is greater than current info do
				// These lines move the current process forward
				// ptr keeps track of the current item being examined
				// prev specifically is there so we can change what it points
				prev = ptr; 
				ptr = ptr->next;

				// If we have reached the last item in the list we know it needs to go at the end
				if (ptr == NULL && item > prev->info)
				{
					temp->info = item;	// Temp's info is now = item 
					temp->next = NULL;	// Because it is the end of the list it will point to know
					prev->next = temp;	// The prev item now needs to point this 
					length++;			// Increments length
					return;
				}

				//	If item alphabetically comes before the info in the current location
				//	we know that item needs to come before ptr and after prev
				else if (item < ptr->info )
				{
					temp->info = item;	// Temp's info is now = item 
					temp->next = ptr;	// Temp now points to ptr
					prev->next = temp;	// prev now points to temp
					length++;			// Increments length
					return;
				}

				// This section is suspiciouslly like the one 2 above. But im not sure if they are diffent.
				// and im too tired to see why i have it here.
				// its also really late so i dont want to waste any more time figuring it out.
				else if (ptr->next == NULL)
				{
					temp->info = item;	// I think we can guess what this does
					temp->next = NULL;	// temp points to null
					ptr->next = temp;	// yeah im pretty sure they do the same thing
					length++;			// Increments length
					return;
				}
			}
		}
	}
}

// Pre: Item exists and list is not empty.
// Post: If item exists it will be removed, It item does not exits it will retrn false.
void UnsortedType::DeleteItem(ItemType item){
	// These are pointers used to keep track of locations
	NodeType* ptr = head;
	NodeType* prev = head;

	//  Will loop until it finds the item
	while (ptr->info != item){
		// These lines move the current process forward
		// ptr keeps track of the current item being examined
		// prev specifically is there so we can change what it points
		prev = ptr; 
		ptr = ptr->next;
	}
	if (head == ptr)
		head = ptr->next; // Makes head = to what head points to

	// I think it does the same thing
	prev->next = ptr->next; 

	// Deletes ptr
	delete ptr;

	//	Decrements length
	length--;
}

// Pre: Item exists and list is not empty.
// Post: It prints all the items
void UnsortedType::print_all() const
{
	// The same prt as we have always used 
	NodeType* ptr = head;

	// Loops
	while (ptr != NULL)
	{
		cout << "Make: \t \t" << ptr->info.car_make << endl;
		cout << "Model: \t \t" << ptr->info.car_model << endl;
		cout << "Type: \t \t" << ptr->info.car_type << endl;
		cout << "Year: \t \t" << ptr->info.car_year << endl;
		cout << "Mileage: \t" << ptr->info.car_mileage << endl << endl;
		ptr = ptr->next;
	}
	cout << "------------END------------- \n";
	cout << endl;
}

// Pre: Item exists and list is not empty.
// Post: It prints the item at index
void UnsortedType::print(int index) const
{
	if (index > length || length == 0)
		return;

	NodeType* ptr = head;

	for (int i = 0; i < index; i++)
		ptr = ptr->next;

	cout << "Make: \t \t" << ptr->info.car_make << endl;
	cout << "Model: \t \t" << ptr->info.car_model << endl;
	cout << "Type: \t \t" << ptr->info.car_type << endl;
	cout << "Year: \t \t" << ptr->info.car_year << endl;
	cout << "Mileage: \t" << ptr->info.car_mileage << endl << endl;
	cout << "------------END------------- \n";
	cout << endl;
}

// Pre: Item exists and list is not empty.
// Post: It prints the item
void UnsortedType::search(ItemType item)const
{
	// Checks if the item exists, if it doesnt it exits
	if (!RetrieveItem(item))
		return;

	// Same as always
	NodeType* ptr = head;
	int x = 0; // X is used as a counter

	// Loops finds the index where item is
	while (item != ptr->info){
		x++;
		ptr = ptr->next;
	}

	// Prints the index with item
	print(x);
}

// Pre: none
// Post: if the item exits it updates it. If the item doesnt exits it inserts it
void UnsortedType::update(ItemType item)
{
	// If the item doesnt exits it inserts it and exits
	if (!RetrieveItem(item)){
		InsertItem(item);
		return;
	}

	// Same as always
	NodeType* ptr = head;
	int x = 0; // X is used as a counter

	// Loops finds the index where item is
	while (item != ptr->info){
		x++;
		ptr = ptr->next;
	}

	// Updates the info at this index
	ptr->info = item;

	// prints
	print(x);
}

// Pre: list is not empty
// Post: returns the average year of all the cars in the list
int UnsortedType::average()
{
	int avg = 0; // Integer to store the sum of all the years

	// Looks familiar
	NodeType* ptr = head;
	for (int i = 0; i < length; i++)
	{
		avg += ptr->info.car_year;	// The year of the car at this index is added to avg
		ptr = ptr->next;			// Goes to the next node
	}

	// Calculates average by dividing sum by the length
	return avg / length; 
}

// Pre: Im not sure, Probably not empty
// Post: I really am not sure
void UnsortedType::get_next()
{
	// "A get next function which will return the record of the current position. 
	// It is an iterator"
	// Im not sure what this function is supposed to do.
	// What in this program is the "current position"?
	// and why is it an iterator?
}


									/********************************************

												OPPERATOR OVERLOADS

									*********************************************/


// Checks if the two items are the same
bool operator== (const ItemType& a, const ItemType& b)
{
	if (a.car_make == b.car_make && a.car_model == b.car_model)
		return true;
	else
		return false;
}

// Checks if the two items are not the same
bool operator!= (const ItemType& a, const ItemType& b)
{
	if (a.car_make == b.car_make && a.car_model == b.car_model)
		return false;
	else
		return true;
}

// Checks if a comes alphabetically before b
bool operator< (const ItemType& a, const ItemType& b)
{
	if (a.car_make == b.car_make){
		if (a.car_model < b.car_model)
			return true;
		else if (a.car_model > b.car_model)
			return false;
	}
	else if (a.car_make != b.car_make){
		if (a.car_make < b.car_make)
			return true;
		else if (a.car_make > b.car_make)
			return false;
	}
}

// Checks if b comes alphabetically before a
bool operator> (const ItemType& a, const ItemType& b)
{
	if (a.car_make == b.car_make){
		if (a.car_model > b.car_model)
			return true;
		else if (a.car_model < b.car_model)
			return false;
	}
	else if (a.car_make != b.car_make){
		if (a.car_make > b.car_make)
			return true;
		else if (a.car_make < b.car_make)
			return false;
	}
}

