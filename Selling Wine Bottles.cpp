Selling Wine Bottles
There are N wine bottles packed and arranged in a row from left to right. 
The wine bottles can be sold only one per year with a condition that only the leftmost or the rightmost wine bottle can be sold.
The price of a wine bottle P(i) where 1 <= i <= N (which has not been sold yet) increases by it's initial price P(i) every year.
Find the maximum revenue that can be obtained by selling the wine bottles based on the above conditions. 

Boundary Condition(s):
1 <= N <= 1000 
1 <= P(i) <= 100 

Input Format: 
The first line contains N. 
The second line contains N integers representing the price of the wine bottles separated by a space. 

Output Format:
The first line contains the maximum revenue that can be obtained by selling the wine bottles based on the above conditions.

Example Input/Output 1:
Input:
4
1 4 2 3

Output: 
29
Explanation: 
Max revenue = 1*1 + 3*2 + 2*3 + 4*4 = 29 

Example Input/Output 2: 
Input: 
5 
3 5 7 3 6 

Output:
79

#include <bits/stdc++.h>
using namespace std;
 
#define N 1000
 
int dp[N][N];
 
// This array stores the "optimal action"
// for each state i, j
int sell[N][N];
 
// Function to maximize profit
int maxProfitUtil(int price[], int begin,
                  int end, int n) {
    if (dp[begin][end] != -1)
        return dp[begin][end];
 
    int year = n - (end - begin);
 
    if (begin == end)
        return year * price[begin];   
 
    // x = maximum profit on selling the
    // wine from the front this year
    int x = price[begin] * year +
            maxProfitUtil(price, begin + 1, end, n);
 
    // y = maximum profit on selling the
    // wine from the end this year
    int y = price[end] * year +
            maxProfitUtil(price, begin, end - 1, n);
 
    int ans = max(x, y);
    dp[begin][end] = ans;
 
    if (x >= y)
        sell[begin][end] = 0;
    else
        sell[begin][end] = 1;
 
    return ans;
}
 
// Util Function to calculate maxProfit
int maxProfit(int price[], int n) {
    // reseting the dp table
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
 
    int ans = maxProfitUtil(price, 0, n - 1, n);
 
    int i = 0, j = n - 1;
 
    while (i <= j) {
        // sell[i][j]=0 implies selling the
        // wine from beginning will be more
        // profitable in the long run
        if (sell[i][j] == 0) {
            cout << "beg ";
            i++;
        }  else {
            cout << "end ";
            j--;
        }
    }
 
    cout << endl;
 
    return ans;
}
 
// Driver code
int main() {
    // Price array
    int price[] = { 2, 4, 6, 2, 5 };
 
    int n = sizeof(price) / sizeof(price[0]);
 
    int ans = maxProfit(price, n);
 
    cout << ans << endl;
 
    return 0;
}
