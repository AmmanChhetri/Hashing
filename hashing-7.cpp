



// Problem Link - https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1 

#include <bits/stdc++.h>
using namespace std;







// Brute Force 
// As we need to count unique elements in each window...so what i will do is i will use 2 nested for loops to get the particular 
// elements in the window...and then i will add it to the set..so we know set doesn't stores the duplicates...so we will have
// all unique elements...in the set..after each window...and then after this we add the size of the set to the ans array..and 
// after calculation for each window..we need to make set empty for other window...
void countDistinct_Brute (vector<int> &nums, int n, int k) {

    unordered_set<int> st;
    vector<int> ans;


    for(int i = 0;i<=n-k;i++) {
        for(int j = 0;j<k;j++) {
            st.insert(nums[i+j]);
        }

        ans.push_back(st.size());
        st.clear();
    }
    
    // Printing the number of unique elements in each window...
    cout<<" No. of unique elements in each window : ";
    for(int i = 0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    // Time Complexity is O(nk)...
    // Space Complexity is O(n) (ie. extra space complexity is O(n) for set)..but we are using O(n) for ans array as well..though
    // our algorithm only using O(n) space for set...

}






// Better - 
// As the window size is fixed ..so we use slidinig window technique....
// as we have to count the distinct elements in each window...now tell me...how will you count that how many elements are distinct
// in the given window...if we know for a particular window..we have number and count they occured as 1->2, 2->1, 3->1 ...so here
// the number of distint elements are 3..that is 1, 2 & 3....so how do we know which value has occured or which not...so for this 
// we can either use a hash array to remember which element has occured and how many times...

// Now here counting how many times the number has occured is very important ...you cant just remember which element has 
// occured...for instance take this example...{1,2,1,3,4}...now if window size is 4...we cheeck initally we had 1,2 & 3 as unique
// elements ..so after this we add 4 into our window and remove 1 from index 0...now as we remove 1...but we still have 1 
//...one left at index 2...which is inside the current window... so if we would have just remembered the presence we would have
// said ...we have deleted 1 when we moved our window forward....so that's why it necessary to remember the count rather than
// just presence of elements...

int howMany(vector<int> &hash) {
    int n = hash.size();

    int count = 0;

    for(int i = 0;i<n;i++) {
        if(hash[i] > 0) {
            count++;
        }
    }

    return count;
} 

void countDistinct_Better (vector<int> &nums, int n, int k) {
        
    vector<int> ans ;
    // here count means number of unique elements in a particular window...
    int count = 0;
    
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++) {
        maxi = max(maxi,nums[i]);
    }
    
    vector<int> hash(maxi+1,0);

    // Pre computation of first k elements...
    for(int i = 0;i<k;i++) {
        hash[nums[i]]++;
    }

    count += howMany(hash);
    ans.push_back(count);
    
    count = 0;
    for(int j = k;j<n;j++) {
        // we need to add this element and we need to remove the element at index j-k...so basically means we need to reduce 
        // the count..
        hash[nums[j]]++;
        hash[nums[j-k]]--;
        count += howMany(hash);
        ans.push_back(count);
        count = 0;
    }

   
    
    // Printing the number of unique elements in each window...
    cout<<" No. of unique elements in each window : ";
    for(int i = 0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    
    

    // Time Complexity is O(n) + O(k) + O(n-k)*O(maxi)...
    // Space Complexity is O(maxi)...
      
}









// Optimal - Same approach of Brute Force but using maps...because it will be time consuming to search the whole array ...when 
//           values may not be present ahead or the values differ very much...so we use maps to hash...

void countDistinct_Optimal(vector<int> &nums, int n, int k) {

    unordered_map <int,int> mpp;
    vector<int> ans;
    
    // Pre computation of first k elements...
    for(int i = 0;i<k;i++) {
        mpp[nums[i]]++;
    }
    
    // addding the size of the map...into the ans vector...as mpp also doesn't store the duplicates...
    ans.push_back(mpp.size());

    // computing for other elements...
    for(int j = k;j<n;j++) {
        
        // for adding element on the front of window...
        if(mpp.find(nums[j]) == mpp.end()) {
            mpp[nums[j]] = 1;
        }else{
            mpp[nums[j]]++;
        }

        // for removing element from the back of window
        
        // after getting the required window..we add the size...but here we only need to add those elements which has value > 0
        // becasuse there might be case when the value of 1 element reduces to 0...but it will still remain in the map..and while 
        // calculating the size of the map...we will consider this element as well...which we don't want....so we need to make 
        // a check whenver we are deleting the element...
        
        if(mpp[nums[j-k]] > 1) {
            // because if it frequency is greater than 1..which means even if we delete it ..its' occurence will still have in 
            // map(ie. value > 0)
            mpp[nums[j-k]]--;
            ans.push_back(mpp.size());
        }else{
            // if the value is 1...which means...if we delete this element...we have value == 0..so we need to remove this element from the map...
            mpp.erase(mpp[nums[j-k]]);
            ans.push_back(mpp.size());
        }
        
    }

    // Printing the number of unique elements in each window...
    cout<<" No. of unique elements in each window : ";
    for(int i = 0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    // Time Complexity is O(k) + O(k-n) .... 
    // Space Complexity is O(m)...where m is the size of the map...
}


int main() {

    vector<int> nums = {1,2,1,3,4,2,3};
    int k = 4;
    int n = nums.size();

    countDistinct_Brute(nums,n,k);
    countDistinct_Better(nums,n,k);
    countDistinct_Optimal(nums,n,k);

    return 0;
}