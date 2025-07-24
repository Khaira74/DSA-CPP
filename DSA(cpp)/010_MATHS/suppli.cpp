#include <iostream>
#include <cmath> // For pow


using namespace std;
// count digits
int counts(int n){
    int count=0;
    while(n>0){
        // int digit=n%10;
        count+=1;
        n=n/10;

    }
    return count;


}
//reverse a number

void reversing (int n){
    int reverse=0;
    while(n>0){
        int digit=n%10;
        reverse=reverse*10+digit;
        n=n/10;

    }
    cout<<reverse<<endl;
    


}
int reversings(int n){
    int reverse=0;
    while(n!=0){
        int digit=n%10;
        reverse=reverse*10+digit;
        n=n/10;

    }
    return reverse;

}
//check palindrome 

bool palindome(int n){
    int reverse=reversings(n);
    if(n!=reverse){
        return false;

    }
    else{
        return true;
    }

}
bool armstrong(int n){
    int og=n;
    int sum=0;
    while(n!=0){
        int digit=n%10;
        sum=sum+pow(digit,3);
        n=n/10;
    }
    if(sum!=og){
        return false;

    }
    else{
        return true;
    }

}


// all divisors

void divisors(int n){
    for(int i=0;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    //  cout << endl; // Move to the next line after printing all divisors

}



// prime number 

bool prime(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            count++;
            
            
        }
    }
    if(count>2){
        return false;
    }
    return true;

}
int main(){

    int n;
    cin>>n;



    // // cout<<counts(n)<<endl;




    // reversing(n);
    // cout<<reversings(n)<<" "<<"hnjiii okko"<<endl;



    // if(palindome(n)){
    //     cout<<"yes it is"<<endl;
    // }
    // else{
    //             cout<<"nonon it is"<<endl;

    // }


    //  if(armstrong(n)){
    //     cout<<"yes it is"<<endl;
    // }
    // else{
    //     cout<<"nonon it is"<<endl;

    // }




    // divisors(n);









     if(prime(n)){
        cout<<"yes it is"<<endl;
    }
    else{
        cout<<"nonon it is"<<endl;

    }






    return 0;







}
