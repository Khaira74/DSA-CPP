// https://www.youtube.com/watch?v=essQiHKRmrc&list=PLQEaRBV9gAFujcBWJhBT2XXsuMlIfETBy&index=7


// excpetion handling
//an exception is  a unexpected problem that arises during the execution of a program and the prgoram
// then terminates suddenly with some errors


//  try- a code that may or may not throw a error.can contain one or more catch codes 
//  catch-runs if the code has errors and then print the error we got from  the throw
//  throw-its a code inside the if else coditon that check for the erro then its pritned tgrow catch 

#include<iostream>
using namespace std;
class Customer{
    public:
    string name;
    int balance,accout_number;
    Customer(string name,int balance,int accout_number ){
        this->name=name;
        this->balance=balance;
        this->accout_number=accout_number;

    }
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            cout<<balance<<endl;
        }
        else{
            throw"amount should be greater than 0";
        }

    }
    void withrwar(int amount){
        if(amount>0 && balance>=amount){
            balance-=amount;
            cout<<balance<<endl;


        }
        else if(amount<0){
            throw"athe account is empty nothing to remove bankcrupt";
        }
        else{
            throw"balace is low please eneter saller amount";
        }
    }


};


int main(){

    // belwo 2 can be solved with if else but u are not seeing the big picture
    Customer arsh("arshdep",200,100200);
    try
    {
        arsh.deposit(300);
        arsh.withrwar(3000);
    }
    catch(const char *e)
    {
        cout<<"the exceptiopn is beow following  "<<e<<endl;
    }



    // method 2 of exception handoing

    int a=55;
    int b=0;

    try
    {
        if(b==0){
            throw" jatt life baby";
        }
        int ans=a/b;
        cout<<ans<<endl;
    }
    catch(const  char *message)// char as throw is of type cahr
    {
        cout<<"the error is the following "<<message<<endl;
    }


    // when we want to know the type of error

    // can not be solved with if else
    try
    {
        int *p=new int[10000000000000000];

        cout<<"meomory in heap allocated succesely"<<endl;
        delete []p;
    }
    // beloww cannot take any char or int as a catch in  fucntion
    // catch can be of any type 
    // thorw can be of any type like now its a object
    catch(const exception& e)// exception is object of class std::exception

    {
        cout<<"type of exception  " << e.what() << '\n';// bad allocation
    }
    
    
    

}

// std::exception                      // Base class for all standard exceptions
// ├── std::logic_error                // Errors in program logic
// │   ├── std::invalid_argument       // Invalid function argument
// │   ├── std::domain_error           // Argument out of mathematical domain
// │   ├── std::length_error           // Exceeded allowed size/length
// │   └── std::out_of_range           // Accessed element outside container bounds
// │
// ├── std::runtime_error              // Errors during program execution
// │   ├── std::range_error            // Arithmetic result out of range
// │   ├── std::overflow_error         // Arithmetic overflow
// │   ├── std::underflow_error        // Arithmetic underflow
// │   └── std::regex_error            // Regular expression error
// │
// ├── std::bad_alloc                  // Failure to allocate memory (from <new>)
// ├── std::bad_cast                   // Invalid `dynamic_cast`
// ├── std::bad_typeid                // Using `typeid` on null pointer
// ├── std::bad_exception              // Thrown when unexpected exception occurs
// ├── std::bad_function_call          // Calling an empty `std::function`
// └── std::ios_base::failure          // Input/output stream errors (from <ios>)
