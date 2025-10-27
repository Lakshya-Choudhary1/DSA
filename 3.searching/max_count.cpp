#include <iostream>
#include <vector>
using namespace std;

int maximumCount(vector<int>& nums) {
    int last_negNum_index = -1;
    int first_posNum_index = -1;

    // Find last negative number index
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < 0) {
            last_negNum_index = mid;
            start = mid + 1; // move right
        } else {
            end = mid - 1; // move left
        }
    }

    // Find first positive number index
    start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > 0) {
            first_posNum_index = mid;
            end = mid - 1; // move left to find first
        } else {
            start = mid + 1; // move right
        }
    }

    int total_neg_num = (last_negNum_index == -1) ? 0 : (last_negNum_index + 1);
    int total_pos_num = (first_posNum_index == -1) ? 0 : (nums.size() - first_posNum_index);

    cout << "last_negNum_index = " << last_negNum_index
         << "\tfirst_posNum_index = " << first_posNum_index << endl;

    return max(total_neg_num, total_pos_num);
}

int main() {
    vector<int> nums = {-1, -1, 0, 2};
    int ans = maximumCount(nums);
    cout << "Maximum Count = " << ans << endl;
    return 0;
}
