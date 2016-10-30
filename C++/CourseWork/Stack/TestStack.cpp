#include <iostream>
#include <cstdlib>
#include "Exception.h"
#include "Array.h"
#include "DynamicStackAsArray.h"

using namespace std;

int main()
{
	try{
		cout<<"First we will print an array and test if all values are set accordingly"<<endl;
		cout<<"For the default array, the stack size = 0, array size = 10,"<<endl;
		cout<<"count = 0, ihead = -1"<<endl;
		cout<<"------------------------------------------------------------------------"<<endl<<endl;

	DynamicStackAsArray <int> stack;
	stack.print();
	cout<<endl<<endl;
		
	cout<<"The empty method test: Should return true"<<endl;
	cout<<stack.empty()<<endl;

	cout<<"NOW, let's push values onto the stack till its full!"<<endl;
	cout<<"stack size = 10, array size = 10, count = 10, ihead = 9"<<endl;
	cout<<"--------------------------------------------------------"<<endl<<endl;

	for(int i = 0; i<stack.capacity();i++)
		stack.push(5);

	stack.print();
	cout<<endl<<endl;

	cout<<"Now let's add one more value to the FULL stack!"<<endl;
	cout<<"stack size = 11, array size = 20, count = 11, ihead = 10"<<endl;
	cout<<"--------------------------------------------------------"<<endl;

	stack.push(5);
	stack.print();
	cout<<endl<<endl;

	cout<<"Let's push 7 to the stack and see if we can use the top() method to print this value"<<endl;
	cout<<"-------------------------------------------------------------------------------------"<<endl;
	stack.push(7);
	cout<<stack.top()<<endl;
	cout<<endl<<endl;

	cout<<"The size of the stack using the size method(should return 12)"<<endl;
	cout<<stack.size()<<endl;
	cout<<endl<<endl;
	
	cout<<"The empty method test: Should return false"<<endl;
	cout<<stack.empty()<<endl;
	cout<<endl<<endl;

	cout<<"Let's do aggressize testing on POP now"<<endl;
	cout<<"Right now the array size is 12"<<endl;
	cout<<"if we go down to 3, the array should resize to 10!"<<endl;
	for(int i =0; i<9;i++)
		stack.pop();
	stack.print();
	cout<<endl<<endl;

	cout<<"Now let's increase stack size to 41! Hence the Capacity should be 80!"<<endl;
	for(int i = 0; i<=37;i++)
		stack.push(5);
	stack.print();

	cout<<"Now let's go down to 30 elements!"<<endl;
	cout<<"The array size should still be 80!"<<endl;
	for(int i = 0;i<=10;i++)
		stack.pop();
	stack.print();

	cout<<"Now if we go down to 20, the stack capacity should reduce to 40!"<<endl;
	int x;
	for (int i = 0; i<=9; i++)
		x = stack.pop();
	stack.print();
	cout<<"Last popped value: "<<x<<endl;
	cout<<endl<<endl;

	cout<<"Lastly, let's clear the stack. so we should be back to defaul output that we got first"<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	stack.clear();
	stack.print();

	cout<<"Finally, let's make a stack of capacity 5 instead of 10 to begin with"<<endl;
	DynamicStackAsArray <double> stack2(5);
	cout<<endl;
	cout<<endl;
	stack2.print();

	}
	catch(underflow e)
	{
		cout<<"Underflow Error"<<endl;

	}


	

	
	cin.get();
	return 0;
}


