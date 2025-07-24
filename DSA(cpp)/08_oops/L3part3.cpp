
#include<iostream>
using namespace std;
// pure virtual fucntion
// abstract class- calss haveinf atleast one virtual function
//we cant declare the object of abstract class

#include <iostream>
using namespace std;
 

class Animal {// abstract virtual class
public:
    virtual void speak() = 0; // Pure virtual function
};

class Dog : public Animal {
public:
    void speak() override {// defing the pure virtaul fucntion
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    // Animal a; ❌ Error: Cannot instantiate abstract class
    // cannot make an obejct of abstract class
    Dog d;
    Cat c;

    d.speak(); // Woof!
    c.speak(); // Meow!

    // Polymorphism
    // late binding
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    // as animal is virtual fucntion
    a1->speak(); // Woof!
    a2->speak(); // Meow!
  

    // to save memory
    delete a1;
    delete a2;

    return 0;
}


