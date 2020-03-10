// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
using namespace std;
int main() {
    int a,b;
    while(cin >> a >> b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
        cout << a+b << endl;
}

// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n,ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x; scanf("%d",&x);
            ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}