package main

import (
	"fmt"
)

func solve(idx, sum int, curr, arr []int, res *[][]int) {
	if idx == len(arr) {
		if sum == 0 {
			temp := make([]int, len(curr))
			copy(temp, curr)
			*res = append(*res, temp)
		}
		return
	}

	// take
	curr = append(curr, arr[idx])
	solve(idx+1, sum-arr[idx], curr, arr, res)

	// not take
	curr = curr[:len(curr)-1]
	solve(idx+1, sum, curr, arr, res)
}

func subsequencesSumK(arr []int, target int) [][]int {
	// n := len(arr)
	// dp := make([][]int, n+1)
	// for i := range dp {
	// 	dp[i] = make([]int, target+1)
	// }
	res := [][]int{}

	curr := []int{}

	solve(0, target, curr, arr, &res)

	return res
}

func main() {
	arr := []int{17, 18, 6, 11, 2, 4}
	target := 6

	res := subsequencesSumK(arr, target)

	for i := range res {
		fmt.Println(res[i])
	}
}
