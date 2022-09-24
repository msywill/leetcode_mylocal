#include<bits/stdc++.h>

/*
题目描述：
--  对输入字符串检查是否存在非法字符，输出合法字符串（去重）和非法字符串（不去重）
--  对合法字符串循环左移10次，在进行排序输出。（举例：比如字符串"abc"，循环左移一次的结果为"bca"）
输入描述：
(1) 字符串中的字符集合为 '0'-'9'，'a'-'z'，'A'-'Z'，其余为非法字符串（空字符串作为定界符），
有非法字符的字符串被视为非法输入；
(2) 作为输入的字符串个数不超过100，每个字符串长度不超过64；
(3) 作为输入的连续空字符串（空格/制表符/回车/换行符）作为一个空格处理（作为定界符，字符串起始字符不能为空）；
(4) 输入每行只有一个字符串
(5) 输入以空行结束
        输出描述：
(1) 输出合法字符串并去重
(2) 输出所有非法字符串
(3) 对结果1的去重合法字符串循环左移10次
(4) 对结果3合法字符串字符串排序，按ASCII表字符从小到大顺序排序
        注意事项：
--  每输入一个字符后用空格跟下一个字符串隔离，作为输出的所有字符串之间只能有一个空格（作为定界符）；
示例1:
-- 输入
        abc
def
==
acd123
44234tjg
aga'-=
ad--s
        abd
123
abcdef
1234567890123456789012345678901234567890123
45678901234567890123
EDFG
        SDFG
ABC
        DEF
cccc
        a*b=1
dd
87&&^
asdfas
234abc35
765rgfh4sd
1231
123
==
EDFG

-- 输出
        abc def acd123 44234tjg abd 123 abcdef 1234
5678901234567890123456789012345678901234567
8901234567890123 EDFG SDFG ABC DEF cccc dd
asdfas 234abc35 765rgfh4sd 1231
== aga'-= as--s a*b=1 87&&^ ==
bca efd 23acd1 234tjg44 bda 231 efabcd 1234
5678901234567890123456789012345678901234567
8901231234567890 FGED FGSD BCA EFD cccc dd
asasdf 4abc3523 765rgfh4sd 3112
1234567890123456789012345678901234567890123
45678901231234567890 231 234tjg44 23acd1 31
12 4abc3523 765rgfh4sd BCA EFD FGED FGSD as
        asdf bca bda cccc dd efabcd efd
————————————————
版权声明：本文为CSDN博主「拾一滴清水」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_43982238/article/details/91350464


*/
using namespace std;

set<char> num_set = {'0','1','2','3',
                     '4','5','6','7','8','9'
};
set<char> world_set ={'a','b','c','d','e','f','g', 'h', 'i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
        ,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};




vector<string> legal_string(vector<string>& input){

    vector<string> legal_str;
    int flag = 0;

    for(auto tmp_str: input)
    {

        for(int i =0;i<tmp_str.size();i++)
        {
            if(find(num_set.begin(),num_set.end(),tmp_str[i])!=num_set.end() || find(world_set.begin(),world_set.end(),tmp_str[i])!=world_set.end())
            {
                flag = 1;
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag) legal_str.push_back(tmp_str);

    }
    return legal_str;
}

vector<string> non_legal_string(vector<string>& input, vector<string>& legal_str)
{
    vector<string> non_legal_str;
    for(auto tmp_str: input)
    {
        if(find(legal_str.begin(),legal_str.end(),tmp_str)==legal_str.end())
        {
            non_legal_str.push_back(tmp_str);
        }

    }
    return non_legal_str;

}

vector<string> remove_repeat(vector<string>& legal_str)
{
    vector<string> remove_repeat;
    for(auto tmp: legal_str)
    {
        string s;

        for(size_t i =0; tmp.cbegin()+i<tmp.cend();i++)
        {

            if(find(tmp.cbegin()+i+1, tmp.cend(),tmp[i])==tmp.end()){
                s+=tmp[i];
            }
        }
        remove_repeat.push_back(s);

    }
    return remove_repeat;
}

vector<string> left_move(vector<string>& rr_legal_str){
    vector<string> left_move;
    for(auto tmp_str:rr_legal_str)
    {
        cout<<"original: "<<tmp_str <<endl;
        int size = tmp_str.size();
        int n = 10% size;
        string str = tmp_str.substr(n, size-n) + tmp_str.substr(0,n);
        left_move.push_back(str);
        cout<<"moved: "<< str << endl;
    }
    return left_move;
}

void print_output(vector<string> my_string)
{
    for(auto tmp: my_string)
    {
        cout<< tmp << ' ';
    }
    cout<<endl;
}

int main(){

    vector<string> input_str;
    string tmp;
    while(getline(cin,tmp))
    {
        int len = tmp.size();
        if(len>0) {

            input_str.push_back(tmp);
        }
        else{
            break;
        }

    }
    vector<string> legal_str = legal_string(input_str);
    vector<string> non_legal_str = non_legal_string(input_str, legal_str);
    vector<string> rr_legal = remove_repeat(legal_str);
    print_output(rr_legal);
    print_output(non_legal_str);
    vector<string> l_m = left_move(rr_legal);
    print_output(rr_legal);
    sort(rr_legal.begin(),rr_legal.end());
    print_output(rr_legal);


    return 0;
}