#include <iostream>
#include <string>
using namespace std;
int sum_of_digits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int super_digit(int num){
    while(num>=10){
        num=sum_of_digits(num);
    }
    return num;
}
int main(){
    string n;
    int k;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter k: ";
    cin>>k;
    int sum=0;
    for(char digit:n){
        sum+=digit-'0';
    }
    int total=sum*k;
    int result=super_digit(total);
    cout<<"Super Digit: "<<result<<endl;
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
