package main

import "fmt"

func solve(idx, last int, arr, dp [][]int) int {
	// base case:   if we are at day 0 (first day)
	if idx == 0 {
		maxx := 0
		// Choose the best task on day 0 that is NOT equal to 'last'
		for task := 0; task < 3; task++ {
			if task != last {
				maxx = max(maxx, arr[0][task])
			}
		}
		return maxx
	}

	if dp[idx][last] != -1 {
		return dp[idx][last]
	}

	maxx := 0
	// Try all 3 tasks for current day
	for task := 0; task < 3; task++ {
		// We cannot repeat the task performed on the previous day
		if task != last {
			// Points = today's task + best points from previous day
			point := arr[idx][task] + solve(idx-1, task, arr, dp)
			maxx = max(maxx, point)
		}
	}
	dp[idx][last] = maxx
	return dp[idx][last]
}

func main() {
	arr := [][]int{{1, 2, 5}, {3, 1, 1}, {3, 3, 3}} // -> 11
	n := len(arr)
	/*
			dp[n][4] because "last task" can be 0,1,2 or 3 (3 = none)
			For any day, yesterday’s task can be:
				•	0 → Running
			    •	1 → Fighting
		        •	2 → Learning
		        •	3 → No task (only for the very first call)
	*/
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 4)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}

	res := solve(n-1, 3, arr, dp)
	fmt.Println(res)
}
