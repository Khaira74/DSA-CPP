
#include<iostream>
using namespace std;
// count digits


int count(int n){
    int count=0;
    while(n>0){
        count=count+1;
        n=n/10;
    }
    return count;
}
int main(){
    int n;
    cout<<"enter:"<<endl;
    cin>>n;
    int answer=count(n);
    cout<<answer<<endl;
    

}
// revrese a number
int reverse(int n){
    int reverseeno=0;
    while(n>0){
        int digit=n%10;// last digit
        reverseeno=(reverseeno*10)/* so that next igit not overlaps but comes at next positionˀ*/+digit;
        n=n/10;// removing last digit
    }
    return reverseeno;


}
int main(){
    int n;
    cout<<"enter:"<<endl;
    cin>>n;
    int answer=reverse(n);
    cout<<answer<<endl;
    

}
// palindrome number // reverse == orignal number


bool palindrome(int n){
    int real=n;
    int reversed=0;
    while(n>0){
        int digit=n%10;
        reversed=reversed*10+digit;
        n=n/10;
    }
    if(real==reversed){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    bool answer=palindrome(n);
    if(answer){
        cout<<"oh yes it is"<<endl;
    }
    else{
        cout<<"no no no lose lose"<<endl;
    }

}


// armstrong of a int n//// sum of power of n of each number,s sum must equal to the number itself

bool armstrong(int n){
    int sum=0;
    int real=n;
    while(n!=0){
        int digit=n%10;
        sum=sum+digit*digit*digit;
        n=n/10;
    }
    if(real==sum){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin>>n;
    bool answer=armstrong(n);
    if(answer){
        cout<<"jattlife"<<endl;
    }
    else{
        cout<<"not a jatt life"<<endl;
    }
}
 

//  print all divisons          
void printing(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    printing(n);
    return 0;

}
// the problem above is that the mutilplation repeat itselef after i*i=n;then its just reversse of above mutlipkiaction
#include<vector>
void printing(int n){
    vector<int>hlo;
    
    for(int i=1;i*i<=n/** till eg n=36 lopp will run till i*i=n// 6*6=36 means i=6 */;i++){

        if(n%i==0){
            hlo.push_back(i);// first this will print the divisor


            if((n/i)!=i){
                hlo.push_back(n/i);// thne this loop will run and print the divison for the above same iteration
            }
        }
    }
    sort(hlo.begin(),hlo.end());
    int size=hlo.size();
    for(int i=0;i<size;i++){
        cout<<hlo[i]<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printing(n);
    return 0;

}

//  prime
bool prime(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    int n;
    cin>>n;
    bool answer=prime(n);
    if(answer){
        cout<<"not prime"<<endl;
    }
    else{
        cout<<" prime"<<endl;
    }

    return 0;
}
// count prime 
bool prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return true;
        }
        else{
            return false;
        }
    }
}

int howMANYprime(int n){
    int count=0;
    for(int i=2;i<n;i++){
        if(prime(i)){
            count++;
        }
    }
    return count;
        
}
int main(){
    int n;
    cin>>n;
    int answer=howMANYprime(n);
    cout<<answer<<endl;
    

    return 0;
}
// hcf and gcd 
// euclids algo 
// gcd(a,b)=gcd(a-b,b)  
// gcd(a,b)=gcd(a%b)

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
    }
    return a;
}
 