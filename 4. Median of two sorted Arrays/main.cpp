#include <iostream>
#include <vector>


class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        double sum = 0;
        for(size_t i =0; i < nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }

        for(size_t i =0; i < nums1.size(); i++){
            sum += nums1[i];
        }
        return sum/nums1.size();
    }
};

int main(){

    double sum = 0;
    std::vector<int> v1 = {2,2,4,4};
    std::vector<int> v2 = {2,2,2,4,4};
    for(int i =0; i < v2.size(); i++){
        v1.push_back(v2[i]);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
    }
    
    for (int i = 0; i < v1.size(); i++)
    {
        sum += v1[i];
    }


    std::cout << "Median der Summe: " << sum/v1.size();

    



    return 0;
}