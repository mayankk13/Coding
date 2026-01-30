package main

import "fmt"

func solve(idx, sum int, arr []int, dp [][]int) int {
	if idx == 0 {
		if sum == 0 {
			if arr[0] == 0 {
				return 2
			}
			return 1
		}
		if arr[idx] == sum {
			return 1
		}
		return 0
	}

	if dp[idx][sum] != -1 {
		return dp[idx][sum]
	}

	notTake := solve(idx-1, sum, arr, dp)
	take := 0
	if arr[idx] <= sum {
		take = solve(idx-1, sum-arr[idx], arr, dp)
	}

	dp[idx][sum] = take + notTake
	return dp[idx][sum]
}

func countPartitionsWithDiff(arr []int, diff int) int {
	n := len(arr)
	total := 0
	for _, val := range arr {
		total += val
	}

	// s1 + s2 = total
	// s1 - s2 = diff
	// s1 = (total + diff) / 2
	target := (total + diff) / 2
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, target+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	return solve(n-1, target, arr, dp)
}

func main() {
	arr := []int{1, 1, 1, 1}
	diff := 0

	res := countPartitionsWithDiff(arr, diff)
	fmt.Printf("%d ", res)
}
