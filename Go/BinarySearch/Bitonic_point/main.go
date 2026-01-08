package main

import "fmt"

func findMaximum(arr []int) int {
	n := len(arr)
	left := 0
	right := n - 1

	for left < right {
		mid := left + (right-left)/2

		if arr[mid] < arr[mid+1] {
			left = mid + 1
		} else {
			right = mid
		}
	}

	return arr[left]
}

func main() {
	arr := []int{1, 2, 4, 5, 7, 8, 3}

	num := findMaximum(arr)
	fmt.Printf("%d ", num)
}
