#include<iostream>
using namespace std;
//polymorphisism  //many forms// static poly


// 1 compile time  poly

// function overloading
// operator overloading

// 2 runtime  poly
// method overriding
// inheritance dpendent




// compile time
class Human{
    public:

    // same fucntion but eith diff arguments
    void hello(){
        cout<<"hlo jattlife"<<endl;
    }
    void hello(string name){
        cout<<"hlo ths is again thatt }shit"+name<<endl;
        
    }

    // oprator overloading
    int a;
    int b;
    int add(){
        return a+b;
    }
    void operator+(Human &obj){
        int val1=this->a;
        int val2=obj.b;
        cout<<"output;->"<<val2-val1<<endl;

    }
   
};

// runtime
class Animal {
     public: 
     // method overridng // same function in parent and child class
     void speak( ) {
         cout << "Speaking " << endl;
    }
};
class Dog: public Animal {
    public: 
    void speak( ) { 
        cout << "Barking " << endl;
    }
};
int main(){
    Human obj1;
    obj1.hello();
    obj1.hello("arsh");
    Human obj2;
    obj1.a=10;
    obj2.b=20;
    obj1+obj2;// operator overloaidng


    // 

    Dog tommy;
    tommy.speak();// barking// child class one // chuld class fucntion is prfefered first then parent class 


}