/*西西是某公司的一名员工，该公司目前正在做的项目还有N天截止。
为鼓励员工加班，在这N天内该公司每天都会为当天加班的员工发放奖金。
具体来说，对于当天加班的某位员工，若该员工已经连续加班了i天（1≤i≤N），则其当天能获得的奖金为i
（例如 ，第一天加班，则此时记为连续加班1天，获得的奖金为1）。西西制定了这N天内的加班计划，
他每天要么加班，要么不加班，要么不确定加不加班
（有50%的概率加班，剩下50%的概率不加班），那么西西在这N天内能获得的总奖金的期望是多少？
#include <iostream>*/

//第一行包含一个整数N，1≤N≤10^5。

//第二行包含N个空格隔开的整数t1到tN，0≤ti≤2。若ti=0，则表示西西在第i天不加班；
//若ti=1，则表示西西在第i天会加班；若ti=2，则表示西西在第i天有50%的概率加班，剩下50%的概率不加班。

//仍未完成
#include <iostream>
using namespace std;
int calculate(int days, int date[],int count,int j)
{
    
    double temp_money = 0;
    double money = 0;
    for(int i=j;i<days;i++)
    {
        if(date[i]==0)
        {
            count = 0;
        }
        else if(date[i]==1)
        {
            count +=1;
            money = money + count;
        }
        else if(date[i]==2)
        {
            if(j==days-1)
            {    
                money = money+0.5*(money+1);
                return money;
            }
            else
            {
                if(date[i+1]!= 0)
                {
                    calculate(days,date,count,i+1);
                }
            }
            
        }

    }
    return money;

}

int main(void)
{
    int days;
    cin>>days;
    int date[days];
    double money[days];
    for(int i=0;i<days;i++)
    {
        cin>>date[i];
    }
    //cout<<date<<endl;
    cout<<calculate(days, date,0,0)<<endl;
}