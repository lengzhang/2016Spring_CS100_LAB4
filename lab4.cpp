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
		Op (const int new_num) {
			num = new_num;
		};
		~ Op () {};

		void setNum(const int new_num) {
			num = new_num;
		};
		int getNum() {
			return num;
		};
	private:
		int num;
};

class Mult: public Base {
	public:
		/* Constructors */
		Mult () {};
		~ Mult () {};
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
