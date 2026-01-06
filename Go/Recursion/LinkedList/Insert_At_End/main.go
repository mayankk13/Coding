package main

import "fmt"

type Node struct {
	Val  int
	Next *Node
}

func newNode(data int) *Node {
	return &Node{Val: data, Next: nil}
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
	curr := head
	for curr != nil {
		fmt.Printf("%d ", curr.Val)
		curr = curr.Next
	}
	fmt.Println()
}

func main() {
	var n int
	fmt.Scan(&n)

	var head *Node = nil

	for i := 1; i <= n; i++ {
		head = insertAtEnd(head, i)
	}

	printList(head)
}
