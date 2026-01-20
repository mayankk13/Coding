package main

import (
	"fmt"
	"math"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func solve(idx int, arr, dp []int) int {
	if idx <= 0 {
		return 0
	}

	if dp[idx] != -1 {
		return dp[idx]
	}

	// TAKE 1 STEP
	// Frog jumps from (idx-1) to idx
	oneJump := solve(idx-1, arr, dp) + abs(arr[idx]-arr[idx-1])

	// Take 2 step
	// frog jump from (idx-2 to idx) -  (possible only if idx > 1)
	twoJump := math.MaxInt
	if idx > 1 {
		twoJump = solve(idx-2, arr, dp) + abs(arr[idx]-arr[idx-2])
	}

	dp[idx] = min(oneJump, twoJump)
	return dp[idx]
}

func main() {
	arr := []int{20, 30, 40, 20}
	n := len(arr)

	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = -1
	}

	res := solve(n-1, arr, dp)
	fmt.Println(res)
}
