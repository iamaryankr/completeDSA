class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty())mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=mp[nums1[i]];
        }
        return nums1;
    }
};

//next greater element- II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2*n);
        
        for(int i=n; i<2*n; i++){
            nums[i] = nums[i-n];
        }
        
        vector<int> res(n, -1);
        stack<int> st;
        
        for(int i=0; i<2*n; i++){
            int ele = nums[i];
            
            while(!st.empty() && ele > nums[st.top()]){				
                if(st.top() >= n){
                    st.top() = st.top() - n;
                }
                res[st.top()] = ele;
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};
