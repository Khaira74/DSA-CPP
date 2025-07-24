#include <iostream>
#include <cmath> // For pow

using namespace std;

int main(){
    int i=3;
    int *t=&i;
    *t=*t+1;
    cout<<*t<<endl;
    cout<<t<<"before"<<endl;
    t=t+1;
    cout<< t<< "after "<<endl;//increswad by 4






    // real work starts here 
    int arr[10]={0,44};
    
//arr name depict the address of the frist elemnt of array
// compare below 4 statemets 
    cout<<"address of first  memory block or address of array->"<<arr<<endl;//0x16b126da0
    cout<<"address of first  memory block"<<&arr<<endl;//same as above      //0x16b126da0

    // Yes, the full array has an address as a single block:Use ""&arr""" to get that.
    // It's different in type from ""arr"", even though they often print the same address.
    cout <<"address of second elemnt of array" <<(arr + 1) << endl;// 0x16b126da0+4= 0x16b126da4
    cout <<"adding 1 to the add of array"<< (&arr + 1) << endl;   // Skips the entire block of 40 bytes(10*4)

/////othe topic
    cout<<"address of first  memory block"<<&arr[0]<<endl;// same as above //0x16b126da0


    //In most expressions, the name of an array (arr) decays into a pointer to its first element.
// So *arr is really the same as arr[0]
    cout<<"value at oth index  "<<*arr<<endl;//*arr  → *(arr + 0)  → arr[0]  → 0
    cout<<"value at 0th index +1 ---> "<<*arr+1<<endl;//0+1=1
    cout<<"value at oth index +1---> "<<*(arr)+1<<endl;//0+1=1

    cout<<"value at 1th index  "<<*(arr+1)<<endl;//arr[1]'
    // arr[i]=*(arr+i)


    // DIFF BW ARRAY AND POINTER 
    int temp[10];
    // int *ptr=&temp// error cannot initialize a variable of type 'int *' with an rvalue of type 'int (*)[10]So &arr is of type: int (*)[5] → a pointer to an array of 5 ints

    int *ptr=temp;// temp indicates the first elemnt of array
    // *ptr stores the address of first elemnt of temp == 8 bytes
    // it points to the first elemnt of aray
    cout<<" the size of array in  bytes->>"<<sizeof(temp)<<endl;//40 40*4bytes
    cout<<" the size of first elemnt of array in  bytes->>"<<sizeof(*temp)<<endl;//4 bytes
    cout<<" the size of array in  bytes->>"<<sizeof(&temp)<<endl;//8 bytes


    cout<<" the size of ptr in  bytes->>"<<sizeof(ptr)<<endl;// 8 bytes 
    cout<<" the size of object ptr is poting to in  bytes->>"<<sizeof(*ptr)<<endl;//4  bytes 




















    // char arrays
    cout<<"       c  ha  a r  r                A R RY A AYS       "<<endl;
    int array[5]={1,2,3,4,5};
    char ch[6]="abcde";//It means you're storing 5 visible characters 
    //('a', 'b', 'c', 'd', 'e') plus 1 hidden character: the null terminator '\0' that marks the end of 
    // the string  in C-style strings.

    cout<<arr<<endl;
    cout<<ch<<endl;// it not gives address  prints entire char array

    char *c=&ch[0];
    cout<<c<<endl;// same it not gives addres prints full char array




    char tempo='a';
    char *p=&tempo;
    cout<<p<<endl;// as 4 bytes value of char the rest 3 spaces ae printed as random values
    // till these is not null ptr till 4 bytes completes it prints random val

    
    






}