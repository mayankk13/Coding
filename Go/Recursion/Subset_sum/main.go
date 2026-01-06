package main

import (
	"fmt"
	"sort"
)

func solve(idx, sum int, arr []int, res *[]int) {
	if idx == len(arr) {
		*res = append(*res, sum)
		return
	}

	// take
	solve(idx+1, sum+arr[idx], arr, res)

	// notTake
	solve(idx+1, sum, arr, res)
}

func subsetSum(arr []int) []int {
	res := []int{}

	solve(0, 0, arr, &res)

	return res
}

func main() {
	arr := []int{1, 2, 1}

	res := subsetSum(arr)
	sort.Ints(res)

	for i := 0; i < len(res); i++ {
		fmt.Printf("%d ", res[i])
	}
}
