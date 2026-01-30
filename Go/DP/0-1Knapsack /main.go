package main

import "fmt"

func solve(idx, W int, wt, val []int, dp [][]int) int {
	if idx == 0 {
		if wt[0] <= W {
			return val[0]
		}
		return 0
	}

	if dp[idx][W] != -1 {
		return dp[idx][W]
	}

	notTake := solve(idx-1, W, wt, val, dp)
	take := 0
	if wt[idx] <= W {
		take = val[idx] + solve(idx-1, W-wt[idx], wt, val, dp)
	}

	dp[idx][W] = max(take, notTake)
	return dp[idx][W]
}

func knapsack(W int, val, wt []int) int {
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
	W := 4
	val := []int{1, 2, 3}
	wt := []int{4, 5, 1}

	res := knapsack(W, val, wt)
	fmt.Println(res)
}
