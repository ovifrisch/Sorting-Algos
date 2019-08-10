var js_test = require('./../Test/JavascriptTest')


function mergesort(nums) {

	const merge = (xs, ys) => {
		if (xs.length == 0) {
			return ys
		} else if (ys.length == 0) {
			return xs
		}
		else {
			if (xs[0] < ys[0]) {
				return [xs[0]].concat(merge(xs.slice(1, xs.length), ys))
			} else {
				return [ys[0]].concat(merge(xs, ys.slice(1, ys.length)))
			}
		}
	}

	if (nums.length < 2) {
		return nums
	}

	let mid = parseInt(nums.length / 2)
	return merge(mergesort(nums.slice(0, mid)), mergesort(nums.slice(mid, nums.length)))
}


// test
console.log(js_test.test(mergesort))
