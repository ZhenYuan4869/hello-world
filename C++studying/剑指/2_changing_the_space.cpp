/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
//传进去的length是可用长度
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL||length<=0)
        {
            return;
        }
        int i=0;
        int count=0;//计算有多少个空格,以及处理之后字符串长度是多少
        int string_length = 0;//字符串长度
        while(str[i] != '\0')
        {
            string_length+=1;
            if(str[i] == ' ')
            {
                count += 1;
            }
            i++;
        }
        if(string_length+2*count+1>length)//如果计算后的长度大于总长度就无法插入
            return;
        //从后往前覆写才不会产生错误重写
        for(i=string_length;i>=0;i--)
        {
            str[i+2*count]=str[i];
            if(str[i]==' ')
            {
                str[i+2*count]='0';
                str[i+2*count-1]='2';
                str[i+2*count-2]='%';
                count--;
            }
        }
        
	}
};