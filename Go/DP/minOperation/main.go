package main

import "fmt"

func solve(n int, dp []int) int {
	// base case
	if n == 0 {
		return 0
	}

	// already computed, return it
	if dp[n] != -1 {
		return dp[n]
	}

	// Option 1: Last operation was +1
	ans := solve(n-1, dp) + 1

	// Option 2: Last operation was *2 (only if n is even)
	if n%2 == 0 {
		ans = min(ans, solve(n/2, dp)+1)
	}
	dp[n] = ans

	return dp[n]
}

func minOperation(n int) int {
	dp := make([]int, n+1)
	for i := range len(dp) {
		dp[i] = -1
	}

	return solve(n, dp)
}

func main() {
	var n int
	fmt.Scan(&n)

	res := minOperation(n)
	fmt.Println(res)
}
