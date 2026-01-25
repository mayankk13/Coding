package main

import (
	"fmt"
	"math"
)

func largestUniqueNumber(arr []int) int {
	n := len(arr)
	unique := -1
	mp := make(map[int]int)
	maxx := math.MinInt

	for i := 0; i < n; i++ {
		mp[arr[i]]++
	}

	for i := 0; i < len(arr); i++ {
		if mp[arr[i]] == 1 {
			if arr[i] > maxx {
				maxx = arr[i]
				unique = maxx
			}
		}
	}

	return unique
}

func main() {
	// arr := []int{5, 7, 3, 9, 4, 9, 8, 3, 1} // OP -> 8
	arr := []int{8, 8, 9, 9} // OP -> -1

	res := largestUniqueNumber(arr)
	fmt.Println(res)
}
