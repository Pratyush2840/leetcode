class Solution {
public:

    void updateSegmentTree(int pos, int i, int l, int r, vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i]++;
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid)
            updateSegmentTree(pos, 2 * i + 1, l, mid, segmentTree);
        else
            updateSegmentTree(pos, 2 * i + 2, mid + 1, r, segmentTree);

        segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
    }

    int querySegmentTree(int start,int end,int i,int l,int r,vector<int>& segmentTree) {
        if (l > end || r < start)
            return 0;

        if (l >= start && r <= end)
            return segmentTree[i];

        int mid = l + (r - l) / 2;

        return querySegmentTree(start,end,2 * i + 1, l, mid,segmentTree) +querySegmentTree(start,end,2 * i + 2,mid + 1,r,segmentTree);
    }

    long long distantSubarrays(vector<int>& nums,long long goal,long long k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        if (k == 0) {
            return 1LL * n * (n + 1) / 2;
        }

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<long long> values = prefix;
        sort(values.begin(), values.end());

        values.erase(
            unique(values.begin(), values.end()),
            values.end()
        );

        int m = values.size();

        vector<int> segmentTree(4 * m, 0);

        long long ans = 0;

        for (int i = 0; i <= n; i++) {

            long long Q = prefix[i];

            long long low = Q - goal - k;
            long long high = Q - goal + k;

            int rightPos = upper_bound(values.begin(),values.end(),low) - values.begin() - 1;
            long long leftCount = 0;

            if (rightPos >= 0) {
                leftCount = querySegmentTree(0,rightPos, 0,0,m - 1,segmentTree);
            }

            int leftPos = lower_bound(values.begin(),values.end(),high) - values.begin();

            long long rightCount = 0;
            if (leftPos < m) {
                rightCount = querySegmentTree(leftPos,m - 1,0,0,m - 1,segmentTree);
            }
            ans += leftCount + rightCount;
            int pos = lower_bound(values.begin(),values.end(),Q) - values.begin();
            updateSegmentTree(pos,0,0,m - 1,segmentTree);
        }

        return ans;
    }
};