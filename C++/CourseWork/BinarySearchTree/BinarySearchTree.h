#ifndef BSTTREE_H
#define BSTTREE_H

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
#include "BinarySearchTreeNode.h"
#include "Exception.h"
#include <iostream>

template <typename Type>
class BinarySearchTree {
	private:
		BinarySearchTreeNode<Type> *tree_root;
		int count;

	public:
		BinarySearchTree();
		~BinarySearchTree();

		// Accessors

		int size() const;
		bool empty() const;

		Type min() const;	
		Type max() const;	
		Type sum() const;
	
	
	    


		BinarySearchTreeNode<Type> *root() const;
		bool member( const Type  &) const;

		// Mutators
       
		void insert( const Type &);
		void clear();

};


template <typename Type>
BinarySearchTree<Type>::BinarySearchTree():
tree_root( 0 ), 
count( 0 ) {
	// empty constructor
}

template <typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {
	clear();
}

template <typename Type>
int BinarySearchTree<Type>::size() const {
	return count;
	//return 0;
}

template <typename Type>
bool BinarySearchTree<Type>::empty() const {
	if (count == 0)
		return true;
	else
		return false;
	//return true;
}

template <typename Type>
Type BinarySearchTree<Type>::min() const {
	if(empty())
		throw underflow();
	return tree_root->min();
	//return Type();
}



template <typename Type>
Type BinarySearchTree<Type>::max() const {
	if(empty())
		throw underflow();
	return tree_root->max();
	//return Type();
}



template <typename Type>
Type BinarySearchTree<Type>::sum() const {
	
	if(empty())
		return 0;
	return tree_root->sum();
	//return Type();
}






template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTree<Type>::root() const 
{
	if(empty())
		return 0;
	else
		return tree_root;

	//return 0;
}




template <typename Type>
bool BinarySearchTree<Type>::member( const Type  &x ) const {
	if(empty())
		return false;
	return tree_root->member(x);
	//return false;
}

template <typename Type>
void BinarySearchTree<Type>::insert( const Type  &x ) {
	if(empty())
	{
		tree_root = new BinarySearchTreeNode<Type>(x);
		count++;
	}
	else if(tree_root->insert(x))
		count++;

}

template <typename Type>
void BinarySearchTree<Type>::clear() {
	if(empty())
		return;
	tree_root->clear();
	count = 0;
	tree_root = 0;

}

// You can modify this function however you want:  it will not be tested

template <typename Type>
std::ostream &operator << ( std::ostream &out, BinarySearchTree<Type> const &qt ) {
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif


