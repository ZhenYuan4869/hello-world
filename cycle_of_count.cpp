#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int func(unsigned int n, unsigned int k)
{
    signed int flag = (signed int)k;
    signed int len = (signed int)n;
    int number = 0;
    if(n==1)
    {
        return 1;
    }
    if(flag<=0)
    {
        return 0;
    }
    int a[len];
    int count = 0;
    for(int i = 1;i<=len;i++)
    {
        a[i-1] = i;
    }
    for(int i = 0;count != (len-1);)
    {
        if(a[i]!=0)
        {
            number++;
            if(number%flag==0)
            {
                number = 0;
                a[i]=0;
                count += 1;
            }
        }
        i++;
        i = i%len;
    }
    for(int i=0;i<len;i++)
    {
        if(a[i]!=0)
        {
            return a[i];
        }
    }
     return 0;
    
}
int main()
{
    string line;
    cout<<"请输入两个数字："<<endl;
    while(getline(cin,line))
    {
        stringstream ss(line);
        int n = 0, k = 0;
        
        ss>>n>>k;
        if(n<=0)
        {
            break;
        }
        cout<<func(n,k)<<endl;
    }
    return 0;
}