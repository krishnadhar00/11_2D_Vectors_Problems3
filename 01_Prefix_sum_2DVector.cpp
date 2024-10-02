// Given a matrix 'a' of dimension nxm and 2 coordinates (l1,r1) and (l2,r2), return the sum of the rectangle from (l1,r1) to (l2,r2)
// Brute Force Approach 
#include<iostream>
#include<vector>
using namespace std;

int rectangleSum(vector<vector<int>> &vec, int l1, int  r1, int l2, int r2)
{
    // Brute force approach
    int sum = 0;
    for(int i=l1;i<=l2;i++)
    {
        for(int j=r1;j<=r2;j++)
        {
            sum += vec[i][j];
        }
    }
    // return sum;

    // Prefix Sum approach
    // First counting the prefix sum in each row and then from l1 to l2 count the number and subtract it.
    // Calculating the horizontal sum for each row in the matrix.
    int count = 0;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            vec[i][j] = vec[i][j]+ vec[i][j-1];  // counting the prefix sum in each row.
        }
    }
    for(int i=l1;i<=l2;i++)
    {
        if(r1!=0)
        {
            count = count+vec[i][r2]-vec[i][r1-1];  // subtracting from l2 to l1 in each row and adding them.
        }
        else
        {
            count = count + vec[i][r2];
        }
    }
    return count;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum = rectangleSum(matrix, l1,r1,l2,r2);

    // Printing the prefix sum of each row in the matrix.
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Sum is : "<<sum;

}