/*************************************************
 * Weighted_graph_tester
 * A class for testing singly-linked lists.
 *
 * Author:  Douglas Wilhelm Harder
 * Copyright (c) 2006-8 by Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *************************************************/

#ifndef WEIGHTED_GRAPH_TESTER_H
#define WEIGHTED_GRAPH_TESTER_H
#define PARAMETERIZED

#include "Exception.h"
#include "Tester.h"
#include "Weighted_graph.h"

#include <iostream>
#include <cmath>

using namespace std;


class Weighted_graph_tester:public Tester<Weighted_graph> {
	using Tester< Weighted_graph >::object;
	using Tester< Weighted_graph >::command;

	public:
		Weighted_graph_tester( Weighted_graph *obj = 0 ):Tester<Weighted_graph>( obj ) {
			// empty
		}

		void process();
};

/****************************************************
 * void process()
 *
 * Process the current command.  For singly-linked lists, these include:
 *
 *  Accessors
 *   edge_count n      edge_count   the edge count is n
 *   degree m n        degree       the degree of vertex m is n
 *   adjacent m n d    adjacent     checks if the adjacency of m and n is d
 *   adjacent! m n     adjacent     checks if adjacent throws an exception when checking
 *                                  if m and n are adjacent
 *   distance m n d    distance     checks if the shortest distance from m to n is d
 *   distance! m n     distance     checks if the shortest distance throws an exception when
 *                                  attempting to find the shortest distance from m to n
 *
 *  Mutators
 *   insert m n d      insert        insert an edge of weight d between m and n
 *   insert! m n d     insert        insert throws an exception when inserting an
 *                                   edge of weight d between m and n
 *  Others
 *   summary                         prints the amount of memory allocated
 *                                   minus the memory deallocated
 *   details                         prints a detailed description of which
 ****************************************************/

void Weighted_graph_tester::process() {
	if ( command == "edge_count" ) {
		// check if the edge count equals the next integer read

		int expected_count;

		cin >> expected_count;

		int actual_count = object->edge_count();

		if ( actual_count == expected_count ) {
			cout << "Okay" << endl;
		} else {
			cout << "Failure in edge_count(): expecting the value '" << expected_count << "' but got '" << actual_count << "'" << endl;
		}
	} else if ( command == "degree" ) {
		int vertex;
		cin >> vertex;

		int expected_degree;
		cin >> expected_degree;

		int actual_degree = object->degree( vertex );

		if ( actual_degree == expected_degree ) {
			cout << "Okay" << endl;
		} else {
			cout << "Failure in degree(" << vertex << "): expecting the value '" << expected_degree << "' but got '" << actual_degree << "'" << endl;
		}
	} else if ( command == "adjacent" ) {
		int v1, v2;
		cin >> v1;
		cin >> v2;

		double expected_weight;
		cin >> expected_weight;

		double actual_weight = object->adjacent( v1, v2 );

		if ( actual_weight == expected_weight ) {
			cout << "Okay" << endl;
		} else {
			cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting the value '" << expected_weight << "' but got '" << actual_weight << "'" << endl;
		}
	} else if ( command == "adjacent!" ) {
		int v1, v2;
		cin >> v1;
		cin >> v2;

		try {
			object->adjacent( v1, v2 );
			cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting to catch an exception" << endl;
		} catch( illegal_argument ) {
			cout << "Okay" << endl;
		} catch (...) {
			cout << "Failure in adjacent(" << v1 << ", " << v2 << "): expecting an illegal argument exception but caught a different exception" << endl;
		}
	} else if ( command == "distance" ) {
		int v1, v2;
		cin >> v1;
		cin >> v2;

		double expected_distance;
		cin >> expected_distance;

		double actual_distance = object->distance( v1, v2 );

		if ( fabs( actual_distance - expected_distance ) < 1e-10 ) {
			cout << "Okay" << endl;
		} else {
			cout << "Failure in distance(" << v1 << ", " << v2 << "): expecting the value '" << expected_distance << "' but got '" << actual_distance << "'" << endl;
		}
	} else if ( command == "distance!" ) {
		int v1, v2;
		cin >> v1;
		cin >> v2;

		try {
			object->distance( v1, v2 );
			cout << "Failure in distance(" << v1 << ", " << v2 << "): expecting to catch an exception" << endl;
		} catch( illegal_argument ) {
			cout << "Okay" << endl;
		} catch (...) {
			cout << "Failure in distance(" << v1 << ", " << v2 << "): expecting an illegal argument exception but caught a different exception" << endl;
		}
	} else if ( command == "insert" ) {
		int v1, v2;
		cin >> v1;
		cin >> v2;

		double weight;
		cin >> weight;

		object->insert( v1, v2, weight );
		cout << "Okay" << endl;
	} else if ( command == "insert!" ) {
		int v1, v2;
		cin >> v1;
		cin >> v2;

		double weight;
		cin >> weight;

		try {
			object->insert( v1, v2, weight );
			cout << "Failure in insert(" << v1 << ", " << v2 << ", " <<  weight<< "): expecting to catch an exception" << endl;
		} catch( illegal_argument ) {
			cout << "Okay" << endl;
		} catch (...) {
			cout << "Failure in insert(" << v1 << ", " << v2 << ", " <<  weight<< "): expecting an illegal argument exception but caught a different exception" << endl;
		}
		
    }
	
}

#endif


