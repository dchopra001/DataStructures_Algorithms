#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

/*****************************************
 * UW User ID:  dchopra
 * Submitted for ECE 250
 * Semester of Submission:  Winter 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "Exception.h"
#include "ece250.h"

enum state { EMPTY, OCCUPIED, DELETED };

template<typename T>
class DoubleHashTable {
	private:
		int count; //number of elements in the hash table
		int power;	//size of hash table (hence array) = 2^power
		int array_size;	//size of the array
		T *array;		//declaration of hash array
		state *occupied; //declaration of state array

		int h1( T const & ) const; // first hash function
		int h2( T const & ) const; // second hash function

	public:
		DoubleHashTable( int = 5 );
		~DoubleHashTable();
		int size() const;
		int capacity() const;
		double load_factor() const;
		bool empty() const;
		bool member( T const & ) const;
		T bin( int ) const;

		void print() const;

		void insert( T const & );
		bool remove( T const & );
		void clear();
};

template<typename T >
DoubleHashTable<T >::DoubleHashTable( int m ):
count( 0 ), power( m ),
array_size( 1 << power ),
array( new T [array_size] ),
occupied( new state[array_size] ) {

	for ( int i = 0; i < array_size; ++i ) {
		occupied[i] = EMPTY;
	}
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
	delete [] array;
	delete [] occupied;
	// enter your implemetation here 
}

template<typename T >
int DoubleHashTable<T >::size() const {
	return count;
    // enter your implementation here 
	return 0;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    // enter your implemetation here 
	return array_size;
	return 0;
}

template<typename T >
double DoubleHashTable<T >::load_factor() const {
    // enter your implemetation here 
	return ((double)count)/((double)array_size);
	return 0.00;
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
    // enter your implemetation here 
	if(count == 0)
		return true;
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
//determined the index value at whic to insert the value called "obj"	
	int x = ((int)obj)%array_size; 
	if(x<0)
		return x+array_size;
	return x;
	// enter your implemetation here 

	return 0;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
	//hash function
	int y = ((int)(obj/array_size))%array_size;
	//if y is negative, make it positive
	if (y<0)
		y = y+array_size;
	//if y is even, make it odd
	if(y%2 == 0)
		return y+1;
	return y;
	// enter your implemetation here 


	return 0;
}

template<typename T>
bool DoubleHashTable<T >::member( T const &obj ) const {
//get the index and jump (probe and offset)
	int index = h1(obj); 
	int jump = h2(obj);	
	
	for(int i = 0; i<array_size; i++)
	{	//accounts for jump
		int key  = (index + i*jump)%array_size; 
////makes sure its the value we are looking for and not garbage
		if(array[key] == obj && occupied[key] == OCCUPIED) 
			return true;
		//if either is true, we don't need to run loop any further
		else if(occupied[key] == EMPTY || occupied[key] == DELETED) 
			return false;
	}
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
    // enter your implemetation here
	return array[n];
                    
	return T();
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
//throw exception if array is full	
	if(count == array_size)
		throw overflow();
//find probe, offset values
	int probe = h1(obj);
	int offset = h2(obj);
//find the first possible empty or deleted box
	while(occupied[probe] == OCCUPIED)
		probe = (probe+offset)%array_size;
//set the box to the value specified
	array[probe] = obj;
//update all variables to ensure state and count is consistent
	count = count+1;
	occupied[probe] = OCCUPIED;
	// enter your implemetation here 	
	 //return ; 
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
//calculate probe and offsets and initialize a temporary count value
	int probe = h1(obj);
	int offset = h2(obj);
	int tempCount = 0;
	
//loop to find the value in the table and then remove it 
	while(occupied[probe] != EMPTY && tempCount<array_size)
	{
		if(array[probe] == obj && occupied[probe] == OCCUPIED)
		{
			occupied[probe] = DELETED;
			count = count --;
			return true;
		}
		probe = (probe+offset)%array_size;
		tempCount++;

	}

	// enter your implemetation here 	

	return false;
}

template<typename T >
void DoubleHashTable<T >::clear() {
//Declare new arrays for data and states
		T *newArray;
		newArray = new T[array_size];

		state *newOccupied;
		newOccupied = new state[array_size];
		//initialize the new state array
		for(int i = 0; i<array_size;i++)
			newOccupied[i] = EMPTY;
		//reset count
		count = 0;
		//delete the pointers to the old array
		delete [] array;
		delete [] occupied;
		//reset the pointers to the new arrays
		occupied = newOccupied;
		array = newArray;


	 // enter your implemetation here 	
	 return ; 
}

template<typename T >
void DoubleHashTable<T >::print() const {
    /*cout<<"Here are the Hash Table Contents"<<endl;
	cout<<"--------------------------------"<<endl<<endl;
	cout<<"Here is the Table Data: "<<endl<<endl;
	for(int i = 0; i<array_size; i++)
	{
		cout<<"INDEX: "<<i<<", VALUE: "<<bin(i)<<", STATE: "<<occupied[i]<<endl;
	}
	cout<<endl<<"Here General Info about the HashTable: "<<endl;
	cout<<      "---------------------------------------"<<endl;

	cout<<"COUNT (size): "<<size()<<" ARRAYSIZE (capacity): "<<capacity();
	cout<<" LOADFACTOR: "<<load_factor()<<" ISEMPTY: "<<empty();
	cout<<" POWER: "<<power<<endl<<endl;
	// enter your implemetation here 	
	//return;*/


}





#endif


