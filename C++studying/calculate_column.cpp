#include<iostream>  
#include<string>
using namespace std;
int main()
{
    string input_string;
    int match_count = 0;
    int left_column = 0;
    int right_column = 0;
    int length = 0;
    input_string = "";
    cin>>input_string;
    if(input_string=="")
    {
        cout<<match_count<<' '<<left_column<< ' '<<right_column;
        return 0;
    }
    length = input_string.size();
    for(int i=0;i<length;i++)
    {
        if(input_string[i]=='(')
        {
            left_column+=1;
        }
        else if (input_string[i]==')')
        {
            if (left_column>0)
            {
                match_count+=1;
                left_column-=1;
            }
            else
            {
                right_column+=1;
            }
        }
    }
    cout<<match_count<<' '<<left_column<< ' '<<right_column;
    return 0;
}