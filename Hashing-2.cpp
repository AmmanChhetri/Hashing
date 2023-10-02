

// Problem Link - https://www.codingninjas.com/studio/problems/k-most-occurrent-numbers_625382


#include <bits/stdc++.h>
using namespace std;


// Brute Force
void getFrequencies_Brute(vector<int> &nums) {

    int n = nums.size();
    
    int k = *max_element(nums.begin(),nums.end());
    vector<bool> visited(k+1,false);
    
    int maxi = INT_MIN;
    int mini = INT_MAX;

    int max_elm = -1;
    int min_elm = -1;

    for(int i = 0;i<n;i++) {

        if(visited[i] == true) {
            continue;
        }


        int count = 1;
        for(int j = i+1;j<n;j++) {
            if(nums[j] == nums[i]) {
                count++;
                visited[j] = true;
            }
        }


        if(count > maxi) {
            max_elm = nums[i];
            maxi = count;
        }

        if(count < mini) {
            min_elm = nums[i];
            mini = count;
        }
    }

    cout<<"The smallest element with maximum Frequency : "<<max_elm<<endl;
    cout<<"The smallest element with minimum Frequency : "<<min_elm<<endl;


    // Time Complexity is O(n^2) + O(n) ..O(n) for finding maximum..
    // Space complexity is O(max(nums)+1)


}





// Better
void getFrequencies_Optimal(vector<int> &nums) {

    int n = nums.size();
    
    // as we want the smallest element which has highest or lowest frequency that's why we are defining a ordered map...
    map<int,int> mpp;
    for(int i = 0;i<n;i++) {
        mpp[nums[i]]++;
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;

    int max_elm = -1;
    int min_elm = -1;

    for(auto it : mpp) {

        // for finding maximum element..
        if(it.second > maxi) {
            maxi = it.second;
            max_elm = it.first;
        }
        
        // for finding minimum element..
        if(it.second < mini) {
            mini = it.second;
            min_elm = it.first;
        }
    }

    cout<<"The smallest element with maximum Frequency : "<<max_elm<<endl;
    cout<<"The smallest element with minimum Frequency : "<<min_elm<<endl;

    // Time Complexity is O(nlogn) + O(m) ...where m = mpp.size()
    // Space complexity is O(n)

}




int main() {
    
    vector<int> nums = {2,5,12,3,16,3,10,9};

    getFrequencies_Brute(nums);
    getFrequencies_Optimal(nums);
    return 0;
}