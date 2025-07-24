#include<iostream>
using namespace std;
// using namespace std;
// super 
class Human {
public:
    int age;
    string name;

    Human(int a, string n) {
        age = a;
        name = n;
    }
};

class Student : public Human {
public:
int arsh;
int jatt;
    Student(int a,string n,int arsh, int jatt) : Human(a, n) {
        cout << "Student Constructor: Age = " << arsh << ", Name = " << jatt <<a<<n<< endl;
    }
};

int main() {
    int age;
    string name;

    cout << "Enter age: ";
    cin >> age;
    cout << "Enter name: ";
    cin >> name;

    // Now pass the input to the constructor
    Student s(age, name,44,46);

    return 0;
}

// If your base class has a parameterized constructor, then yes — : Base(...) is necessary to call that constructor. Otherwise, the code will not compile.

