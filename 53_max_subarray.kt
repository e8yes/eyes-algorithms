class Solution {
    fun maxSubArray(nums: IntArray): Int {
        var curSum = nums[0] ?: return 0
        var maxSum = curSum
        for (i in 1..nums.size - 1) {
            curSum = maxOf(nums[i], curSum + nums[i])
            maxSum = maxOf(maxSum, curSum)
        }
        return maxSum
    }
}