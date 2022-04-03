private fun readInt(): Int = readln().toInt()

private fun readInts(): IntArray =
    readln().split(" ").map { it.toInt() }.toIntArray()

private fun solve(n: Int, s: IntArray): Int {
    s.sort()
    var tmp = 0
    var res = 0
    var startIndex = 0
    var i = 0
    while (i < n) {
        if (res < s[i]) {
            res++
        } else {
            if (tmp < res) {
                tmp = res
                startIndex++
                i = startIndex
                res = 0
                continue
            }
        }
        i++
    }
    return res
}

private fun main() {
    val t = readInt()
    for (i in 1..t) {
        val n = readInt()
        val s = readInts()
        val res = solve(n, s)
        println("Case #$i: $res")
    }
}