#include<bits/stdc++.h>
using namespace std;
#include <fstream>
vector<vector<int>> coor;
    int dfs(int x,int y,vector<vector<char>>& board,int pos,string word)
    {
        vector<pair<int,int>> v={{0,1},{0,-1},{1,0},{-1,0}};
        if(pos==word.length()-1)
        {coor.push_back({x,y});return 1;}
        char temp=board[x][y];
        board[x][y]='#';
        for(auto u:v)
        if(x+u.first>=0&&x+u.first<board.size()&&y+u.second>=0&&y+u.second<board[0].size())
        {
            int res=0;
            if(board[x+u.first][y+u.second]==word[pos+1])
            res=dfs(x+u.first,y+u.second,board,pos+1,word);
            if(res==1)
            {
            	board[x][y]=temp;
            	coor.push_back({x,y});
            	return 1;
			}
        }
        board[x][y]=temp;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> v(board[0].size(),0);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]&&dfs(i,j,board,0,word))
                return 1;
            }
        }
        return 0;
    }


int main() {
    // Example 2D vector
    
    // Open the output file
    ofstream outputFile("output.txt");
	ofstream opt("opt.txt");
    // Check if the file is open
    if (!outputFile||!opt) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    vector<vector<char>> v;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
    vector<char> v1(n);
        for(int j=0;j<n;j++)
    {
        cin>>v1[j];
    }
    v.push_back(v1);
    }
    string s;
    cin>>s;


    bool x=exist(v,s);
    // Write the 2D vector to the file
    
    for(auto p:coor)
    {
    	outputFile << p[0] <<" " <<p[1] <<endl;
	}
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[0].size();j++)
		{
			opt<<v[i][j]<<" ";
		}
		opt<<endl;
	}
    // Close the file
    outputFile.close();

    std::cout << "Data written to the file successfully." << std::endl;

    return 0;
}