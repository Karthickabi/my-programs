/*Problem Description
In Max sum problems, Two friends A and B are playing with an array of integers. They both agree upon the operations to be performed on the array but differ on choice of window size to perform the said operations.

The operations to be performed on the array are explained below:

· One can choose to add at the most X consecutive elements.

· After performing the addition operation, it is mandatory to skip the next element in the array.

· The goal is to achieve maximum sum by choosing appropriate elements in the array.

A wants X to be W, while B wants X to be (W + D). This is the only difference that they have. Your task is to find out who wins. Winner is the person whose sum is higher.

The inputs that will be provided are values of elements of array, value of W and value of D.

Example:

Array: 4 5 6 1 2 7 8 9

Window Size (W): 3

Output: 39

Explanation

· We will choose to add elements 4, 5, 6 since window size is 3.

· Since one addition operation is complete, we have to skip one element which is 1.

· We choose to skip element 2 because the next three values are also higher than 2.

· The max sum thus obtained is 39.

Now suppose the array was: 4 5 6 1 2 3 7 8 9

· We will choose to add elements 4, 5, 6 since window size is 3.

· Since one addition operation is complete, we have to skip one element which is 1.

· Now we choose to pick element 2 because we can skip element 3 and still pick up the next 3 values viz 7, 8, 9.

· The max sum thus obtained is 41.

· Note that we picked up only one element in second selection since constraint is only on maximum number to be chosen, not minimum.

Now suppose the array was: 4 5 6 7

· Since one can start from any index, we choose element 5, 6, 7.

· The max sum thus obtained is 18.

The above examples illustrate the game with a fixed window size of W. Since B prefers to play the same game with the size of W+D, the steps will remain the same but the max sum output may be different. Print different output depending on whether A wins, B wins or it’s a tie.

Constraints
0 <= N <= 10 ^ 5

5 <= W <= 10 ^ 5

-10^5 <= D <= 10^5

0 < (W + D) <= N

0 <= elements in array <= 10 ^ 9

Input
First line contains three space separated integers N and W and D respectively, which denote

N – size of array

W – window size

D – difference

Second line contains of N space separated integers denoting the elements of the array

Output
If B wins, print “Right <absolute difference>”

If A wins, print “Wrong <absolute difference>”

If It’s a tie, print “Both are Right”

Refer Examples section for better understanding.

Time Limit
1

Examples
Example 1

Input

8 5 -2

4 5 6 1 2 7 8 9

Output

Wrong 2

Explanation
Here we have given N = 8, W = 5, D = -2

A will maximize the sum of elements of the array using window size 5. Whereas B will maximize the sum of elements of the array using window size 3 (5-2).

Using logic as depicted above A will get the max sum as 41 and B will get the max sum as 39. The absolute difference is 41 – 39 = 2.

Hence, output will be: Wrong 2

Example 2

Input

9 2 2

4 5 6 1 2 3 7 8 9

Output

Right 10

Explanation
Here we have given N = 9, W = 2, D = 2

A will maximize the sum of elements of the array using window size 2. Whereas B will maximize the sum of elements of the array using window size 4 (2+2).

Using logic as depicted above A will get the max sum as 33 and B will get the max sum as 43. The absolute difference is 43 – 33 = 10.

Hence, output will be: Right 10

Example 3

Input

10 9 -3

4 5 6 3 2 3 7 8 9 2

Output

Both are right

Explanation
Here we have given N = 10, W = 9, D = -3

A will maximize the sum of elements of the array using window size 9. Whereas B will maximize the sum of elements of the array using window size 6 (9-3).

Using logic as depicted above A will get the max sum as 47 and B will get the max sum as 47. The absolute difference is 47 – 47 = 0.
                                                             --------------COMPLETED---------------
*/#include <bits/stdc++.h> 
using namespace std; 
int dp[10000]; 
//iterative method
int Max_Sum(int arr[], int K, int N)
{int k[N+1];
memset(k, 0, sizeof(k));
for(int i = 1; i <=K ; i++)
k[i] = k[i-1]+arr[i-1];
for(int i = K+1; i<=N; ++i)
{int t=0;
	for(int j=i-1;j>=(i-K-1);j--){
	t+=arr[j];
	 k[i] = max(k[i], k[j]+t-arr[j]);}}
	return k[N];}
//recusion method
int maxSum(int arr[], int i, int n, int k)//,bool visit[]) 
{if (i >= n) 
return 0; 
/*if (visit[i])
return dp[i]; 
visit[i] = 1; */
int tot = 0; 
dp[i] = maxSum(arr, i + 1, n, k/*,visit*/); 
for (int j = i; j < i + k and j < n; j++){
    tot += arr[j]; 
	dp[i] = max(dp[i], tot +/*maxSum(arr, j + 2, n, k,visit)*/(j+2<n?dp[j+2]:0));}
return dp[i];} 
int main() 
{int n,a,b;
cin>>n>>a>>b;
b+=a;
int arr[n],k;
for(int i=0;i<n;i++)
cin>>arr[i];
//bool v1[n]={0};
k=maxSum(arr, 0, n, a);
k-=Max_Sum(arr,b,n);//-Max_Sum(arr,b,n);
if(k==0)
printf("BOTH ARE RIGHT");
else
printf("%s %d ",k>0?"Wrong":"Right",abs(k));
return 0;}
