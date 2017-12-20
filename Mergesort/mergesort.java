import java.util.*;

class mergesort {
	public static void main(String args[]) {
		int x;
		ArrayList<Integer> myArr = new ArrayList<Integer>();
		myArr.add(5);
		myArr.add(4);
		myArr.add(3);
		mergeSort(myArr, 0, myArr.size() - 1);
		printList(myArr);
	}

	private static void mergeSort(List<?> list, int start, int end) {
		if (start >= end) return;
		int middle = (start + end) / 2;
		mergeSort(list, start, middle);
		mergeSort(list, middle + 1, end);
		merge(list, start, middle, middle + 1, end);

	}

	private static <T> void merge(List<T> list, int leftStart, int leftEnd, int rightStart, int rightEnd) {
		int length = rightEnd - leftStart + 1;
		int left = leftStart;
		int right = rightStart;
		ArrayList<T> temp = new ArrayList<T>();

		for (int i = 0; i < length; i++) {
			if (right > rightEnd) {
				temp.add(list.get(left++));
			}
			else if (left > leftEnd) {
				temp.add(list.get(right++));
			}
			else if ((Integer)list.get(left) <= (Integer)list.get(right)) {
				temp.add(list.get(left++));
			}
			else {
				temp.add(list.get(right++));
			}
		}

		for (int i = 0; i < length; i++) {
			list.set(leftStart++, temp.get(i));
		}
	}

	private static void printList(List<?> list) {
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i) + " ");
		}
		System.out.println();
	}

}
