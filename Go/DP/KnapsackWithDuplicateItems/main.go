package main

import "fmt"

func solve(idx, W int, wt, val []int, dp [][]int) int {
	// Base case: only one type of item available (idx == 0)
	if idx == 0 {
		// we can take as many of item 0 as will fit in the remaining capacity
		if wt[0] <= W {
			return (W / wt[0]) * val[0]
		}

		return 0
	}

	if dp[idx][W] != -1 {
		return dp[idx][W]
	}

	notTake := solve(idx-1, W, wt, val, dp)
	take := 0
	if wt[idx] <= W {
		take = val[idx] + solve(idx, W-wt[idx], wt, val, dp)
	}

	dp[idx][W] = max(take, notTake)

	return dp[idx][W]
}

func knapsack(W int, wt, val []int) int {
	n := len(wt)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, W+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	return solve(n-1, W, wt, val, dp)
}

func main() {
	W := 8
	wt := []int{1, 3, 4, 5}
	val := []int{10, 40, 50, 70}

	res := knapsack(W, wt, val)
	fmt.Printf("%d ", res)
}
