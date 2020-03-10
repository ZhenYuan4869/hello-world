#include<iostream>
#include<string>
using namespace std;
void Filter(const char *a1, long length, char *a2)
{
    int j,k = 1;
    a2[0] = a1[0];
    for(int i = 1;i<length;++i)
    {
        for(j = 0;j<k;++j)
        {
            if(a2[j] == a1[i])
            break;
        }
        if(j==k)
        {
            a2[k] == a1[i];
            ++k;
        }

    }
    
}

int main()
{
    char s1[100]={0},s2[100]={0};
    cin>>s1;
    Filter(s1,strlen(s1),s2);
    cout<<s2<<endl;
    return 0;
}