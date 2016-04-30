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
/*
class SelectionSort: public Sort {
	public:
		SelectionSort () ;
		void  sort ( Container * container ) {
			int size = container -> size ();
			for ( int i = 0; i < size; i++ )
			{
				int min_it = i;
				for ( int j = i + 1; j < size; j++ )
					if ( container -> at ( min_it ) -> evaluate () > container -> at ( j ) -> evaluate () )
						min_it = j;
				container -> swap ( i, min_it );
			}
		};
};
*/
#endif /* Sort_h */
