 #include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> &vec)
{
    for(int i =0; i<9; i++)
    {
        for(int j =0; j<9;j ++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<< endl;
    }
}

bool isSafe(vector<vector<int>> &vec,int row, int col, int value)
{
    for(int k =0;k<9;k++)
    {
        if(vec[row][k] == value || vec[k][col] == value)
        {
            return false;
        }
    }

    int rowchunk = row / 3;
    int colchunk = col / 3;

    for(int i = rowchunk*3; i < (rowchunk + 1) * 3; i++)
    {
        for(int j = colchunk*3; j < (colchunk + 1) * 3; j++)
        {
            if(vec[i][j] == value)
            {
                return false;
            }
        }
    }
    return true;
}

void func(vector<vector<int>> &vec,int row, int col)
{
    if(row == 9)
    {
        display(vec);
        return;
    }
    if(col == 9){
        func(vec,row+1, 0);
        return;
    }
    if(vec[row][col] == 0)
    {
        for(int i =1; i<=9; i++)
        {
            if(isSafe(vec,row , col , i))
            {
                vec[row][col]=i;
                func(vec,row, col+1);
                vec[row][col]=0;
            }
        }
    }
    else 
    {
        func(vec,row, col + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    std::vector<vector<int>> vec(N,vector<int>(N,0));
    for(int i =0; i<N; i++)
    {
        for(int j =0; j<N; j++)
        {
            cin>>vec[i][j];
        }
    }
    func(vec,0,0);
    
    return 0;
}
