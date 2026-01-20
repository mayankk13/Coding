package main

import "fmt"

func isSubsetSum(idx, sum int, arr []int, dp [][]int) bool {
	if sum == 0 {
		return true
	}

	if idx == 0 {
		if arr[0] == sum {
			return true
		}
		return false
	}

	if dp[idx][sum] != -1 {
		return dp[idx][sum] == 1
	}

	notTake := isSubsetSum(idx-1, sum, arr, dp)
	take := false
	if arr[idx] <= sum {
		take = isSubsetSum(idx-1, sum-arr[idx], arr, dp)
	}

	dp[idx][sum] = 0
	if take || notTake {
		dp[idx][sum] = 1
	}

	return dp[idx][sum] == 1
}

func main() {
	arr := []int{3, 34, 4, 12, 5, 2}
	var sum int
	fmt.Scan(&sum)
	n := len(arr)

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, sum+1)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	res := isSubsetSum(n-1, sum, arr, dp)
	fmt.Println(res)
}
