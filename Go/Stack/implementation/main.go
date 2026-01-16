package main

import "fmt"

type Stack struct {
	data []int
}

// PUSH - add element to the top of the stack
func (s *Stack) Push(val int) {
	s.data = append(s.data, val)
}

func (s *Stack) Pop() int {
	if len(s.data) == 0 {
		return -1
	}

	top := s.data[len(s.data)-1]
	s.data = s.data[:len(s.data)-1]

	return top
}

func (s *Stack) Peek() int {
	if len(s.data) == 0 {
		return -1
	}

	return s.data[len(s.data)-1]
}

func (s *Stack) IsEmpty() bool {
	return len(s.data) == 0
}

func (s *Stack) Size() int {
	return len(s.data)
}

func main() {
	stack := Stack{}
	stack.Push(10)
	stack.Push(20)
	stack.Push(30)

	fmt.Printf("%d ", stack.Size())
}
