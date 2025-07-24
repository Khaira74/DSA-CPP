#include<iostream>
using namespace std;
//static // not needs an object creation to access it
// Must be declared inside the class, but defined outside the class.
//its inddependet  of objects  cration as like wehn wehn objects are made they have their own values of class variables 
// but static variable runs independetlyy  incremmenting or decremmeting indoendlty 
// this keyword cannot be sued for staic \\\\\ 




// If everything in the parent class is public, you do not need to use super (like in Java) to
//  access base class members in C++ — because C++ allows you to access public members of the base class
//  directly in the child class.

class Human {
public:
    int age;
    string name;
    static int population;

    Human() {
        cout << "Human constructor called\n";
    }
};

class Student : public Human {
public:
    Student() {
        // ✅ Accessing base class members directly — no need for `super`
        age = 20;
        name = "Arsh";
        cout << "Student Constructor: Age = " << age << ", Name = " << name << endl;
        cout<<"jjjjjjjjj"<<population++<<endl;// static in constructor
    }
    // void show(){
    //     cout<<population;
    // }
};


int Human::population=0;





class Hero{
    public:
    int health;
    int level;
    static int count;





    Hero() {
        count++;  // Increment static variable
    }
    static int random(){
        //cout<<health<<endl;// a nonstatic member reference must be relative to a specific objectC/C++(245)

    }
    void showCount(){
        cout<<count<<endl;
    }

};
// ::= scrope resolution operator
int Hero::count=0;
int main(){
    cout<<Hero::count<<endl;// printing direclty withour using any object
     Hero obj1;//count=1
    Hero obj2;//count=2;
    obj1.showCount();  // Output: Count is: 2
    obj2.showCount();


    Student s1;
    Student s2;
    Student s3;

    // s3.displayCount();  // prints 3
    // cout << "Access via class: " << Student::count << endl; // prints 3
    return 0;

}