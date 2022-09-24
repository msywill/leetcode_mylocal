#include<bits/stdc++.h>

using namespace std;

vector<string> remove_repeat(vector<string>& input)
{
    unordered_set<string> map;
    for(auto tmp: input)
    {
        map.insert(tmp);
    }
    vector<string> rr_string;
    for(auto tmp:map)
    {
        rr_string.push_back(tmp);
    }
    return rr_string;
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
    vector<string> rr_string = remove_repeat(input_str);
    print_output(rr_string);

    return 0;
}