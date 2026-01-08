package main

import "fmt"

func search(left, right, target int, arr []int) int {
	for left <= right {
		mid := left + (right-left)/2

		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return -1
}

func findPosition(arr []int, target int) int {
	n := len(arr)
	left := 0
	right := 1

	// find upper bound for binary search
	for right < n && arr[right] < target {
		left = right
		right = right * 2
	}

	// cap high to nums.size() - 1
	right = min(right, n-1)

	idx := search(left, right, target, arr)

	return idx
}

func main() {
	arr := []int{1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 52, 55, 58, 61, 64, 67, 70, 73}
	target := 25

	idx := findPosition(arr, target)
	fmt.Printf("idx: %d", idx)
}
