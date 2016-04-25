#include <iostream>

using namespace std;

class Base {
	public:
		/* Constructors */
		Base () { };
		/* Pure Virtual Functions */
		virtual double evaluate () = 0;
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
	private:
		Base* op1;
		Base* op2;
};


int main() {
	Op* num1 = new Op(7);
	Op* num2 = new Op(3);
	Mult* mult = new Mult(5, 5);
	Add* add = new Add(5,mult);
	cout << add->evaluate() << endl;

	return 0;
}
