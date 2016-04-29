#ifndef _Sort_h_
#define _Sort_h_

#include <iostream>
#include "Container.h"

using namespace std;

class Container;

class Sort {
	public:
		/* Constructors */
		Sort ();
		/* Pure Virtual Functions */
		virtual void sort ( Container * container ) = 0 ;
};

class Selection_Sort: public Sort {
	public:
		Selection_Sort () ;
		void  sort ( Container * container ) {

		};
};

#endif /* Sort_h */
