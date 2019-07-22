class Solution {
    fun reverseString(s: CharArray): Unit {
        var i = 0
        var j = s.size - 1
        while (i < j) {
            var temp = s[i]
            s[i] = s[j]
            s[j] = temp
            i += 1
            j -= 1
        }
    }
}
