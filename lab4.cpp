#include <iostream>
#include <vector>

using namespace std;

class Base {
	public:
		/* Constructors */
		Base () { };
		/* Pure Virtual Functions */
		virtual double evaluate () = 0;
		virtual void print () = 0;
};

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
		double evaluate () { return num; };
		void print () { cout << num; };
	private:
		double num;
};

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
        	void print ()
        	{
            		op1->print();
            		cout << " * ";
            		op2->print();
        	};
	private:
        	Base* op1;
        	Base* op2;
};

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
        	void print ()
        	{
            		op1->print();
            		cout << " - ";
            		op2->print();
        	};
	private:
        	Base* op1;
       		Base* op2;
};

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
        	void print ()
        	{
            		op1->print();
            		cout << " / ";
            		op2->print();
        	};
	private:
        	Base* op1;
        	Base* op2;
};

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
		void print ()
		{
			op1->print();
			cout << " + ";
			op2->print();
		};

	private:
		Base* op1;
		Base* op2;
};

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
        	}
        	void print ()
        	{
            		op1.print();
            		cout << "^ 2";
        	}
	private:
        	Base* op1;
};

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

	private:
}

class Sort {
	public:
		/* Constructors */
		Sort ();
		/* Pure Virtual Functions */
		virtual void sort ( Container * container ) = 0;
};

int main() {
	Op* num1 = new Op(7);
	Op* num2 = new Op(3);
	Mult* mult = new Mult(5, 5);
	Add* add = new Add(5,mult);
	cout << add->evaluate() << endl;

	return 0;
}
