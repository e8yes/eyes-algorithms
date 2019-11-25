class Solution {
    fun transpose(A: Array<IntArray>): Array<IntArray> {
        val R = A.size
        val C = A[0].size
        val res = Array<IntArray>(C) {IntArray(R) {0}}
        for (r in 0 until R) {
            for (c in 0 until C) {
                res[c][r] = A[r][c]
            }
        }
        return res
    }
}

