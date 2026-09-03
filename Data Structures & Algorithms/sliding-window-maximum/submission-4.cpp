class Solution {
private:
    vector<int> tree;

    void build(int idx, int l, int r, const vector<int>& nums){
        if (l == r){
            tree[idx] = nums[l];
            return;
        }

        int m = l + (r-l)/2;
        build(2*idx,l,m,nums);
        build(2*idx+1,m+1,r,nums);

        tree[idx] = max(tree[2*idx],tree[2*idx+1]);
    }

    int query(int idx, int l, int r, int u, int v){
        if (v < l || u > r) return INT_MIN;
        if (u <= l && v >= r) return tree[idx];

        int m = l + (r-l)/2;
        int maxL = query(2*idx,l,m,u,v);
        int maxR = query(2*idx+1,m+1,r,u,v);

        return max(maxL,maxR);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return {};

        tree.assign(4*n,0);
        build(1,0,n-1,nums);
        
        vector<int> res; res.reserve(n-k+1);
        for (int i = 0; i <= n-k; i++){
            int maxVal = query(1,0,n-1,i,i+k-1);
            res.push_back(maxVal);
        }

        return res;
    }
};
