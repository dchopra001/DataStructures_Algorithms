
#include "ece250.h"
#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"
#include "Exception.h"
#include <iostream>

using namespace std;

int main()
{
	try{

	cout<<"Let's create a Binary Search Tree"<<endl;
	cout<<"---------------------------------"<<endl;

	BinarySearchTree<double> *tree1;
	tree1 = new BinarySearchTree<double>();
	cout<<"Let's check zero boundaries"<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	//cout<<"Min: "<<tree1->min()<<endl;  SHOULD GIVE ERROR
	//cout<<"Max: "<<tree1->max()<<endl;  SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(-.1): "<<tree1->member(-0.1)<<endl;
	//cout<<"Clear: "<<tree1->clear()<<endl;

	cout<<"----------------------------------------"<<endl;

		
	cout<<"Let's insert one and then test boundaries"<<endl;
	tree1->insert(5.1);
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Min: "<<tree1->min()<<endl;  //SHOULD GIVE ERROR
	cout<<"Max: "<<tree1->max()<<endl;  //SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(5.1): "<<tree1->member(5.1)<<endl;

	cout<<"----------------------------------------"<<endl;

	cout<<"Let's insert SAME VALUE then test boundaries"<<endl;
	tree1->insert(5.1);
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Min: "<<tree1->min()<<endl;  //SHOULD GIVE ERROR
	cout<<"Max: "<<tree1->max()<<endl;  //SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(5.1): "<<tree1->member(5.1)<<endl;

	cout<<"Let's insert another value then test boundaries"<<endl;
	cout<<"----------------------------------------"<<endl;
	tree1->insert(4.1);
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Min: "<<tree1->min()<<endl;  //SHOULD GIVE ERROR
	cout<<"Max: "<<tree1->max()<<endl;  //SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(5.1): "<<tree1->member(5.1)<<endl;

	cout<<"Let's insert a SECOND value then test boundaries"<<endl;
	cout<<"----------------------------------------"<<endl;
	tree1->insert(4.1);
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Min: "<<tree1->min()<<endl;  //SHOULD GIVE ERROR
	cout<<"Max: "<<tree1->max()<<endl;  //SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(5.1): "<<tree1->member(5.1)<<endl;

	cout<<"Let's insert a THIRD value then test boundaries"<<endl;
	cout<<"----------------------------------------"<<endl;
	tree1->insert(0.8);
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Min: "<<tree1->min()<<endl;  //SHOULD GIVE ERROR
	cout<<"Max: "<<tree1->max()<<endl;  //SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(5.1): "<<tree1->member(5.1)<<endl;

	cout<<"Let's insert a FOURTH value then test boundaries"<<endl;
	cout<<"----------------------------------------"<<endl;
	tree1->insert(-10);
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Empty: "<<tree1->empty()<<endl;
	cout<<"Size: "<<tree1->size()<<endl;
	cout<<"Min: "<<tree1->min()<<endl;  //SHOULD GIVE ERROR
	cout<<"Max: "<<tree1->max()<<endl;  //SHOULD GIVE ERROR
	cout<<"Sum: "<<tree1->sum()<<endl;
	cout<<"Root: "<<tree1->root()<<endl;
	cout<<"Member(-10): "<<tree1->member(-10)<<endl;




	}catch(underflow e)
	{
		cout<<"Underflow"<<endl;
	}

	system("Pause");

return 0;
}




