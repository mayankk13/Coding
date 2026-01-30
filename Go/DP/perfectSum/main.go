package main

import "fmt"

func solve(idx, sum int, arr []int, dp [][]int) int {
	if idx == 0 {
		// if sum == 0, we always have one valid subset: the empty subset
		// if nums[0] == 0, and sum == 0, we have two subsets: {}, {0}
		if sum == 0 {
			if arr[0] == 0 {
				return 2
			}
			return 1
		}
		// if nums[0] == sum, we can includeit as a valid subset
		if arr[0] == sum {
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

func main() {
	arr := []int{5, 2, 3, 10, 6, 8}
	n := len(arr)
	target := 10
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, target+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	res := solve(n-1, target, arr, dp)
	fmt.Println(res)
}
