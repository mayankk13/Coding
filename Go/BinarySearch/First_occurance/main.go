package main

import "fmt"

func firstOccurance(arr []int, x int) int {
	res := -1
	n := len(arr)
	left := 0
	right := n - 1

	for left <= right {
		mid := left + (right-left)/2

		if arr[mid] == x {
			res = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return res
}

func main() {
	arr := []int{0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
	x := 1
	idx := firstOccurance(arr, x)

	fmt.Printf("%d ", idx)
}
