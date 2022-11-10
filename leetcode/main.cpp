#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        bool cnt = false;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target ){
                        output.push_back(i);
                        output.push_back(j);
                        cnt = true;
                        break;
                    }
                }
                if(cnt == true){
                break;
            }
        }
                 return output;
    }   
};