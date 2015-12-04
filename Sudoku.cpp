#include<bits/stdc++.h>
using namespace std;
#define N 9
#define UNASSIGNED 0

bool UsedInRow(int grid[N][N],int row,int n)
{
    for(int i=0;i<N;i++)
        if(grid[row][i]==n)
            return true;
    return false;
}
bool UsedInColumn(int grid[N][N],int col,int n)
{
    for(int i=0;i<N;i++)
        if(grid[i][col]==n)
            return true;
    return false;
}
bool UsedInSquare(int grid[N][N],int rowStart,int colStart,int n)
{
    for(int i=rowStart;i<=rowStart+2;i++)
        for(int j=colStart;j<=colStart+2;j++)
            if(grid[i][j]==n)
                return true;
    return false;
}
bool isSafe(int grid[N][N],int row,int col,int n)
{
    return (!UsedInColumn(grid,col,n)&&!UsedInRow(grid,row,n)&&!UsedInSquare(grid,row-row%3,col-col%3,n));
}
bool findUnassignedLocation(int grid[N][N],int &row,int &col)
{
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(grid[row][col]==UNASSIGNED)
                return true;
    return false;
}
bool Sudoku(int grid[N][N])
{
    int row,col;
    if(!findUnassignedLocation(grid,row,col))   //No unassigned location
        return true;


    //Check digits 1 to 9 for unassigned location
    for(int i=1;i<=9;i++)
    {
        if(isSafe(grid,row,col,i))
        {
            grid[row][col]=i;

            if(Sudoku(grid))
                return true;
            grid[row][col]=UNASSIGNED;
        }
    }

    return false;
}
void PrintGrid(int grid[N][N],int row,int col)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
//    cout<<endl;
}
int main()
{
//    freopen("Sudoku_input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {


    int grid[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
    if(Sudoku(grid))
        PrintGrid(grid,N,N);
    else
        cout<<"No solution\n";
    }
}
