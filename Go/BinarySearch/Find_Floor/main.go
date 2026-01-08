package main

import "fmt"

func findFloor(arr []int, target int) int {
	n := len(arr)
	left := 0
	right := n - 1
	res := -1

	for left < right {
		mid := left + (right-left)/2

		if arr[mid] <= target {
			res = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return res
}

func main() {
	arr := []int{1, 2, 8, 10, 10, 12, 19}
	target := 5

	idx := findFloor(arr, target)
	fmt.Printf("%d ", idx)
}
