package main

import "fmt"

type Node struct {
	Val  int
	Next *Node
}

func newNode(data int) *Node {
	return &Node{Val: data, Next: nil}
}

func printList(head *Node) {
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
	fmt.Println()
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

func reverse(head *Node) *Node {
	curr := head
	var prev *Node = nil
	var next *Node = nil

	for curr != nil {
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}

	return prev
}

func addOne(head *Node) *Node {
	newHead := reverse(head)
	dummy := newNode(0)
	dummy.Next = newHead
	carry := 1

	for newHead != nil {
		sum := newHead.Val + carry
		newHead.Val = sum % 10
		carry = sum / 10

		if carry == 0 {
			break
		}

		if newHead.Next == nil && carry > 0 {
			node := newNode(carry)
			newHead.Next = node
			carry = 0
			break
		}

		newHead = newHead.Next
	}

	head = reverse(dummy.Next)
	return head
}

func main() {
	var head *Node = nil
	arr := []int{9, 9, 9}
	for i := 0; i < len(arr); i++ {
		head = insertAtEnd(head, arr[i])
	}

	printList(head)
	head = addOne(head)
	printList(head)
}
