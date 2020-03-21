#include<iostream>  
#include<cmath>  
using namespace std;  
int main()  
{  
    int n;  
    long long total_num,old_num;  
    while(cin>>n && n!=0)  
    {  
        total_num=pow(5,n)-4;  
        old_num=n+pow(0.8,n)*pow(5,n)-4;  
        cout<<total_num<<" "<<old_num<<endl;  
    }  
    return 0;  
}  
