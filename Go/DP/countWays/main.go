package main

import "fmt"

func solve(n int, dp []int) int {
	if n == 0 {
		return 1
	}

	if n < 0 {
		return 0
	}

	if dp[n] != -1 {
		return dp[n]
	}

	dp[n] = solve(n-1, dp) + solve(n-2, dp) + solve(n-3, dp)
	return dp[n]
}

func main() {
	var n int
	fmt.Scan(&n)

	dp := make([]int, n+1)
	for i := range len(dp) {
		dp[i] = -1
	}

	res := solve(n, dp)
	fmt.Println(res)
}
