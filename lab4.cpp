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
	private:
		double num;
};

class Mult: public Base {
	public:
		/* Constructors */
		Mult () {};
		Mult (const Base* op1, const Base* op2) {};
		~ Mult () {};
		virtual double evaluate()
		{
			return op1*op2;
		}
	private:
		Base* op1;
		Base* op2;
};

class Mult: public Base {
	public:
	/* Constructors */
	Mult () {};
	Mult (const Base* op1, const Base* op2) {};
	~ Mult () {};
	virtual double evaluate()
	{
		return op1/op2;
	}
	private:
	Base* op1;
	Base* op2;
};

class Add: public Base {
	public:
		/* Constructors */
		Add (const Base* op_1, const Base* op_2) {op1=op_1;op2=op_2;};
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
		virtual double evaluate()
		{
			return op1-op2;
		}
		Sub (const Base* op_1, const Base* op_2) {op1=op_1;op2=op_2;};
		~ Sub () {};
			
	private:
		Base* op1;
		Base* op2;	
};

class Sqr: public Base {
	public:
		/* Constructors */
		Sqr (const Base* op_1) {op1=op_1;};
		~ Sqr () {};
		virtual double evaluate()
		{
			return op1*op1;
		}
		
	private:
		Base* op1;
};

int main() {

	return 0;
}
