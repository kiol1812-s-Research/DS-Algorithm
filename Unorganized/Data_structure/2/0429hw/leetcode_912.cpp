class Solution {
public:
    void swap(int &a, int &b){
        int tmp=a;
        a = b;
        b = tmp;
    }
    int pivot(vector<int>& nums, int start, int end){
        int pivot=nums[start], swapIdx=start;
        for(int i=start+1; i<nums.size(); i++){
            if(pivot>nums[i]){
                swapIdx++;
                swap(nums[swapIdx], nums[i]);
            }
        }
        swap(nums[start], nums[swapIdx]);
        return swapIdx;
    }
    void qs(vector<int> &nums, int left, int right){
        if(left<right){
            int pivotIdx = pivot(nums, left, right);
            qs(nums, left, pivotIdx-1);
            qs(nums, pivotIdx+1, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums, 0, nums.size()-1);
        return nums;
    }
};
class Solution {
public:
    void swap(int &a, int &b){
        int tmp=a;
        a = b;
        b = tmp;
    }
    void qs(vector<int> &nums, int left, int right){
        if(left<right){
            int i=left, j=right+1, pivot=nums[left];
            do{
                do{
                    i++;
                }while(i<nums.size()&&nums[i]<pivot);
                do{
                    j--;
                }while(j>=0&&nums[j]>pivot);
                if(i<j) swap(nums[i], nums[j]);
            }while(i<j);
            swap(nums[left], nums[j]);
            qs(nums, left, j-1);
            qs(nums, j+1, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qs(nums, 0, nums.size()-1);
        return nums;
    }
};