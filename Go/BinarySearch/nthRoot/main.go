package main

import (
	"fmt"
	"math"
)

func nthRoot(n, m int) int {
	left := 0
	right := m

	for left <= right {
		mid := left + (right-left)/2

		num := int(math.Pow(float64(mid), float64(n)))
		if num == m {
			return mid
		} else if num < m {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return -1
}

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	num := nthRoot(n, m)
	fmt.Printf("%d ", num)
}
