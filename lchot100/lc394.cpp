
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
    string decodeString(string s)
    {
        stack<pair<int,string>> st;
        if(s.size()==1) return s;
        int num = 0; string res = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                num = num*10;
                num += s[i]-'0';
            }
            else if(s[i] == '['){
                st.push(make_pair(num,res));
                num = 0;
                res = "";
            }
            else if(s[i] == ']'){
                int multi = st.top().first;
                string pre = st.top().second;
                st.pop();
                for(int i=0;i<multi;i++){
                   pre =  pre + res;
                }
                res = pre;
            }
            else{
                res += s[i];
            }

        }
        return res;

    }

};

int  main()
{
//    TreeNode mynode;
//    mynode.data = 2;
//    mynode.next = NULL;
    string input;
    getline(cin,input);


    if(input.size()>0)
    {
        Solution* new_sol = new Solution();
        //使用new方法声明的对象需要指针接收
        //使用完之后需要delete销毁
        delete new_sol;
        Solution sol;
        string ans = sol.decodeString(input);
        cout<<ans<<endl;
    }
    return 0;

}