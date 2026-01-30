package main

import "fmt"

func bfsOfGraph(V int, adj [][]int) []int {
	result := []int{}
	queue := []int{}
	visited := make([]bool, V)

	// Start BFS from node 0
	queue = append(queue, 0)
	// visited[0] = true

	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		// if this node is not visited yet
		if !visited[node] {
			visited[node] = true
			result = append(result, node)
		}

		// visit neigbours
		for _, neigbor := range adj[node] {
			if !visited[neigbor] {
				queue = append(queue, neigbor)
			}
		}
	}

	return result
}

func main() {
	var V int
	fmt.Scan(&V)

	adj := make([][]int, V)

	// adding edges
	adj[0] = []int{2, 3, 1}
	adj[1] = []int{0}
	adj[2] = []int{0, 4}
	adj[3] = []int{0}
	adj[4] = []int{2}

	bfs := bfsOfGraph(V, adj)

	for _, val := range bfs {
		fmt.Printf("%d ", val)
	}
}
