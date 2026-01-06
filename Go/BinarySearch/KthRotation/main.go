package main

import "fmt"

func findKthRotation(arr []int) int {
	n := len(arr)
	left := 0
	right := n - 1
	// res := -1

	for left <= right {
		mid := left + (right-left)/2

		if arr[mid] <= arr[right] {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return left
}

func main() {
	arr := []int{2, 3, 4, 5, 1}

	idx := findKthRotation(arr)
	fmt.Printf("%d ", idx)
}
