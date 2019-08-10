
function gen_nums(n) {
	var nums = []
	for (var i = 0; i < n; i++) {
		nums.push(Math.floor(Math.random() * 100))
	}
	return nums
}

exports.test = function(sorter) {
	var nums = sorter(gen_nums(20))
	for (var i = 1; i < nums.length; i ++) {
		if (nums[i] < nums[i-1]) {
			return false;
		}
	}
	return true;
}