
/*
输入：s = "3[a]2[bc]"
输出："aaabcbc"

输入：s = "3[a2[c]]"
输出："accaccacc"
 */

#include <bits/stdc++.h>
using namespace std;

// 结构体允许存储不同类型的数据项 ，使用访问成员运算符.
struct TreeNode{
    int data;
    TreeNode *next;
};


class Node{
public:
    int data;
    Node *next;

    Node(int data =0, Node *p = NULL){ //构造函数
        this->data = data;
        this->next = p;
    }

};


class Solution{
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i = 0; i<s.size(); i++){

            if(s[i]>='0'&& s[i]<='9'){
                int t = i;
                while(s[i]!='['){
                    i++;
                }

                string tmp1 = s.substr(t,i-t);
                st.push(tmp1);
                //跳出循环时i指向[
            }//此时需要再次判断一下i
            if(s[i] == '[')
            {
                st.push("["); //左括号进st ， 进入下一次循环
            }
            if(s[i]>='a' && s[i]<='z'){
                int t = i;
                while(s[i]>='a' && s[i]<='z'){
                    i++;
                }//s[i] 为非字母的时候跳出
                string tmp = s.substr(t,i-t); // 字符串压栈 跳出while的时候 i为 [ 或 ]
                st.push(tmp);
                i = i-1;//回退一步来到最后一个字母 进入下一次循环后检查是否为 [
            }
            if(s[i] == ']'){
                string str;
                vector<string> tmp;
                while(st.top()!="["){
                    tmp.emplace_back(st.top());
                    st.pop();
                }
                for(int i = tmp.size()-1;i>=0;i--)
                {
                    str += tmp[i];
                }
                st.pop();
                int k = stoi(st.top());
                st.pop();
                string ans;
                for(int i=0;i<k;i++)
                {
                    ans += str;
                }
                st.push(ans);
            }

        }
        string res;
        while(!st.empty())
        {
           res = st.top()+res;
            st.pop();
        }
       // reverse(res.begin(),res.end());
        return res;
    }

};


int  main()
{

    string input;
    getline(cin,input);
    class Solution mylocal;
    string ans = mylocal.decodeString(input);
    cout<<ans<<endl;


    return 0;

}