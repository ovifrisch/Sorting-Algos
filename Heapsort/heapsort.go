package main
import "fmt"

func percolateDown(list []int, hole int, currentSize int) {
	var child int
	var temp int = list[hole]

	for ; hole * 2 <= currentSize - 1; hole = child {
		child = hole * 2
		if (child != currentSize - 1 && list[child + 1] > list[child]) {
			child++
		}

		if (list[child] > temp) {
			list[hole] = list[child]
		} else {
			break
		}
	}
	list[hole] = temp
}

func buildHeap(list []int) {
	for i := (len(list) - 1) / 2; i > 0; i-- {
		percolateDown(list, i, len(list))
	}
}

func heapsort(list []int) {
	buildHeap(list)
	var heapSize int = len(list)
	for i := 1; i < len(list); i++ {
		last := list[heapSize - 1]
		list[heapSize - 1] = list[1]
		list[1] = last
		heapSize--
		percolateDown(list, 1, heapSize)
	}
}

func print(list []int) {
	for i := 1; i < len(list); i++ {
		fmt.Print(list[i], " ")
	}
	fmt.Println()
}

func main() {
	list := []int{0, 1, 2, 3, 67, 32, 2, 5, 8, 4, 5, 6, 7}
	heapsort(list)
	print(list)
}

