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

	private:
		Base* op1;
		Base* op2;
};

class Add: public Base {
	public:
		/* Constructors */
		Add () {};
		~ Add () {};
};

class Sub: public Base {
	public:
		/* Constructors */
		Sub () {};
		~ Sub () {};
};

class Sqr: public Base {
	public:
		/* Constructors */
		Sqr () {};
		~ Sqr () {};
};

int main() {

	return 0;
}
