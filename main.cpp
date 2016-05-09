#include <iostream>

#include <vector>
#include <list>

using namespace std;

//—————Base—————

class Base {
	public:
		/* Constructors */
		Base () { };
		/* Pure Virtual Functions */
		virtual double evaluate () = 0;
		virtual void print () = 0;
};

//—————Op—————

class Op: public Base {
	public:
		/* Constructors */
		Op () {};
		Op (const double new_num) {
			num = new_num;
		};
		~ Op () {};

		void setNum(const double new_num) {
			num = new_num;
		};
		double getNum() {
			return num;
		};
		virtual double evaluate () { return num; };
		virtual void print () { cout << num; };
	private:
		double num;
};

//—————Mult—————

class Mult: public Base {
	public:
        	/* Constructors */
        	Mult () {};
        	Mult (Base* new_op1, Base* new_op2)
        	{
            		op1 = new_op1;
            		op2 = new_op2;
        	};
	
        	Mult (Base* new_op1, const double x)
        	{
            		op1 = new_op1;
            		op2 = new Op(x);
        	};
	
        	Mult (const double y, const double x)
        	{
            		op1 = new Op(y);
            		op2 = new Op(x);
        	};
	
        	Mult (const double y, Base* new_op2)
        	{
            		op1 = new Op(y);
            		op2 = new_op2;
        	};
	
        	~ Mult () {};
        	virtual double evaluate()
        	{
            		return op1->evaluate() * op2->evaluate();
        	}
        	virtual void print ()
        	{
            		op1->print();
            		cout << " * ";
            		op2->print();
        	};
	private:
        	Base* op1;
        	Base* op2;
};

//—————Sub—————

class Sub: public Base {
	public:
        	/* Constructors */
        	Sub () {};
        	Sub (Base* new_op1, Base* new_op2)
        	{
            		op1 = new_op1;
            		op2 = new_op2;
        	};
	
        	Sub (Base* new_op1, const double x)
        	{
            		op1 = new_op1;
            		op2 = new Op(x);
        	};
	
        	Sub (const double y, const double x)
        	{
            		op1 = new Op(y);
            		op2 = new Op(x);
        	};
	
        	Sub (const double y, Base* new_op2)
        	{
            		op1 = new Op(y);
            		op2 = new_op2;
	        };
	
        	~ Sub () {};
        	virtual double evaluate()
        	{
            		return op1->evaluate() - op2->evaluate();
        	}
        	virtual void print ()
        	{
            		op1->print();
            		cout << " - ";
            		op2->print();
        	};
	private:
        	Base* op1;
       		Base* op2;
};

//—————Div—————

class Div: public Base {
	public:
        	/* Constructors */
        	Div () {};
        	Div (Base* new_op1, Base* new_op2)
        	{
            		op1 = new_op1;
            		op2 = new_op2;
        	};
	
        	Div (Base* new_op1, const double x)
        	{
            		op1 = new_op1;
            		op2 = new Op(x);
        	};
	
        	Div (const double y, const double x)
        	{
            	op1 = new Op(y);
            		op2 = new Op(x);
        	};
	
	        Div (const double y, Base* new_op2)
       		{
            		op1 = new Op(y);
            		op2 = new_op2;
        	};
	
        	~ Div () {};
        	virtual double evaluate()
        	{
            		return op1->evaluate() / op2->evaluate();
        	}
        	virtual void print ()
        	{
            		op1->print();
            		cout << " / ";
            		op2->print();
        	};
	private:
        	Base* op1;
        	Base* op2;
};

//—————Add—————

class Add: public Base {
	public:
		/* Constructors */
		Add (Base* new_op1, Base* new_op2) {
			op1 = new_op1;
			op2 = new_op2;
		};
		Add (const double new_op1, const double new_op2) {
			op1 = new Op(new_op1);
			op2 = new Op(new_op2);
		};
		Add (Base* new_op1, const double new_op2) {
			op1 = new_op1;
			op2 = new Op(new_op2);
		};
		Add (const double new_op1, Base* new_op2) {
			op1 = new Op(new_op1);
			op2 = new_op2;
		};
		
		~ Add () {};
		virtual double evaluate()
		{
			return op1->evaluate() + op2->evaluate();
		};
		virtual void print ()
		{
			op1->print();
			cout << " + ";
			op2->print();
		};

	private:
		Base* op1;
		Base* op2;
};

//—————Sqr—————

class Sqr: public Base {
	public:
        	/* Constructors */
       		Sqr () {};
        	Sqr (Base* new_op1)
        	{
            		op1 = new_op1;
        	};
	
	        Sqr (const double y)
        	{
            		op1 = new Op(y);
        	};
    
        	~ Sqr () {};
        	virtual double evaluate()
        	{
            		double i=op1->evaluate();
            	return i * i;
        	};
        	virtual void print ()
        	{
            		op1->print();
            		cout << "^ 2";
        	};
	private:
        	Base* op1;
};

//—————Container—————

class Sort;

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

//—————Sort—————

class Sort {
	public:
		/* Constructors */
		Sort () {};
		/* Pure Virtual Functions */
		virtual void sort ( Container * container ) = 0 ;
};

//—————SelectionSort—————

class SelectionSort: public Sort {
	public:
		virtual void  sort ( Container * container )
		{
			int size = container -> size ();
			for ( int i = 0; i < size - 1; i++ )
			{
				int min_it = i;
				for ( int j = i + 1; j < size; j++ ){
					if ( container -> at ( min_it ) -> evaluate () > container -> at ( j ) -> evaluate () )
						min_it = j;
				}
				if ( min_it != i )
					container -> swap ( i, min_it );
			}
		};
};


//—————BubbleSort—————

class BubbleSort: public Sort {
	public:
		virtual void sort ( Container * container )
		{
			int size = container -> size ();
			bool swapped;
			do
			{
				swapped = false;
				for ( int i = 0; i < size - 1; i++ )
				{
					if ( container -> at ( i ) -> evaluate () > container -> at ( i + 1 ) -> evaluate () )
					{
						container -> swap ( i, i + 1);
						swapped = true;
					}
				}
			} while ( swapped ); 
		};
};

//—————VectorContainer—————

class VectorContainer: public Container {
	public:
		void set_sort_function ( Sort * sort_function ) {
			this->sort_function = sort_function;
		};
		virtual void add_element ( Base * element ) {
			vectorContainer.push_back ( element );
		};
        	virtual void print () {
			if ( this -> size () == 0)
				cout << "Container is empty." << endl;
			else
				for ( int i = 0; i < this -> size (); i++ )
					cout << this -> at ( i ) -> evaluate () << endl;
		};
        	virtual void sort () {
			sort_function -> sort ( this );
		};
    
        	virtual void swap ( int i , int j ) {
			Base * temp = vectorContainer[i];
			vectorContainer[i] = vectorContainer[j];
			vectorContainer[j] = vectorContainer[i];
		};
        	virtual Base * at ( int i ) { return vectorContainer[i]; };
        	virtual int size () { return vectorContainer.size(); };

	protected:
		Sort * sort_function;

	private:
		vector < Base * > vectorContainer;
};

//—————ListContainer—————

class ListContainer: public Container {
	public:
		void set_sort_function ( Sort * sort_function ) {
			this->sort_function = sort_function;
		};

		virtual void add_element ( Base * element ) {
			listContainer.push_back ( element );
		};
        	virtual void print () {
			if ( this -> size () == 0)
				cout << "Container is empty." << endl;
			else
				for ( int i = 0; i < this -> size (); i++ )
					cout << this -> at ( i ) -> evaluate () << endl;
		};
        	virtual void sort () {
			sort_function -> sort ( this );
		};
    
        	virtual void swap ( int i , int j ) {
			list < Base * > :: iterator it_i = listContainer.begin();
			list < Base * > :: iterator  it_j = listContainer.begin();
			int k = 0;
			while ( k < i || k < j )
			{
				if ( k < i ) { it_i++; }
				if ( k < j ) { it_j++; }
				k++;
			}
			listContainer.insert ( it_i, *it_j );
			listContainer.insert ( it_j, *it_i );
			listContainer.erase ( it_i );
			listContainer.erase ( it_j );
		};
        	virtual Base * at ( int i )
		{
			list < Base * > :: iterator it;
			it = listContainer.begin ();
			for ( int j = 0; j < i; j++) { ++it; }
			return * it;
		};
        	virtual int size () { return listContainer.size(); };

	protected:
		Sort * sort_function;

	private:
		list < Base * > listContainer;
};

//—————Main—————

int main() {
	Op * op7 = new Op ( 7 );
	Op * op4 = new Op ( 4 );
	Op * op3 = new Op ( 3 );
	Op * op2 = new Op ( 2 );
	Mult * A = new Mult ( op7 , op4 );
	Add * B = new Add ( op3 , A );
	Sub * C = new Sub ( B , op2 );
	Sqr * D = new Sqr ( C );
	
	ListContainer * container = new ListContainer ();
	container -> add_element ( A );
	container -> add_element ( B );
	container -> add_element ( C );
	container -> add_element ( D );
	container -> add_element ( op7 );
	container -> add_element ( op4 );
	container -> add_element ( op3 );
	container -> add_element ( op2 );


	cout << "Container Before Sort:" << endl;
	container -> print ();

	cout << "Container After Sort:" << endl;
	container -> set_sort_function ( new SelectionSort ());
	//container -> set_sort_function ( new BubbleSort ());
	container -> sort ();
	container -> print ();




	return 0;
}
