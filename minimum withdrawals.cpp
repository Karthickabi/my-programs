#include <bits/stdc++.h>

using namespace std;

int minimumWithdrawal(vector<int> ATM,int X){
    unordered_map<int, int> um;
 
    int sum = 0, maxLen = 0;
 
    // Traverse the given array
    for (int i = 0; i < ATM. size(); i++) {
 
        // Update sum
        sum += ATM[i];
 
        // If the subarray starts
        // from index 0
        if (sum == X)
            maxLen = i + 1;
 
        // Add the current prefix sum
        // with index if it is not
        // present in the map um
        if (um.find(sum) == um.end())
            um[sum] = i;
 
        // Check if sum - K is
        // present in Map um or not
        if (um.find(sum - X) != um.end()) {
 
            // Update the maxLength
            if (maxLen < (i - um[sum - X]))
                maxLen = i - um[sum - X];
        }
    }
 
    // Return the required maximum length
    if(maxLen==0)
    {
        return -1;
    }
    return ATM.size()-maxLen;

}
int main(){
    int N;
    cin>>N;
    vector<int> ATM(N);
    int totalsum=0;
    for(int j = 0;j < N;j++){
        cin>>ATM[j];
        totalsum+=ATM[j];
    }
    int X;
    cin>>X;
    int result;
    result = minimumWithdrawal(ATM,totalsum-X);
    cout<<result;
    return 0;
}
