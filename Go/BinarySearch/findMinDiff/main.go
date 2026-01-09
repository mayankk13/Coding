package main

import "fmt"

func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func minDifferenceElement(arr []int, target int) int {
	n := len(arr)
	left := 0
	right := n - 1

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

	leftDiff := abs(arr[left] - target)
	rightDiff := abs(arr[right] - target)

	if leftDiff < rightDiff {
		return left
	} else {
		return right
	}
}

func main() {
	arr := []int{1, 3, 8, 10, 15}
	target := 14

	idx := minDifferenceElement(arr, target)
	fmt.Println("idx ", idx)
}
