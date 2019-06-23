def merge(nums1 : List[Int], nums2 : List[Int]) : List[Int] = {
	(nums1, nums2) match {
		case (Nil, nums2) => nums2
		case (nums1, Nil) => nums1
		case (x::xs, y::ys) => {
			if (x < y) x :: merge(xs, nums2)
			else y :: merge(nums1, ys)
		}
	}
}

def merge_sort(nums : List[Int]) : List[Int] = {
	if (nums.length <= 1) nums
	else {
		val s = nums.length / 2
		merge(merge_sort(nums.take(s)), merge_sort(nums.drop(s)))
	}
}



println(merge_sort(List(3, 6, 1, 9, 3, 6, 8, 2)))
