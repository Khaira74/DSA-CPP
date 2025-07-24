#include <iostream>
#include <cmath> // For pow

using namespace std;

int main(){
    int num=5;// num is now matched to the addess of a block which conatin 5 hahahahha
    cout<<num<<endl;
    // & is used to get address of anything
    // When you write int *ptrs;, you're saying :
    //“I have a pointer named ptrs, but it currently doesn’t point to any known variable.”

   // When you write ptrs = &i;, you're saying:
   // “Now I assign it the address of i — now it points to i.”
    cout<<"address of num is->"<<&num<<endl;

    // pointer only  stores the address
    int *ptr=&num; // now both ptr and num points to 5 
    // int *ptrrrrr=num;// cannot happen it  gives error
    cout<<"value that pointer points to  is "<< *ptr<<endl;//5
    cout<<"address that pointer stores is "<< ptr<<endl;//0x13442j24b4
    cout<<"address of pointer is "<< &ptr<<endl;//0x43j242424

    //error both below 
    int i=33;
    // 1. int *pttt=i; a value of type "int" cannot be used to initialize an entity of type "int *"
    // 2. int pp=&i;a value of type "int *" cannot be used to initialize an entity of type "int"






    double d=4.3;
    double *ptr1=&d;
    cout<<"value that  double pointer points to  is "<< *ptr1<<endl;//4.3
    cout<<"address that  double pointer stores is "<< ptr<<endl;//0x1324ds34s




    
    cout<<"size of the num is "<< sizeof(num)<<endl;//4 as it stores data

    cout<<"size of the pointer is "<< sizeof(ptr)<<endl;//8   as it stores address











    /// tricky 
    cout<<" T  R  I  C  K      F O  R      P  O  IN  T  E R  S  "<<endl;


     // both smae outputs 
    //#1
    int i=5;
    int*q=&i;
    cout<<q<<endl;//0x16d72edbc
    cout<<*q<<endl;//5

    // #2
    int *p=0;
    p=&i;
    cout<<p<<endl;//0x16d72edbc
    cout<<*p<<endl;//5



   ///     CHANGIGN VALUE'S 


   int digit =5;
   int a=digit;
   cout<<"before INCREMENT A ::"<< digit<<endl;//5
   a++;
   cout<<"after INCRMENT A ::"<<digit<<endl;//5


   int*pointer=&digit;
   // error
//    int ok=&digit;// this cannot be done 

   cout<<"before INCRMENT POINTER"<<digit<<endl;
   (*pointer)++;  // *p litreaky means we are dealing the value stored not the address 

   cout<<"after INCRMERNT POINTER"<<digit<<endl;







    cout<<"    C  OP YI N  G            T  H  E         P O IN T E R  "<<endl;

    int *copyPointer=pointer;
    cout<< copyPointer<<" <---->" <<pointer<<endl;
    cout<< *copyPointer<<" <---->" <<*pointer<<endl;




    cout<<"  ARTHEMATIC OPERATION IN THE POINTERS"<<endl;


    int z=4;
    int *t=&z;
    *t=*t+1;
    cout<<"addtion in pointrs:" <<*t<<endl;//5
     cout<<"normal value of t is ::" <<t<<endl;//
    t=t+1;
    cout<<"addtion in values of pointrs:" <<t<<endl;//+4 byte
    t=t+1;
    cout<<"addtion in values of pointrs+2:" <<t<<endl;//+4 byte
    t=t+1;
    cout<<"addtion in values of pointrs+3:" <<t<<endl;// +4byte


    
   



}