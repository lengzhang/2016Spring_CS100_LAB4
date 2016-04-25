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
		Mult (Base* new_op1, Base* new_op2) {
			op1 = new_op1;
			op2 = new_op2;
		};
		~ Mult () {};
		double evaluate () {
			
		};
	private:
		Base* op1;
		Base* op2;
};

class Mult: public Base {
	public:
	/* Constructors */
	Mult () {};
	Mult (Base* op1, Base* op2) {};
	~ Mult () {};
	virtual double evaluate()
	{
		op1->evaluate() * op2->evaluate();
		return op1/op2;
	}
	private:
	Base* op1;
	Base* op2;
};

class Add: public Base {
	public:
		/* Constructors */
		Add (Base* op_1, Base* op_2) {op1=op_1;op2=op_2;};
		~ Add () {};
		virtual double evaluate()
		{
			return op1+op2;
		}
	private:
		Base* op1;
		Base* op2;
};

class Sub: public Base {
	public:
		/* Constructors */
<<<<<<< Updated upstream
		virtual double evaluate()
		{
			return op1-op2;
		}
=======
>>>>>>> Stashed changes
		Sub (Base* op_1, Base* op_2) {op1=op_1;op2=op_2;};
		~ Sub () {};
			
	private:
		Base* op1;
		Base* op2;	
};

class Sqr: public Base {
	public:
		/* Constructors */
		Sqr (Base* op_1) {op1=op_1;};
		~ Sqr () {};
		virtual double evaluate()
		{
			return op1*op1;
		}
		
	private:
		Base* op1;
};

int main() {
//	Op* num = new Op(7);
//	cout << num->getNum() << endl;


	return 0;
}
