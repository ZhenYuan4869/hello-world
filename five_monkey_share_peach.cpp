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

int solution2()
{
    int n, i;
    int sum, l, t;
    while (scanf("%d", &n)==1 && n)
    {
        l = 1;
        for (i=1; i<n; i++)
            l *= 5;
        sum = 1+5*(l-1);
        t = sum;
        for (i=1; i<=n-1; i++)
            t = (t-1)/5*4;
        printf("%d %d\n", sum, t+n);
    }
    printf("%d %d\n", sum, t+n);
    return 0;
}
