#include<iostream>  
#include<cmath>  
#include<string>
using namespace std;  
int main()
{
    int a = 1234;
    char b = '5';
    string s = "45";
    a = b - '0'+'0';//这里a为asc的相差
    cout<<a<<endl;
    char c = '6';
    c = c+'0';
    cout<<c<<endl;
    return 0;
}