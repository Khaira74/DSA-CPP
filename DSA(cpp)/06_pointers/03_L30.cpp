#include <iostream>
#include <cmath> // For pow

using namespace std;







int main(){
    int i=3;
    int *p=&i;
    int**p2=&p;
    cout<<"preinting  p "<<p <<endl;
    cout<<"address of  p "<<&p <<endl;
    cout<<"  p "<<*p2 <<endl;// it points to the p
    cout<<"preinting  p "<<**p2 <<endl;// it points to the i 






    // simplaraties
    cout<<"          S I M L A R A T TI E S        I  N           T HE    V A  L U E S  "<<endl;
    // it gives 3
    cout<<"preinting  i "<<i <<endl;
    cout<<"preinting  i "<<*p <<endl;
    cout<<"preinting  i "<<**p2 <<endl;



    
// it gives the address of i
    cout<<"preinting  i "<<&i <<endl;
    cout<<"preinting  i "<<p <<endl;
    cout<<"preinting  i "<<*p2 <<endl;



    // it prints the address of the p 
    cout<<"preinting  p address "<<&p <<endl;
    cout<<"preinting  i "<<p2 <<endl;








}
void update(int **p2){
    p2=p2+1;// no change 
    *p2=*p2+1;//  value  at p chnages
    **p2=**p2+1;// value changes of num

}