package main

import "fmt"

func findSum(n int) int {
	if n == 0 {
		return 0
	}

	return n + findSum(n-1)
}

func main() {
	var n int
	fmt.Scan(&n)

	res := findSum(n)
	fmt.Printf("%d ", res)
}
