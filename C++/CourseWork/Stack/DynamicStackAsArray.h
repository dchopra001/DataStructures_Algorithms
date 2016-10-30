#ifndef DYNAMIC_STACK_AS_ARRAY_H
#define DYNAMIC_STACK_AS_ARRAY_H

/*****************************************
 * UW User ID:  dchopra
 * Submitted for ECE 250
 * Semester of Submission:  Winter 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
 
 #include <iostream>
using namespace std;

#include "Exception.h"
#include "Array.h"

template <typename T>
class DynamicStackAsArray {
	private:
		
		Array<T> *stack ; 
		int ihead, count, initial_size, array_size;

	public:
		DynamicStackAsArray( int = 10 );
		~DynamicStackAsArray();

		T top() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void push( T const & );
		T pop();
		void clear();
		void print();
	
        void stackResize(int ) ;
};
//For the constructor,initialize all variables and 
//create a new instance of Array, callling it stack
//ihead initialized to -1 since ihead is the index
//of the array as well as the top of the stack
template <typename T>
DynamicStackAsArray<T>::DynamicStackAsArray( int n ):
count( 0 ),
initial_size( n ),
array_size( n ) {            
      
	   stack = new Array<T>(array_size);
	   // What initial value will you give to ihead ?
		ihead = -1;
}

//delete the pointer stack from memory
template <typename T>
DynamicStackAsArray<T>::~DynamicStackAsArray() {
	// Enter your implementation
	delete stack;
}

//if ihead = -1, it indicates there are no elements
//in stack. so error will be thrown, else 
//the method returns the value at the top of the stack
//which is at the index "ihead" in the array
template <typename  T>
T DynamicStackAsArray<T>::top() const {
    
   // Enter your implementation
	if(ihead == -1)
		throw underflow();
	else
		return stack->get(ihead);
      
}
//number of elements in stack = count = size of stack
//hence the value fo the size variable is returned
template <typename T>
int DynamicStackAsArray<T>::size() const {
	// Enter your impleme ntation
	return count;
}

//if stack is empty, we return true. else false
//if ihead = -1, we have no elements in stack
//so true will only be returnd if ihead = -1
template <typename T>
bool DynamicStackAsArray<T>::empty() const {
	// Enter your implementation:
	if(ihead == -1)
		return true;
	else
		return false;
}

//capacity is basically the size of the array!
//so we call the size method of the array, which
//is pointed to by the variable stack
template <typename T>
int DynamicStackAsArray<T>::capacity() const {
	// Enter your implementation
	return stack->size();
}
//first we check if count == array size.
//this indicates if array is full. if yes, then we 
//double the size. following that, we add a new element
//to the stack and adjust the value of ihead, arraysize,
//and count accordingly. 
template <typename T>
void DynamicStackAsArray<T>::push( T const &obj ) {
     // Enter your implementation
	if(count == array_size)
	{
		stack->resize(2*array_size);
	}
		ihead = ihead + 1;
		stack->set(ihead, obj);
		array_size = stack->size();
		count = count +1;
}

//first we check if stack is empty (call the empty method)
//if yes, then there is nothing to return OR pop. so we 
//throw an error. after that we pop the top of the 
//stack and adjust all variables. 
//lastly, we check if we have reached a quarter of the 
//array size in our stack. if yes, then resize to half.
template <typename T>
T DynamicStackAsArray<T>::pop() {

	T tmp;
	
	if(empty())
	{
		throw underflow();
	}
	else
	{
		
		
		ihead = ihead - 1;
		count = count - 1;
		tmp = stack-> get(ihead+1);
		stack->set(ihead+1, 0);
	}

		
	
	if(count == (array_size/4) && array_size>initial_size)
	{
		if(array_size/2 < initial_size)
			stack->resize(initial_size);
		else
			stack->resize(array_size/2);
		
		
	}
	array_size = stack->size();
	return tmp;
	 // Enter your implementation
}


//delete original stack, set equal to a new stack
//and reinitialize all values to those in the constructor
template <typename T>
void DynamicStackAsArray<T>::clear() {
     // Enter your implementation
	delete stack;
	stack = new Array<T>(initial_size);
	ihead =-1;
	count =0;
	stack->resize(initial_size);
	array_size = initial_size;
}


//the print method is used for testing. 
template <typename T>
void DynamicStackAsArray<T>::print() {

if(ihead == -1)
cout<<"The stack is empty"<<endl;
else
{
	for(int i =0; i<=ihead;i++)
		cout<<"Element "<<i<<": "<<stack->get(i)<<endl;



}
	cout<<"Stack size: "<<size()<<endl;
	cout<<"Stack Capacity: "<<capacity()<<endl;
	cout<<"ihead: "<<ihead<<endl;
	cout<<"count: "<<count<<endl;
	cout<<"initial size: "<<initial_size<<endl;

}




#endif
