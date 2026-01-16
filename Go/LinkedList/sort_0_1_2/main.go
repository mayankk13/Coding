package main

import "fmt"

type Node struct {
	Val  int
	Next *Node
}

func newNode(data int) *Node {
	return &Node{Val: data, Next: nil}
}

func sort(head *Node) *Node {
	zero := 0
	one := 0
	two := 0
	curr := head

	for curr != nil {
		if curr.Val == 0 {
			zero++
		} else if curr.Val == 1 {
			one++
		} else if curr.Val == 2 {
			two++
		}
		curr = curr.Next
	}

	curr = head
	for curr != nil {
		if zero > 0 {
			curr.Val = 0
			zero--
		} else if one > 0 {
			curr.Val = 1
			one--
		} else if two > 0 {
			curr.Val = 2
			two--
		}

		curr = curr.Next
	}

	return head
}

func insertAtEnd(head *Node, data int) *Node {
	node := newNode(data)
	if head == nil {
		return node
	}

	curr := head
	for curr.Next != nil {
		curr = curr.Next
	}

	curr.Next = node
	return head
}

func printList(head *Node) {
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
	fmt.Println()
}

func main() {
	var head *Node = nil
	arr := []int{1, 2, 2, 1, 2, 0, 2, 2}

	for i := range len(arr) {
		head = insertAtEnd(head, arr[i])
	}

	printList(head)
	head = sort(head)
	printList(head)
}
