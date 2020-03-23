#include<iostream>  
#include<cmath>  
using namespace std;  
int binary_search(int nums[],int head,int tail,int target)
{
    int acc = 0;
    if(head==tail||head==tail-1)
    {
        if(nums[head]==target)
        {
            return head;
        }
        else if (nums[tail]==target)
        {
            return tail;
        }
        else 
        {
            return -1;
        }
    }
    if(nums[tail]<target)
    {
        acc = (tail-head+1)/2;
        return binary_search(nums,head,tail-acc,target);
    }
    else if (nums[tail]==target)
    {
        return tail;
    }
    else if (nums[tail]>target)
    {
        acc = (tail-head+1)/2;
        return binary_search(nums,head+acc,tail,target);
    }
    return -1;
}
int main()  
{
    int nums[6] = {-1,0,3,5,9,12};
    int target = 9;
    int len = sizeof(nums)/sizeof(nums[0]);
    int ans = -1;
    ans = binary_search(nums,0,len-1,target);
    if(len == 0)
    {
        return -1;
    }
    if(nums[len-1]<target)
    {
        return -1;
    }
    cout<<ans<<endl;
    return 0;
}