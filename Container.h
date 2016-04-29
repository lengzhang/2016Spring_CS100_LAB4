#ifndef _Container_h_
#define _Container_h_

#include <iostream>
#include <vector>
#include <list>

#include "Sort.h"

using namespace std;

class Container {
	protected:
        	Sort * sort_function;
    	public:
        	/* Constructors */
        	Container () : sort_function ( NULL ){};
        	Container ( Sort * function ) : sort_function ( function ) {};
    
		/* Non Virtual Functions */
		void set_sort_function ( Sort * sort_function ); // set the type of sorting algorithm

		/* Pure Virtual Functions */
        	// push the top pointer of the tree into container
        	virtual void add_element ( Base * element ) = 0 ;
        	// iterate through trees and output values
        	virtual void print () = 0 ;
        	// calls on the previously set sortingalgorithm. Checks if sort_function is not null, throw exception if otherwise
        	virtual void sort () = 0 ;
    
        	/* Essentially the only functions needed to sort */
        	//switch tree locations
        	virtual void swap ( int i , int j ) = 0 ;
        	// get top ptr of tree at index i
        	virtual Base * at ( int i ) = 0 ;
        	// return container size
        	virtual int size () = 0 ;
};

class VectorContainer: public Container {
	public:
		VectorContainer() : sort_function ( NULL ) {};
		VectorContainer( Sort * function ) : sort_function ( function ) {};
		~ VectorContainer();

		void set_sort_function ( Sort * sort_function ) {
			this->sort_function = sort_function;
		}
		void add_element ( Base * element ) {
			vectorContainer.push_back ( element );
		}
        	void print () {
			if ( this -> size () == 0)
			{
				cout << "Container is empty." << endl;
			}
			else
			{
				for ( int i = 0; i < this -> size (); i++ )
				{
					cout << this -> at ( i ) -> evaluate () << endl;
				}
			}
		}
        	void sort () {
			sort_function -> sort ( this );
		}
    
        	void swap ( int i , int j ) {
			Base * temp = vectorContainer[i];
			vectorContainer[i] = vectorContainer[j];
			vectorContainer[j] = vectorContainer[i];
		}
        	Base * at ( int i ) { return vectorContainer[i]; };
        	int size () { return vectorContainer.size(); }

	protected:
		Sort * sort_function;

	private:
		vector < Base * > vectorContainer;
};

class ListContainer: public Container {
	public:
		ListContainer() : sort_function ( NULL ) {};
		ListContainer( Sort * function ) : sort_function ( function ) {};
		~ ListContainer();

		void set_sort_function ( Sort * sort_function ) {
			this->sort_function = sort_function;
		}

		void add_element ( Base * element ) {
			listContainer.push_back ( element );
		}
        	void print () {
			if ( this -> size () == 0)
			{
				cout << "Container is empty." << endl;
			}
			else
			{
				for ( int i = 0; i < this -> size (); i++ )
				{
					cout << this -> at ( i ) -> evaluate () << endl;
				}
			}
		}
        	void sort () {
			sort_function -> sort ( this );
		}
    
        	void swap ( int i , int j ) {
			//Base * temp = listContainer[i];
			//listContainer[i] = listContainer[j];
			//listContainer[j] = listContainer[i];
		}
        	Base * at ( int i ) { return 0; }
        	int size () { return 0; }

	protected:
		Sort * sort_function;

	private:
		list < Base * > listContainer;
};

#endif /* Container_h */
