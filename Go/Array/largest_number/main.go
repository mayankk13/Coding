package main

import (
	"fmt"
	"math"
)

func largestNumber(arr []int) int {
	res := math.MinInt

	for _, val := range arr {
		res = max(res, val)
	}

	return res
}

func main() {
	arr := []int{1, 8, 7, 56, 90}
	res := largestNumber(arr)
	fmt.Println(res)
}
