#include <iostream>

using namespace std;

class Base {
	public:
		/* Constructors */
		Base () { };
		/* Pure Virtual Functions */
		virtual double evaluate () = 0;
}

class Op: public Base {
	public:
		/* Constructors */
		Op () {};
		~ Op () {};
}

class Mult: public Base

int main() {

	return 0;
}
