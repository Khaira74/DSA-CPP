#include<iostream>
using namespace std;
// encapsulation-like a capsule(which contain all the things inside it )
// information or data hiding
// wrapping up data members and funcitons

// fully encapsulated class-all datamebers are private // oly accesible in the class


// inherticance
// | Inheritance Type | Base `public` → | Base `protected` → | Base `private` → |
// | ---------------- | --------------- | ------------------ | ---------------- |
// | `public`         | public          | protected          | not accessible   |
// | `protected`      | protected       | protected          | not accessible   |
// | `private`        | private         | private            | not accessible   |


class Human{
    public:// accessedeverywhere in main fxn too
    int publicss;
    // below both cannotb be accessed in main function
    protected:
    int protectedss;
    private:
    int privatess;
    public:
    void setpublicss(int a){
        this->publicss=a;
    }
    void setprotectedss(int a){
        this->protectedss=a;
    }
    void setprivatess(int a){
        this->privatess=a;
    }
};
class Male1: public Human{
    public:
    string color;
    void check(){
        // can be done directly without setter
        publicss=66;
        protectedss=77;
        // privatess=88;

    }
    void sleep(){
        cout<<"male is sleeping"<<endl;
        // cout<<sex<<endl;innaccble

    }
};
class Male2: protected Human{
    public:
    string color;

    void setter(int a,int b){
        publicss=b;
        protectedss=a;// or setprotectedss(a)
        // this->privatess=b;// inaccessble;

    }
    void print(){
        cout<<"proteted  and public setter in child class respectively"<<protectedss<<publicss<<endl;
    }
     void check(){
//protected gives access to child classes → meant for inheritance use.
// private hides data completely from outside and from child classes too.
// Both are hidden from main() and other unrelated code — only public is globally accessible.
// Use protected if you want your child classes to access but not expose the data outside.
        publicss=66;
        protectedss=77;
        // privatess=88;

    }
    void sleep(){
        cout<<"male is sleeping"<<endl;

    }
};
class Male3: private Human{
    public:
    string color;
    void set(int z,int c){
        z=protectedss;//  see table  private items are accessd using getters and setters 
        // c=privatess; inaacible see table

    }
    void sleep(){
        cout<<"male is sleeping"<<endl;

    }
};


int main(){

//     Yes, base class setters/getters work with derived class objects.
// Inheritance must be public, and the functions should be public too.
    Male1 h1;
    h1.publicss=77;
    // h1.protectedss=88; // protected cannot be used directly to set values // getter setter is must used
    h1.setprotectedss(43);
    h1.setprivatess(88);

    Male2 h2; 
    h2.setter(44,45);
    h2.print();// gives 44
    

    // all below inaacsible
    // h2.publicss=77;
    // h2.setprotectedss(43);
    // h2.setprivatess(88);


    Male3 h3;
    h3.set(55,55);



    // below are innaccessible
    // h3.publicss=77;
    // h3.setprotectedss(43);
    // h3.setprivatess(88);



}