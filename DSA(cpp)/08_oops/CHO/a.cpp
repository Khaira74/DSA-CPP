#include<iostream>
using namespace std;


class Time{

    public:
    int hours;
    int minutes;
    int seconds;

    Time(int h,int t,int s){
        this->hours=h;
        this->minutes=t;
        this->seconds=s;
    }
    Time operator+(Time& t){
        int totalSeconds = seconds + t.seconds;
        int totalMinutes = minutes + t.minutes + totalSeconds / 60;
        int totalHours = hours + t.hours + totalMinutes / 60;    
        return Time(totalHours,totalMinutes,totalSeconds);
    }
    void print(){
        cout << hours << " " << minutes << " " << seconds << endl;

    }

};


int main(){
    int hours1,minutes1,seconds1;
    cin>>hours1>>minutes1>>seconds1;
    int hours2,minutes2,seconds2;
    cin>>hours2>>minutes2>>seconds2;

    Time t1(hours1,minutes1,seconds1);
    Time t2(hours2,minutes2,seconds2);
    Time t3=t1+t2;
    t3.print();


}