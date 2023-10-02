



// Problem Link - https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

#include <bits/stdc++.h>
using namespace std;




// Brute Force
long long int findSubarray_Brute(vector<long long int> &nums, int n ) {
    
    long long count = 0;


    for(int i = 0;i<n;i++) {
        int sum = 0;
        for(int j = i;j<n;j++) {
            sum += nums[j];

            if(sum == 0) {
                count++;
            }
        }
    }

    return count;

    // Time Complexity is O(n^2)..
    // Space Complexity is O(1)..
}






// Optimal
long long int findSubarray_Optimal(vector<long long int> &nums, int n ) {
    
    long long count = 0;

    unordered_map<int,int> mpp;
    long long sum = 0;

    // beacuse if we have nothing in the subarray...the sum of subarray is 0 too...so as soon we got sum as 0...that sum will 
    // pair with this sum in 1 ways..so we add to the count...if we dont initialize this..then whenver the first array will 
    // come whose sum is 0 ...then it will act like it never appeared before..
    // Suppose we have current sum array as {15,13,12,i}..and arr is {15,-1,-1,j}...now this j can be any number...it can also
    // be a number on adding of which our i can become like 12 or 13 or 15...so u see....at any cost we are considering all 
    // cases....
    // as we want the subarray with sum 0...so before starting searching we need to add mpp[0]=1...in the map.. ..the logic we
    // are using like sum+x = sum...which means x is a subarray with sum 0....but think...when we get the 0 as the running sum
    // for the first time in the array...it actually the 2nd time we have seen the sum = 0 ...till now...which means instead it
    // assigning in the map as ...0->1...we need to count it..
    // consider it in this way...whenver we are getting a 0 sum subarray..we are checking how many times this sum has occured 
    // before...because when the same sum appears again...the number of times it appeared before will be the number of new 
    // subarrays it formed...when 0 appeared for the first time in array...it didn't have appeared before so we do mpp[0]=1..to
    // assign this sum...now think if we get a 0 sum for the first time...so when the running sum = 0 appears for the first time 
    // in the array...it appeared because we added a 0 to the prev sum ...right? so which meanswe have added 0+x=0...so that's 
    // why we initialize this...do dry run for better understanding...
    mpp[0] = 1;

    for(int i = 0;i<n;i++) {
        sum += nums[i];

        if(mpp.find(sum) != mpp.end()) {
            count += mpp[sum];
            mpp[sum]++;
        }else{
            mpp[sum] = 1;
        }
    }

    return count;

    // Time Complexity is O(n)..
    // Space Complexity is O(n)..
}




int main() {

    vector<long long int> nums = {6,-1,-3,4,-2,2,4,6,-12,-7};
    int n = nums.size();

    cout<<findSubarray_Brute(nums,n)<<endl;

    return 0;
}