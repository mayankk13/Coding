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
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
	fmt.Println()
}

func rotateLeft(head *Node, k int) *Node {
	len := 1
	tail := head

	for tail.Next != nil {
		tail = tail.Next
		len++
	}

	tail.Next = head

	k = k % len
	if k == 0 {
		tail.Next = nil
		return head
	}

	for k > 0 {
		head = head.Next
		tail = tail.Next
		k--
	}
	tail.Next = nil

	return head
}

func main() {
	var head *Node = nil
	arr := []int{10, 20, 30, 40, 50}
	for i := 0; i < len(arr); i++ {
		head = insertAtEnd(head, arr[i])
	}

	k := 4

	printList(head)
	head = rotateLeft(head, k)
	printList(head)
}
