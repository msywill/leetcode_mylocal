#include <bits/stdc++.h>
using namespace std;

class Solution79{
public:
    int m, n;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1,};
    bool find = false;
    bool exist(vector<vector<char>>&board, string word){
        m = board.size();
        n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0]) // 找到第一个匹配的字母
                {
                    dfs(board,visited,word,i,j,0);
                    if(find) return find;
                }
            }
        }
        return find;


    }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, string& word, int i, int j,int idx ){
        if(visited[i][j]) return; //已经访问过
        if(board[i][j] != word[idx]) return; //访问到的字符不符合

        //未访问过 且 符合

        if(idx == word.size()-1) {find = true; return;}

        int tx,ty;
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            tx = i+dx[k];
            ty = j+dy[k];
            if(tx>=0 &&tx<m && ty>=0 && ty<n){
                dfs(board,visited,word,tx,ty,idx+1);
            }

        }
        visited[i][j] = 0;
    }
};
int main(){
    //省略 明天再写
    return 0;
}