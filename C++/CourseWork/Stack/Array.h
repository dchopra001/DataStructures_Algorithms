#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

#include "Exception.h"

/*****************************************
 * UW User ID:  dchopra
 * Submitted for ECE 250
 * Semester of Submission:  Winter 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
 
 
 
template <typename T>
class Array {
        private:
                T *array;
                int array_size;

        public:
                Array( int = 10 );
                ~Array();

                // accessors
                T get( int ) const;
                 int size() const;

                // mutators
                void set( int, T );
                void resize( int );
};

//Functions are initialized below
template <typename T> 
Array<T>::Array( int n ) {
	
	array_size=n;					 //set array_size to n
	array = new T[array_size];	 //create new array object
	for(int i = 0; i<array_size;i++) //initialize each value to 0
		array[i] = 0;
              
              
}

template <typename T> Array<T>::~Array() {

	delete [] array;	//delete array (Destructor)
}


template <typename T> T Array<T>::get( int n ) const {

	if ( n>=0 && n<array_size)	//check if n is within range of array
		return *(array+n);		//if yes, return array value at n
	else
		throw ArrayBoundsException(); //else throw exception
	
    
}


template <typename T> int Array<T>::size() const {
   return array_size;		//return integer stored in array_size
}

template <typename T> 

void Array<T>::set( int n, T value ) 
{
	//check to make sure n is within the bounds of the array size
	if ( n>=0 && n<array_size) 
		array[n] = value ;
	   //*(array + n) = value;   //if true,equate array to specified value
	else
		throw ArrayBoundsException();  //if not, throw exception
     
}

template <typename T> void Array<T>::resize( int n ) 
{
	T *newArray;        //declare/initialize a new array
		newArray = new T[n]; 

if(n<=array_size)		//if the new size is less/equal to old size 
{
	for(int i = 0; i<n; i++) //set first n values of array to newArray
		newArray[i] = array[i];
}
else	//in all other cases (n>array size)
{
	for(int i = 0; i<array_size;i++)   //copy all values from old array
		newArray[i] = array[i];  

	for(int i = array_size;i<n;i++)   //for the remaining values, set
		newArray[i] = 0;			  //them equal to 0
}
	delete [] array;  //delete stored values in array
	array = newArray;  //set array pointer to newArray pointer
	array_size = n;		//set array_size to n. 
}



#endif


