#include<iostream>
using namespace std;
// so classes can only creat objects?✅ Yes — exactly!Classes in C++ are templates or blueprints that are only used to create objects.
class Hero{
    public:
    int health;
    int level;
    void print(){
        cout<<level<<endl;
    }

    // if the object is private to get that we use getter and setter 
    int getHealth(){
        return health;


    }
    // set the value of the pbject withour using constrcutor
    void setHealth(int h ){
        health=h;
    }


};



int main(){
    Hero h1;// object h1// static allocation // stack allocation //copilation time  setted value
    // use(.) to access any operator  
    h1.health=33;


    cout<<h1.health<<endl;
    cout<<sizeof(h1)<<endl;// 1 if empty class 4 if fileld class 


    // usig  getter and setter 
    h1.setHealth(44);
    cout<<h1.getHealth()<<endl;
    
    cout<<h1.health<<endl;

// Why does new Hero create an object in the heap, but not the class itself? ✅ Because classes are blueprints, not memory blocks.
// 
    // dynamic allocation
    Hero *h2=new Hero;// the object is made in heap 
    // You are declaring a pointer named h2 of type Hero* It will store the address of a Hero object.
// new Hero creates a new object of class Hero on the heap memory.new returns a pointer to that object.



    cout<<(*h2).health<<endl;
    cout<<h2->health<<endl;










}
