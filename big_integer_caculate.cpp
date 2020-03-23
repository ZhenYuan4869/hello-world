#include<iostream>  
#include<cmath>  
#include<string>
using namespace std;  
string big_add(string s1,string s2)
{
    string ans;
    ans = "";
    int len1,len2,flag,min_size,temp,rest;
    temp = 0;
    flag = 0;
    min_size = 0;
    len1 = s1.size();
    len2 = s2.size();
    if(len1==0)
    {
        return s2;
    }
    if(len2==0)
    {
        return s1;
    }
    if(len1>=len2)
    {
        min_size = len2;
        rest = 1;
    }
    else{
        min_size = len1;
        rest = 2;
    }
    for(int i = 0;i<min_size;i++)
    {
        temp = 0;
        temp = (s1[len1-i-1]-'0')+(s2[len2-i-1]-'0')+flag;
        if(flag == 1)
        {
            flag = 0;
        }
        if(temp>=10)
        {
            flag = 1;
        }
        ans = to_string(temp%10)+ans;
    }
    if(rest == 1)
    {
        for(int i=len1-len2-1;i>=0;i--)
        {
            ans = s1[i]+ans;
        }
    }
    else
    {
        for(int i=len2-len1-1;i>=0;i--)
        {
            ans = s2[i]+ans;
        }
    }
    
    return ans;
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<big_add(s1,s2)<<endl;
    return 0;
}