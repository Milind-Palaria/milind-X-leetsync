class Solution {
public:

    void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; 
        int i = (low - 1);  

        for (int j = low; j <= high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        int partitionIndex = i + 1;
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}
    void sortColors(vector<int>& nums) {
        quickSort(nums,0,nums.size() - 1);
    }
};