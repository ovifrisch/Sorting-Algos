var js_test = require('./../Test/JavascriptTest')



function quicksort(nums) {
	if (nums.length < 2) {
		return nums
	}

	let pivot = nums[0]
	let smaller = []
	let bigger = []
	for (let val of nums.slice(1, nums.length)) {
		if (val < pivot) {
			smaller.push(val)
		} else {
			bigger.push(val)
		}
	}

	return quicksort(smaller).concat([pivot]).concat(quicksort(bigger))
}

// test
console.log(js_test.test(quicksort))