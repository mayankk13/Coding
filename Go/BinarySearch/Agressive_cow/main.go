package main

import (
	"fmt"
	"sort"
)

func canPlaceCows(stalls []int, k, dist int) bool {
	count := 1           // place the firsr cow at first index
	lastPos := stalls[0] // store the postion of last palced cow

	for i := 1; i < len(stalls); i++ {
		// if current stall is at least dist away from the last placed cow
		if stalls[i]-lastPos >= dist {
			count++
			lastPos = stalls[i]
		}

		// if all cows are palced successfully
		if count == k {
			return true
		}
	}
	return false
}

func aggressiveCows(stalls []int, k int) int {
	n := len(stalls)
	// step 1: sort the stall positions
	sort.Slice(stalls, func(i, j int) bool {
		return stalls[i] < stalls[j]
	})

	// step 2: initislize
	left := 1                        // minimum possible distance
	right := stalls[n-1] - stalls[0] // max possible distance between cows

	res := 0

	// step 3: binary search
	for left <= right {
		mid := left + (right-left)/2

		// Check if it's possible to place all cows with at least 'mid' distance apart
		if canPlaceCows(stalls, k, mid) {
			res = mid
			left = mid + 1 // try finding larger min distance
		} else {
			right = mid - 1
		}
	}
	return res
}

func main() {
	arr := []int{1, 2, 4, 8, 9}
	k := 3

	res := aggressiveCows(arr, k)

	fmt.Printf("Result: %d", res)
}
