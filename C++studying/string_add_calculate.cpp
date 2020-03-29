//Fibonacci sequence string
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    string s1,s2;
    cin>>N>>s1>>s2;
    string ans1,ans2,ans3;
    ans1=s1;
    ans2=s2;
    if (N>=3)
    {
        for(int i=3;i<=N;i++)
        {
            ans3 = ans1 + ans2;
            ans1=ans2;
            ans2=ans3;
        }
    }

    if(N==1)
    {
        ans3=ans1;
    }
    else if(N==2)
    {
        ans3=ans2;
    }
    int len = ans3.size();

    int count[26]={0};
    int temp = 0;
    char letter;
    
    for(int i=0;i<len;i++)
    {
        temp = ans3[i]-97;
        count[temp] +=1;
    }

    for(int i=0;i<26;i++)
    {
        if(count[i]!=0)
        {
            letter = i+97;
            cout<<letter<<':'<<count[i]<<endl; //a:8
        }
    }

    return 0;
}