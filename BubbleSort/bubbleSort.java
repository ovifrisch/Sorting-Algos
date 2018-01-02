import java.util.*;

class bubbleSort {

	public static void main(String args[]) {
		ArrayList<Integer> myArr = new ArrayList<Integer>();
		myArr.add(5);
		myArr.add(4);
		myArr.add(3);
		bubbleSort(myArr);
		print(myArr);
	}

	private static <T extends Comparable> void bubbleSort(List<T> list) {
		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list.size() - 1; j++) {
				if (list.get(j).compareTo(list.get(j + 1)) > 0) {
					T temp = list.get(j);
					list.set(j, list.get(j + 1));
					list.set(j + 1, temp);
				}
			}
		}
	}

	private static void print(List<?> list) {
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i) + " ");
		}
		System.out.println();
	}
}
