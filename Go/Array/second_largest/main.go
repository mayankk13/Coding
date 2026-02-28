package main

import (
	"fmt"
	"math"
)

func secondLargest(arr []int) int {
	largest := math.MinInt
	res := -1

	for _, val := range arr {
		largest = max(largest, val)
	}

	for _, val := range arr {
		if val > res && val != largest {
			res = val
		}
	}

	return res
}

func main() {
	arr := []int{12, 35, 1, 10, 34, 1}
	res := secondLargest(arr)

	fmt.Println(res)
}
