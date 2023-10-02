

// we know working with maps involve 2 processes ...that is -
    // 1. Storing - Adding values to the map.. like mpp[arr[i]]++ this is storing
    // 2. Fetching - Retrieving values from the map.. like mpp[3]....this is fetching

// whenever we talked about storing and fetching it means something like this in terms of map...

// we have two different types of maps -
    // 1. ordered map
    // 2. Unordered map


/* 

In ordered map ...all elements are always stored in sorted order accoring to the keys...

ordered map defined as.... map<int,int> mpp ....here both storing and fetching takes O(logn) time in all cases(ie.worst,average
& best)...where n is the size of the map.. 

In ordered map key or value can be anything may be int, double, long, char, string , pairs etc.

Example - Suppose we are creating this ordered map...which maps element with its count... (STORING)

    map<int,int> mpp;
    vector<int> nums = {1,4,5,2,5,8,9,5,1,3,6};

    ! Here loop is running for nums.size() ...lets say it to be `n`...
    for(int i =0;i<nums.size();i++) {
        
        ! Now in worst,average & best case ...this storing will take O(logm) time...where m = mpp.size()..
        ! which means total time will be O(n)*O(logm) = O(nlogm)..

        mpp[nums[i]]++;
    }


*/


/*

unordered map stores elements in random order..

unordered map defined as ... unordered_map<int,int> ...here both storing and fetching takes O(1) time in average and best case..
but the worst case takes O(n) time...where n is the number of elements in the map..here worst case is very-very-very Rare...


In unordered map key or value can only be a individual dataTypes like int,char,long etc...it can't be pair...

Example - Suppose we are creating this unordered map...which maps element with its count... (STORING)

    unorered_map<int,int> mpp;
    vector<int> nums = {1,4,5,2,5,8,9,5,1,3,6};

    ! Here loop is running for nums.size() ...lets say it to be `n`...
    for(int i =0;i<nums.size();i++) {
        
        ! Now in average and best case ...this storing will take O(1) time...so total time will be O(n)*O(1) = O(n)..
        ! But in worst case this will take O(m) time..where m = mpp.size()...which means total time code will take is O(nm)..
        mpp[nums[i]]++;
    }

*/