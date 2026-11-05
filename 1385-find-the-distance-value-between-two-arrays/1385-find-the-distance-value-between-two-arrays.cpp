class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int distance = 0;

        for(int num : arr1){
            int start = 0, end = arr2.size() - 1;
            bool found = false;
            while(start <= end){
                int mid = start + (end - start)/2;
                if(abs(num - arr2[mid]) <= d){
                    found = true;
                    break;
                }
                else if(num - arr2[mid] > d) start = mid+1;
                else end = mid-1;
            }
            if(!found) distance++;
        }

        return distance;
    }
};