#include <iostream>
#include "Exception.h"
#include "ece250.h"
#include "DoubleHashTable.h"
using namespace std;

int main()
{	//cout<<-9%8<<endl;
	cout<<"Testing with Print method commented out... ... ..."<<endl<<endl<<endl<<endl;
	try{
	cout<<"Let's create an array of size 3.. Therefore the power = 3"<<endl;
	DoubleHashTable <double> hash1(3);
	hash1.print();
	
	cout<<"Let's test the othr methods: "<<endl;
	
	cout<<"Look for WRONG element (MEMBER): "<<hash1.member(-842150451)<<endl<<endl;
	
	
	cout<<"Insert 5.1: (index should be 5)"<<endl;
	hash1.insert(5.1);
	hash1.print();
	
	cout<<endl<<"Now let's test if the first jump works! Insert 13.9! Index should be 5"<<endl;
	cout<<"Since there is a collision, offset of 1 should be used, so index should be 6!"<<endl;
	hash1.insert(13.9);
	hash1.print();

	cout<<endl<<"Now let's test if the SECOND jump works! Insert 21.5. Index=5"<<endl;
	cout<<"Since there is a collision, offset of 2+1 should be used, so index should be 0!"<<endl;
	hash1.insert(21.5);
	hash1.print();

	cout<<"Now let's fill up the table! Each new value should cause collisions till the table is full"<<endl;
	hash1.insert(29.8);//index = 5. collision. thus offset = 3. therefore jump to 0! collision! thus jump to 3!
	hash1.insert(37.7);//index = 5. collision. thus offset = 4+1. thus jump to 2!
	hash1.insert(45.6);//index = 5. ........ thus offset = 5... jump to 2! Collision! thus index = 7!
	hash1.insert(53.4);//index = 5. offset = 6+1... jump to 4
	hash1.insert(61.3);//index = 5. offset = 7. ... jump to 4... collision. therefore jump to 3. collision! jump to 2!Collision! jump to 1! thus index = 1!
	hash1.print();
	cout<<endl;

	cout<<"Now let's test the remove method"<<endl;
	cout<<"The values of the table in order are: 21,61,37,29,53,5,13,45"<<endl;
	cout<<"Remove 61!"<<endl;
	hash1.remove(61.3);
	hash1.print();
	
	cout<<"Let's try to find 61.3 now: "<<hash1.member(61.3)<<endl;//should return 0
	hash1.print();

	cout<<endl<<"Let's try to remove 61.3 AGAIN!: "<<hash1.remove(61.3)<<endl;//should return 0

	cout<<"Let's delete all elements in the array now!"<<endl;
	hash1.remove(21.5);
	hash1.remove(37.7);
	hash1.remove(29.8);
	hash1.remove(53.4);
	hash1.remove(5.1);
	hash1.remove(13.9);
	hash1.remove(45.6);
	hash1.print();//all states = delete, and all values same as that of constructor

	cout<<endl<<"Now let's try to insert something again. Insert 5!"<<endl<<endl;
	hash1.insert(5);
	hash1.print();

	cout<<"Let's try to remove a deleted value: 61.3: "<<hash1.remove(61.3)<<endl;

	cout<<"Remove 5: "<<hash1.remove(5)<<endl;
	hash1.print();
	cout<<endl;


	cout<<"every single value is deleted. LEt's insert into a box with a deleted value"<<endl;
	hash1.insert(99);//should be at index 3
	hash1.print();

	cout<<"Let's clear this table"<<endl;
	hash1.clear();
	hash1.print();
	
	cout<<endl<<"Let's test negative values"<<endl;
	hash1.insert(-9);
	hash1.insert(-15);
	hash1.insert(-14);
	hash1.insert(-13);
	hash1.insert(-12);
	hash1.insert(-11);
	hash1.insert(-10);
	hash1.insert(-8);
	hash1.print();




	}
	catch(overflow e)
	{
		cout<<"Overflow"<<endl;
	}

	cout<<endl<<endl<<endl;

	cout<<"Testing Finished with Print method commented out!"<<endl<<endl<<endl<<endl;

return 0;

}


