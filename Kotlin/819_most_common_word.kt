class Solution {
    fun mostCommonWord(paragraph: String, banned: Array<String>): String? {
        val words = paragraph.replace(Regex("\\pP"), " ").toLowerCase().split(Regex(" "))
        val bannedWords = banned.toList().map(String::toLowerCase).toSet()
        val word2CountMap = hashMapOf<String, Int>()
        for (word in words) {
            if (word.isNotEmpty() && !bannedWords.contains(word)) {
                word2CountMap[word] = word2CountMap.getOrDefault(word, 0) + 1
            }
        }
        return word2CountMap.maxBy { it.value }?.key
    }
}
