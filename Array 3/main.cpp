//problem
//we got a m*n grid and we have to calculate the total number of ways to reach
//bottom left corner if we start from the top right one
//NOTE : we can only move rightwards or downwards

/*
#include <bits/stdc++.h>
using namespace std;
//recursive method
//time complexity : O(2^n)
int uniquepaths(int m, int n)
{
    if(m==1 || n==1)
        return 1;

    return uniquepaths(m-1,n) + uniquepaths(m,n-1);
}
int main()
{
    int m,n;
    cin>>m>>n;

    int ans = uniquepaths(m,n);
    cout<<"the to number unique path's are : "<<ans<<endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
//optimized approach
//Time complexity : O(m*n)

int uniquepaths(int m, int n)
{
    //instead of always repeating recursive calls we could go on with simple addition
    //we should first store the base condition as 1 and then move forward
    vector<vector<int>>vect(m,vector<int>(n,1));
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            vect[i][j] = vect[i-1][j] + vect[i][j-1];
        }
    }
    return vect[m-1][n-1];
}
int main()
{
    int m,n;
    cin>>m>>n;

    int ans = uniquepaths(m,n);
    cout<<"the to number unique path's are : "<<ans<<endl;
    return 0;
}


