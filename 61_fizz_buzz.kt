class Solution {
    fun fizzBuzz(n: Int): List<String> {
        return (1..n).map { it -> 
                when {
                    (it % 3 == 0 && it % 5 == 0) -> "FizzBuzz"
                    it % 3 == 0 -> "Fizz"
                    it % 5 == 0 -> "Buzz"
                    else -> it.toString()
                }
        }
    }
}