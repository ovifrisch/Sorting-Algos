var js_test = require('./../Test/JavascriptTest')

function bubble_sort(nums) {
	for (var i = 0; i < nums.length; i++) {
		for (var j = i+1; j < nums.length; j++) {
			if (nums[j] < nums[i]) {
				var temp = nums[i]
				nums[i] = nums[j]
				nums[j] = temp
			}
		}
	}
	return nums
}

console.log(js_test.test(bubble_sort))