package main

import "fmt"

func search(left, right, target int, arr []int, isLeftSearch bool) int {
	res := -1
	for left <= right {
		mid := left + (right-left)/2

		if arr[mid] == target {
			res = mid
			if isLeftSearch {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return res
}

func numberOfOccurance(arr []int, target int) int {
	n := len(arr)
	left := 0
	right := n - 1

	leftIndex := search(left, right, target, arr, true)
	rightIndex := search(left, right, target, arr, false)

	if leftIndex == -1 {
		return 0
	} else {
		return rightIndex - leftIndex + 1
	}
}

func main() {
	arr := []int{1, 1, 2, 2, 2, 2, 3}
	target := 2

	num := numberOfOccurance(arr, target)
	fmt.Printf("%d ", num)
}
