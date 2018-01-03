package main
import "fmt"

func merge (list []int, leftStart int, leftEnd int, rightStart int, rightEnd int) {
	length := rightEnd - leftStart + 1
	temp := make([]int, length)
	left := leftStart
	right := rightStart

	for i := 0; i < length; i++ {
		if (left > leftEnd) {
			temp[i] = list[right]
			right++
		} else if (right > rightEnd) {
			temp[i] = list[left]
			left++
		} else if (list[left] <= list[right]) {
			temp[i] = list[left]
			left++
		} else {
			temp[i] = list[right]
			right++
		}
	}

	for i := 0; i < length; i++ {
		list[leftStart] = temp[i]
		leftStart++
	}
}

func mergesort(list []int, start int, end int) {
	if (end - start < 1) {
		return
	}
	middle := (start + end) / 2

	mergesort(list, start, middle)
	mergesort(list, middle + 1, end)
	merge(list, start, middle, middle + 1, end)
}

func print(list []int) {
	for i := 0; i < len(list); i++ {
		fmt.Print(list[i], " ")
	}
	fmt.Println()
}

func main() {
	list := []int{3, 4, 5, 1, 2, 45, 3, 56}
	mergesort(list, 0, len(list) - 1)
	print(list)
}

