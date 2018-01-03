package main
import "fmt"

func quicksort(list []int, left int, right int) {
	start := left

	if (right <= left) {
		return
	}

	pivot := list[left]
	newList := make([]int, right - left + 1)
	j := 0
	for i := left + 1; i <= right; i++ {
		if (list[i] <= pivot) {
			newList[j] = list[i]
			j++
		}
	}

	var posPivot int = left + j
	newList[j] = pivot
	j++

	for i := left + 1; i <= right; i++ {
		if (list[i] > pivot) {
			newList[j] = list[i]
			j++
		}
	}

	for i := 0; i < len(newList); i++ {
		list[start] = newList[i]
		start++
	}
	
	quicksort(list, left, posPivot - 1)
	quicksort(list, posPivot + 1, right)

}

func print(list []int) {
	for i := 0; i < len(list); i++ {
		fmt.Print(list[i], " ")
	}
	fmt.Println()
}

func main() {
	list := []int{3, 4, 5, 1, 2, 45, 3, 56, 789, 23, 45, 12}
	quicksort(list, 0, len(list) - 1)
	print(list)
}
