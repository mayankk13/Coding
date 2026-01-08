package main

import "fmt"

func findTarget(arr []int, target int) int {
	n := len(arr)
	left := 0
	right := n - 1

	for left <= right {
		mid := left + (right-left)/2

		// check mid
		if arr[mid] == target {
			return mid
		}

		// check left
		if left < mid && arr[mid-1] == target {
			return mid - 1
		}

		// check right
		if mid < right && arr[mid+1] == target {
			return mid + 1
		}

		if arr[mid] < target {
			left = mid + 2
		} else {
			right = mid - 2
		}
	}

	return -1
}

func main() {
	arr := []int{10, 3, 40, 20, 50, 80, 70}
	target := 40

	idx := findTarget(arr, target)
	fmt.Printf("%d ", idx)
}
