#include <iostream>
using namespace std;
int main()
{
    int N,T;
    cin>>N>>T;
    int monsters[N][2];
    for(int i=0;i<N;i++)
    {
        cin>>monsters[i][0]>>monsters[i][1];
    }
    
    int current_time_used[10000003];
    current_time_used[10000002]=1;
    int current_exp=0;

    int all_escape_flag[N];
    int temp[2];

    //bubble sort
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N-1-j;i++)
        {
            if(monsters[j][1]<monsters[j+1][1])
            {   
                temp[0] = monsters[j][0];
                temp[1] = monsters[j][1];
                monsters[j][0]=monsters[j+1][0];
                monsters[j][1]=monsters[j+1][1];
                monsters[j+1][0]=temp[0];
                monsters[j+1][1]=temp[1];
            }
        }
    }

    int time_slot=0;
    for(int i=0;i<N;i++)
    {
        time_slot = -1;
        for(int j=0;j<monsters[i][0];j++)
        {
            if(current_time_used[j]==0&&current_time_used[j+1]==0)
            {
                if (j+2==monsters[i][0])
                {
                    time_slot=j;
                }
                else if(current_time_used[j+2]==1)
                {
                    time_slot=j;
                }
            }
        }
        if(time_slot>=0 && all_escape_flag[i]!=1)
        {
            current_time_used[time_slot]=1;
            current_time_used[time_slot+1]=1;
            current_exp+=monsters[i][1];
            all_escape_flag[i]=1;
            
        }
    }

    cout<<current_exp<<endl;
    return 0;
}
    