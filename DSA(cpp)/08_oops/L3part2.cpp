
#include<iostream>
using namespace std;

// VIRTUAL BASE CLASS 
// When a class is inherited multiple times through different inheritance paths, it can lead to duplicate copies of the base class, causing ambiguity.
// This is known as the Diamond Problem.

// To solve this, we use a virtual base class, which ensures that only one copy of the base class is shared among all the derived classes.
// multiple inheritacne problem sloution 
#include <iostream>
using namespace std;




class A {
public:
    int value = 1;
};

class B : public A {};
class C : public A {};
class D : public B, public C {}; // Diamond problem

int main() {
    D obj;
    // obj.value = 10; ❌ Error: Ambiguous
    cout << obj.B::value << endl; // ✅ Access via B
    cout << obj.C::value << endl; // ✅ Access via C
    return 0;
}



class A {
public:
    int value = 10;
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

// a is virtual base class
// ba dn c are derivede class
int main() {
    D obj;
    obj.value = 100; // ✅ No ambiguity
    cout << "Value: " << obj.value << endl;
    return 0;
}

