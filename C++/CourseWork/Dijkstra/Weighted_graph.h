#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"


/*****************************************
 * UW User ID:  dchopra
 * Submitted for ECE 250
 * Semester of Submission:  Winter 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 *  the provided code.
 *****************************************/

// include whatever classes you want

class Weighted_graph {
	private:
		// your implementation here
		static const double INF;
		int numberOfNodes;
		double **matrix;
		int *degree1;
		int numberOfEdges;
		double *distanceList;
		bool *visited;
		int tmp;
		//bool all_visited;    //variables used for the while loop implementation of distance
		//int visit_count;		//due to debugging problems i ended up resorting to a for-loop implementation that did not requre these
		double tmpDistance;


	public:
		Weighted_graph( int = 50 );
		~Weighted_graph();


		
		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double distance( int, int ) ;

		void insert( int, int, double );
};

const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

// Your implementation here


Weighted_graph::Weighted_graph(int n)
{
	//if out of bounds value then set to 1
	if(n<=0)
		n = 1;
	//initialize bookkeeping variables
	numberOfNodes = n;
	degree1 = new int[numberOfNodes];
	visited = new bool[numberOfNodes];
	distanceList = new double [numberOfNodes];
	numberOfEdges = 0;

	//declare double pointer matrix properly

	matrix = new double*[numberOfNodes];
	for (int i = 0; i<n;i++)
		matrix[i] = new double[numberOfNodes];

	for (int i= 0; i< n; ++i) 
	{
		for (int j = 0; j < n; ++j ) 
		{
				matrix[i][j] = INF;
		}
		matrix[i][i] = 0;
	}
	
	//initialize degree matrix properly
	for(int i = 0;i<n;i++)
		degree1[i] = 0;

}

Weighted_graph::~Weighted_graph()
{	//first delete the double pointer matrix by deleting each pointer pointing to a double value, then delete the array of pointers
	for(int i = 0; i<numberOfNodes; i++)
		delete [] matrix[i];
	delete [] matrix;
	//all other deletions are as normal
	delete [] degree1;
	delete []distanceList;
	delete []visited;

}

int Weighted_graph::degree(int n) const{
	//bounds checking
	if(n<0 || n>=numberOfNodes)
		throw illegal_argument();	
	
	return degree1[n];
}

int Weighted_graph::edge_count() const{
//simple return required
	return numberOfEdges;
}

double Weighted_graph::adjacent(int n, int m) const{
	//bounds checking
	if(n<0 || n>=numberOfNodes)
		throw illegal_argument();

	if(m<0 || m>=numberOfNodes)
		throw illegal_argument();
	//if value in table is not infinite, then it must have some double value that we can use. So return it
	if(matrix[n][m]!=INF)
		return matrix[n][m];
	//if it does have infinity then return 0 (there is no way of getting to m from n 
	else
		return 0;
}

void Weighted_graph::insert(int m, int n, double w) 
{	//bounds checking
	if(w<=0)
		throw illegal_argument();

	if(n<0 || n>=numberOfNodes)
		throw illegal_argument();

	if(m<0 || m>=numberOfNodes)
		throw illegal_argument();

	if(n == m)
		throw illegal_argument();
	if ( w == INF)
		throw illegal_argument();
	
	//if no edge exists between the vertices, then update bookkeeping variables , else simply update the values
	if(matrix[m][n] ==  INF)
	{
		numberOfEdges++;
		degree1[n]++;
		degree1[m]++;
	}
	//updating the values
	matrix[m][n] = w;
	matrix[n][m] = w;



}

double Weighted_graph::distance(int m, int n) {
//ILLEGAL VALUES CHECKING
	if(n<0 || n>=numberOfNodes)
		throw illegal_argument();

	if(m<0 || m>=numberOfNodes)
		throw illegal_argument();

	if (degree(n) == 0 || degree(m) == 0)
	{
			throw illegal_argument();
	}
	//distance from a node to itself is 0 
	if(n == m)
		return 0.0;

	//initializaing/reseting temporary bookkeeping variables

	tmp = 0;
	tmpDistance = 0;
	//initialize the two most relevant arrays. one keeps track of which vertices have been visited and 
	//the other keeps track of distance from the source to all other vertices
	for(int i = 0; i<numberOfNodes; i++)
	{
		distanceList[i] = INF;
		visited[i] = false;
	}
	//distance from source to itself is 0. We have already visited the source since we start from there
	distanceList[m] = 0.0;
	visited[m] = true; 
		
	//this loop runs the same number of times as the number of vertices in the graph
	//due to the way it is structured, every time it will through a node which it
	//hasnt visited yet. Hence it will run through ALL the nodes in the loop and relax
	//all the edges if required.
	for(int i = 0; i<numberOfNodes; i++)
	{
		visited[m] = true;//now that we are at this node, we can set it to zero
		
		//this for-loop traverses through all the vertices while we are at a certain node.
		//it will update the distance from this node to those vertices if required
		for(int i = 0; i<numberOfNodes; i++)
		{	
			if((adjacent(m,i)+distanceList[m]) < distanceList[i])
			{
					if(adjacent(m,i)>0)
						distanceList[i] =  adjacent(m,i)+distanceList[m];
			}
			
			

		}
		
		//now we must decide what is the next node. This is the node with the shortest path from the current node!
		
		tmpDistance = INF; //this distance is used for comparison reasons
		for(int i = 0; i<numberOfNodes;i++)
		{	//if already visited the node, don't visit again
			if(visited[i] != true)
			{	//if distance to this node is smaller than distance to the shortest distance node we have
				if(distanceList[i]<tmpDistance)
				{
					tmp = i; //new node to go to
					tmpDistance = distanceList[i];//update distance for checking consistently throughout the loop
				}
			}
		}
	
			m = tmp; //next node to visit

		

	}
	//once out of the while loop, we should have all the distances relative to "m" figured out
	//so we just need to return dist[n]

	return distanceList[n];

	


}




#endif

