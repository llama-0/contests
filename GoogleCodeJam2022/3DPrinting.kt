private fun readInt(): Int = readln().toInt()

private fun readInts(): IntArray =
    readln().split(" ").map { it.toInt() }.toIntArray()

private const val L = 1000000L

private fun solve(input: Map<Int, Int>): IntArray? {
    var sum = 0L

    for (i in 0..3) {
        sum += input[i]!!
    }
    return when {
        sum < L -> null
        sum == L -> input.values.toIntArray()
        else -> lessenSum(sum, input)
    }
}

private fun lessenSum(sum: Long, input: Map<Int, Int>): IntArray {
    val tmp: MutableMap<Int, Int> = input.toMutableMap()
    var s: Long = sum
    while (s != L) {
        for (i in 0..3) {
            while (tmp[i] != 0 && s != L) {
                tmp[i] = tmp[i]!! - 1
                s--
            }
        }
    }
    return tmp.values.toIntArray()
}

private fun main() {
    val t = readInt()
    val input = mutableMapOf<Int, Int>()
    for (i in 1..t) {
        for (j in 0..2) {
            val line = readInts()
            if (j == 0) {
                for (k in 0..3) {
                    input[k] = line[k]
                }
            } else {
                for (k in 0..3) {
                    if (input[k]!! > line[k]) {
                        input[k] = line[k]
                    }
                }
            }
        }
        val res = solve(input)
        if (res != null) {
            println("Case #$i: ${res.joinToString(" ")}")
        } else {
            println("Case #$i: IMPOSSIBLE")
        }
    }
}