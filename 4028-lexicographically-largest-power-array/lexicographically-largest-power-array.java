class Solution {
    public int[] largestPower(int[] nums) {
        int n = nums.length;

        int[] perm = new int[n];
        boolean[] used = new boolean[n];

        int mask = (1 << 15) - 1;
        int rem = n;
        int idx = 0;

        while (rem > 0) {
            boolean found = false;

            // Take all numbers containing all bits of mask
            for (int i = 0; i < n; i++) {
                if (!used[i] && (nums[i] & mask) == mask) {
                    used[i] = true;
                    perm[idx++] = nums[i];
                    rem--;
                    found = true;
                }
            }

            if (found) {
                continue;
            }

            // Find unused number having maximum (nums[i] & mask)
            int best = -1;
            int val = -1;

            for (int i = 0; i < n; i++) {
                if (!used[i] && (nums[i] & mask) > val) {
                    val = nums[i] & mask;
                    best = i;
                }
            }

            used[best] = true;
            perm[idx++] = nums[best];
            rem--;

            mask &= nums[best];
        }

        int[] ans = new int[15];

        mask = (1 << 15) - 1;

        for (int i = 0; i < n; i++) {
            mask &= perm[i];

            for (int b = 14; b >= 0; b--) {
                if ((mask & (1 << b)) != 0) {
                    ans[14 - b] = i + 1;
                }
            }
        }

        return ans;
    }
}