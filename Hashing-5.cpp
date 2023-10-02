

// Problem Link - https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1


#include <bits/stdc++.h>
using namespace std;


// Brute Force 
// Logic - Using 2 for loops to generate all subarrays and then count the subarrays with equal number of 0's and 1's ...
long long int countSubarrWithEqualZeroAndOne_Brute(vector<int> &nums, int n) {

    long long count = 0;

    for(int i = 0;i<n;i++) {
        int zeros = 0, ones = 0;
        for(int j = i;j<n;j++) {
            if(nums[j] == 0) {
                zeros++;
            }else{
                ones++;
            }

            if(zeros == ones) count++;
        }
    }

    return count;


    // Time Complexity is O(n^2)...
    // Space Complexity is O(1)...
}








// Optimal

// Refer to this video for explaination - Remember the question in this video is bit different ...but the logic we are using is 
// same..and explained better there...

// What we will do is we consider all 0's as -1 and all 1's as +1...and for each index we are going to calculate the prefix sum...
// now we know whenver the subarray has equal number of 0's and 1's then the sum of this subarray is always 0...now consider 
// the case {1,1,1,0,0,1,1}..now the prefix sum for this array is {1,2,3,2,1,2,3} ...now we didn't encounter the sum=0...so 
// does this mean we don't have any subarray with equal number of 0's and 1's ? NOOOO!!!....
// if we consider the preifix sum subarray again...we see we have 1,2,3 and then 2....now what does this mean...when we were at 
// index 1 of prefix array..we have sum 2...now at index 3 we again have sum as 2...so can we say we added a number 0...to the
// sum after index 1...so that's why it sum remained same...(visualize this in terms of array and do dry run for better 
//understanding )...so which means we got our subarray with equal number of 1's and 0's ....so this is how you identify..and now
// for counting....prefix sum = {1,2,3,2,1,2,3}...lets traverse this ...we have sum 1..so put this in map...and as it has 
// occured 1 time...just give value to it as 1...when we are at 2....do mpp[2]=1...for 3 do mpp[3]=1...as soon we reach 2 again
// we see..this sum has already seen before which means ...to the total count we add mpp[2] ...and then increase the count of 
// mpp[2]...(implying till now we saw sum of 2...two times..)..then we move ahead...we see sum as 1...which has also seen 
// earlier...so we add mpp[1] to the total count....(now this is because....suppose we have 1 before and now we encounter 1 
// again ...now this new 1 will pair with old 1 only 1 time) ..simlarly we again reach at sum = 2...now before this we have 
// seen 2 twice so we add 2(also think it in this way we had {2....2....2}   now this 3rd 2 can pair with 1st 1 in 1 way making
// the subarray from 1st 2 to 3rd 2 ...and 3d 2 can pair with 2nd 2 in one way making subarray from 2nd 2 to 3rd 2...so total
// subarrays is 2...) ..so on...

// Intially we need to add mpp[0] = 1...because..suppose we have {0,1} ...so sum array is {-1,0} ...so if we use the same logic
// we told above we get count as 0...as our map will be -1 -> 1 , 0 -> 1 ...but it is wrong the whole array also has equal 1's 
// and 0's so we need to consider that as well....so we see there are no repeated sum...but when we start we don't have any sum
// so which means sum = 0....now if we again get sum = 0..which means that will be our answer as well...that's why we are 
// initializing the map with 0 -> 1...so that...if we again find 0..we update count...


// Here we need to remember only three things :
//  1. How to identify that the given subarray has equal number of 0's and 1's ...that is by using the property that adding 0
//     will not change the sum...so whenever we see a repeated sum...which means we must have added 0 to get it again...
//  2. How to count the number of these kind of subarrays...now suppose while traversing we reached a sum 6...which has already
//     occured 2 times before... so this time it is appearing for the 3rd time...now because of this appearance we have 2 new 
//     subarrays...ie ...supppose if we had ... 6...6...6..now the 3rd 6 will...make a subarray with the 1st 6...and 2nd 6 too...
//     so 2 new subarrays are added...
//  3. initializing mpp with mpp[0]=1....because when we don't have anything we still have sum 0 right?...so we need to add it as
//     well...so that if one more 0 appears ...which means...we found the required subarray...this step is basically to count the
//     subarrays from the beginning....so suppose we have array as {1,0,0,1} ...so sum array will be {1,0,-1,0}...so if we see
//     our map will be 1->1, -1->1, 0->1 ...for now and when we reach the last 0..we see we have 1 zero till now..so our count
//     will be increased by 1.....which means we got only 1 subarray ....which is wrong if u calculate manually...it's because
//     when we got the 0 for the first time...it itself forms a subarray from the starting index...that's why initializing 
//     mpp[0]=1...is necessary...
long long int countSubarrWithEqualZeroAndOne_Optimal(vector<int> &nums, int n) {

    unordered_map<int,int> mpp;

    int sum = 0;
    mpp[0] = 1;

    long long count = 0;

    for(int i = 0;i<n;i++) {
        sum += (nums[i] == 1) ? +1 : -1;
        if(mpp.find(sum) != mpp.end()) {
            // we encounter the sum again...so how many times we have seen this sum before this index will be the number of ways
            // of making subarrays with  this indexed sum...
            count += mpp[sum];
            mpp[sum]++;
        }else{
            // we encounter this sum for first time..
            mpp[sum] = 1;
        }
    }
    
    return count;

    // Time Complexit is O(n).
    // Space Complexity is O(n)..

}


int main() {
    vector<int> nums = {1,0,0,1,0,1,1};
    int n = nums.size();

    cout<<countSubarrWithEqualZeroAndOne_Brute(nums,n)<<endl;
    cout<<countSubarrWithEqualZeroAndOne_Optimal(nums,n)<<endl;

    return 0;
}