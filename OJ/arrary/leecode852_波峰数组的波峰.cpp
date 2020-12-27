/*************************************************************************
	> File Name: leecode852_波峰数组的波峰.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/27 18:25:43 2020
 ************************************************************************/

class Solution {
public:
    int find(vector<int> arr){
        int L = 0, R = arr.size() - 1;
        while(L != R){
            int mid = L + R >> 1;
            if(arr[mid]  > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if( arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
                L = mid;
            else if( arr[mid] < arr[mid - 1])
                R = mid;
        }
        return L;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find(arr);
    }
};

