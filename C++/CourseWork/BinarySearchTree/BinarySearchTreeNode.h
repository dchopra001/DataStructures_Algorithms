#ifndef NODE_H
#define NODE_H

/*****************************************
 * UW User ID:  dchopra
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  Winter 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "ece250.h"


template <typename Type>
class BinarySearchTree;


template <typename Type>
class BinarySearchTreeNode{
	private:
		Type       x_value;	
        
	
		BinarySearchTreeNode<Type> *right;
		BinarySearchTreeNode<Type> *left;
		
		

	public:
           
         
  
		BinarySearchTreeNode<Type>( const Type  & = Type());
		~BinarySearchTreeNode();

		Type retrieve() const;
	

		BinarySearchTreeNode *get_right() const;
		BinarySearchTreeNode *get_left() const;
		

		Type min() const;
	
		Type max() const;

		Type sum() const;
		

		bool member( const Type & ) const;

		bool insert( const Type & );
		void clear();

	friend class BinarySearchTree<Type>;
};


template <typename Type>
BinarySearchTreeNode<Type>::BinarySearchTreeNode( const Type  &x ):
x_value( x ),  
right( 0 ),
left( 0 )
{
	// empty constructor
}

template <typename Type>
BinarySearchTreeNode<Type>::~BinarySearchTreeNode(){
    // empty destructor      
                                                   
}


template <typename Type>
Type BinarySearchTreeNode<Type>::retrieve() const {
	return x_value;
}



template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTreeNode<Type>::get_left() const {
	return left;
}

template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTreeNode<Type>::get_right() const {
	return right;
}


template <typename Type>
Type BinarySearchTreeNode<Type>::min() const {
	// you may use std::min

	if(left !=0)
		return left->min();
	return x_value;
	
	//return Type();
}



template <typename Type>
Type BinarySearchTreeNode<Type>::max() const {
	// you may use std::max
	if(right !=0)
		return right->max();
	return x_value;
	//return Type();
}



template <typename Type>
Type BinarySearchTreeNode<Type>::sum() const {
	
	
	if ( this == 0 ) {
		// hint...
		return 0;
	} else {
		return x_value + left->sum() + right->sum();
		//return 0;
	}
}



template <typename Type>
bool BinarySearchTreeNode<Type>::member( const Type &x) const {
	if ( this == 0 )
		return false;
	if(x_value==x)
		return true;
	if(x<x_value)
		return left->member(x);
	else
		return right->member(x);
	


	

	return false;
}

template <typename Type>
bool BinarySearchTreeNode<Type>::insert(  const Type &x ) {
	if(x==x_value)
		return false;
	if(x<x_value)
	{
		if(left == 0){
			left = new BinarySearchTreeNode<Type>(x);
			return true;
		}
		else
			return left->insert(x);
	}
	if(x>x_value)
	{
		if(right == 0){
			right = new BinarySearchTreeNode<Type>(x);
			return true;
		}
		else
			return right->insert(x);

	}


	
	return false;
}

template <typename Type>
void BinarySearchTreeNode<Type>::clear() {
	if(left !=0)
		left->clear();
	if(right !=0)
		right->clear();
	delete this;

}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?


#endif

