private const val base = ".."
private const val line_1 = "-+"
private const val line_2 = ".|"

fun printCells(input: List<Int>) {
    val r = input[0]
    val c = input[1]
    for (i in 1..r * 2 + 1) {
        for (j in 1..c) {
            if (i in 1..2 && j == 1) {
                print(if (i == 1) "$base+" else "$base|")
            }
            if (i % 2 != 0) {
                if (j == 1 && i !in 1..2) {
                    print("+$line_1")
                } else if (j != 1) {
                    print(line_1)
                }
            } else {
                if (j == 1 && i !in 1..2) {
                    print("|$line_2")
                } else if (j != 1) {
                    print(line_2)
                }
            }
        }
        println()
    }
}

fun main() {
    val t: Int = readln().toInt()
    for (i in 1..t) {
        val input: List<Int> = readln()
            .split(" ")
            .map { it.toInt() }
        println("Case #$i:")
        printCells(input)
    }
}