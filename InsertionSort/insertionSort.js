var js_test = require('./../Test/JavascriptTest')

function insertion_sort(nums) {
	for (var i = 1; i < nums.length; i++) {
		if (nums[i] < nums[i-1]) {
			let j = i
			while (j > 0 && nums[j] < nums[j-1]) {
				let temp = nums[j]
				nums[j] = nums[j-1]
				nums[j-1] = temp
				j--;
			}
		}
	}
	return nums
}

// test
console.log(js_test.test(insertion_sort))