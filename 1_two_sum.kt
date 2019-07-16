class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = mutableMapOf<Int, Int>()
        for ((index, value) in nums.withIndex()) {
            val complement = target - value
            map[complement]?.let {
                return intArrayOf(it, index)
            }
            map[value] = index
        }
        return intArrayOf()
    }
}
