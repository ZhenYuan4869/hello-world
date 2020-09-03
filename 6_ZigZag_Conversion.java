
// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
// 请你实现这个将字符串进行指定行数变换的函数：
// string convert(string s, int numRows);


//其实不需要考虑N一样排列，只要考虑放在第几行，结果是一样的，这算是一个解题点
import java.util.ArrayList;
import java.util.List;

class Solution {
    public String convert(String s, int numRows) {
        //先考虑如果一行就直接输出
        if(numRows==1){
            return s;
        }
//从左到右迭代 ss，将每个字符添加到合适的行。可以使用当前行和当前方向这两个变量对合适的行进行跟踪。
//只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
//这里我考虑用numRows个String来记录数据
        List<String> result = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            result.add("");
        }
        int flag = 0;//分为numRows到2numRows两个闸门
        for (int i = 0; i < s.length(); i++){
            if (flag<numRows) {
                result.set(flag,result.get(flag)+s.charAt(i));
            }else if (flag>=numRows) {
                result.set(2*numRows-flag-2,result.get(2*numRows-flag-2)+s.charAt(i));
            }
            flag++;
            if(flag==2*numRows-2){
                flag=0;
            }
        }
        String returnValue = "";
        for(int i = 0;i<numRows;i++){
            returnValue+=result.get(i);
        }
        return returnValue;
    }
}