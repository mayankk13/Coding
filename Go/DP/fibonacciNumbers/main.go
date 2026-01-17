package main

import "fmt"

func fibonacciNumbers(n int, dp []int) []int {
	dp[0] = 0
	dp[1] = 1

	for i := 2; i < n; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}

	return dp
}

func main() {
	var n int
	fmt.Scan(&n)
	dp := make([]int, n)

	res := fibonacciNumbers(n, dp)
	fmt.Println(res)
}
