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

func solve(idx, sum int, arr []int, dp [][]int) bool {
	if sum == 0 {
		return true
	}

	if idx == 0 {
		return arr[idx] == sum
	}

	if dp[idx][sum] != -1 {
		return dp[idx][sum] == 1
	}

	notTake := solve(idx-1, sum, arr, dp)
	take := false
	if arr[idx] <= sum {
		take = solve(idx-1, sum-arr[idx], arr, dp)
	}

	dp[idx][sum] = 0
	if take || notTake {
		dp[idx][sum] = 1
	}

	return dp[idx][sum] == 1
}

func main() {
	arr := []int{1, 4}
	n := len(arr)
	totalSum := 0

	for _, val := range arr {
		totalSum += val
	}

	// we will check till totalSum / 2, because difference is minimized there
	target := totalSum / 2

	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, target+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	// check all possibility from 0 to target
	best := math.MaxInt

	for sum := 0; sum <= target; sum++ {
		if solve(n-1, sum, arr, dp) {
			s1 := sum
			s2 := totalSum - sum
			best = min(best, abs(s1-s2))
		}
	}

	fmt.Println(best)
}
