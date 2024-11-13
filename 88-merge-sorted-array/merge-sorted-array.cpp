//gap method
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n)/2 + (m+n)%2;
        while(gap) {
            int i = 0;
            int j = i + gap;

            while(j<m) {
                if(nums1[i] > nums1[j]) swap(nums1[i], nums1[j]);
                i++; j++;
            }

            while(i<m && j-m<n) {
                if(nums1[i] > nums2[j-m]) swap(nums1[i], nums2[j-m]);
                i++;
                j++;
            }

            while(j-m<n) {
                if(nums2[i-m] > nums2[j-m]) swap(nums2[i-m], nums2[j-m]);
                i++; j++;
            }

            if(gap == 1) break;

            gap = gap/2 + gap%2;
        }

        int j = 0;
        while(j < n) {
            nums1[m+j] = nums2[j];
            j++;
        }
    }
};