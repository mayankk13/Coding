package main

import "fmt"

func solve(idx, N int, prices []int, dp [][]int) int {
	// base case: onle length (idx + 1) = 1 available
	// if idx == 0, we only have rod length 1 available
	// we can cut the rod into all 1-length	pieces
	// For rod length = 1:
	// 		number of pieces = N / 1 = N
	// 		revenue = N * pieces[0]
	if idx == 0 {
		return N * prices[0]
	}

	if dp[idx][N] != -1 {
		return dp[idx][N]
	}

	notTake := solve(idx-1, N, prices, dp)
	take := 0
	rodLen := idx + 1
	if rodLen <= N {
		take = prices[idx] + solve(idx-1, N-rodLen, prices, dp)
	}

	dp[idx][N] = max(take, notTake)

	return dp[idx][N]
}

func cutRod(prices []int) int {
	n := len(prices)
	// price has n elements
	// idx ranges from 0 → n-1
	dp := make([][]int, n)
	for i := range dp {
		// N is the remaining rod length.
		// 0 → n   (total n+1 values)
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	return solve(n-1, n, prices, dp)
}

func main() {
	prices := []int{1, 5, 8, 9, 10, 17, 17, 20}

	res := cutRod(prices)
	fmt.Println(res)
}
