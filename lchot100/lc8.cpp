#include<bits/stdc++.h>
using namespace std;

class Solution8{
public:

    int myAtoi(string s){


        //如果不是+ 或 - 读入字符串，直到下一个非数字字符或者结尾
        //转换string
        int i=0, len = s.size(), flag = 1;
        string tmp;
        //先处理' '
        while(i<len && s[i] == ' '){
            ++i;
        }
        //如果不是空格 检查是否为 + 或 - 注意用例有 '+ - 43'
        if(s[i]=='+') {
            flag = 1;
            i++;
        }
        else if(s[i] == '-')
        {
            flag = -1;
            i++;
        }
        //进入读取数字阶段
        while(i<len){
            if(isdigit(s[i])) {
                int t = i;
                while (isdigit(s[i])) {
                    i++;
                }
                tmp = s.substr(t, i - t);
                break;
            }
            //其余情况全部返回0
            else  {return 0;}
        }
        //转换为数字
        int res = 0;
        for(int i=0;i<tmp.size();i++){
            int num = tmp[i]-'0';
            //当前的数字为num 如果res 已经比INT_MAX的 1/10大 或者刚好等于 且num不为0
            if(res>INT_MAX/10 || res == INT_MAX/10 && num>INT_MAX%10) //num>7 最后一位为7
            {
                return (flag+1)?INT_MAX:INT_MIN;
            }
            res = res*10 + num;
        }
        return res;

    }

};



int main()
{
    string input;
    getline(cin,input);
    //方法1
    Solution8 mys;
    int ans = mys.myAtoi(input);
    cout<<ans<<endl;
    //方法2
    stringstream  ss(input);
    int n;
    ss>>n;
    cout<<n<<endl;

    return 0;
}