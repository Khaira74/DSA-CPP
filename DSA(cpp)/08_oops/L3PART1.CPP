
#include<iostream>
using namespace std;
//college walla
// vitual  fucntion binding 

class Scooty{ // parent class
    public: int topSpeed; 
    float mileage; 
    virtual void sound ( ) { 
        cout << "Vroom Vroom" << endl; 
    }
   
};
class Bike : public Scooty{ // child class / derived class 
    public: 
    int gears;
    void sound ( ) {
        cout << "Dhroom Phroom" << endl;
    }
};

int main(){
    Bike b; 
    Scooty a;
    b.sound();
    a.sound();

    cout<<"here the story changes"<<endl;
    Bike*hero=new Bike();
    // early binding
    hero->sound();// dhroom

    // if we use scooty to make runtime object 
    // early binding - we already knew whats will be output
    Scooty*bullet=new Bike();
    bullet->sound();// vroom vrom// due to runtime declration
    // when we have two runtime fucntions


    // late binding- we not knew untill runtime what will be output
    // to change this we use virtual function
    // now
    bullet->sound();//dhoom
}