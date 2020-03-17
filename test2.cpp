#include<iostream>
#include<string>
#include<vector>
using namespace std;
void remove(char *s, char x)
{
    if(s==NULL) 
    {
        s = new char[1]; 
        *s = '\0'; 
    } 
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]== x)
        {
            for(int j=i;j<len-1;j++)
            {
                s[j]=s[j+1];
            }
            len -= 1;
        }
    }
    strncpy(s,s,len);
    s[len] = '\0';
}

int MaximumCopy(const std::vector<int> &s, int C, int &start_index, int &end_index)
{
    int len = s.size();
    int score = 0;
    int temp_rest;
    int min_rest = C;
    int rest = 0;

    // for(int i=start_index;i<=end_index;i++)
    // {
    //     rest += s.at(i);
    // }
    temp_rest = rest;
    for(int i=start_index;i<=end_index;i++)
    {
        score = 0;
        temp_rest = C;
        for(int j=i+1;j<=end_index;j++)
        {
            score += s.at(j);
            if(score>C)
            {
                temp_rest = score-s.at(j);
                if(temp_rest<min_rest)
                {
                    min_rest = temp_rest;
                }
            }


        }
        
        
    }
    if(max_rest!=rest)
    {
        if((rest - max_rest) <= C)
        {
            return (C- rest + max_rest);
        }
        else
        {
            return -1;
        }
        
    }
    return -1;
}  

int main(){
    char src2[] = "abcxyz";
    remove(src2);
    cout<<src2<<endl;
    int n[] = {1,2,3,4,5} ;
    vector<int> vec(n, n+5) ; 
    int a = 0;
    int b = 2;
    int c = MaximumCopy(vec,7,a,b);
    cout<<c<<endl;
}