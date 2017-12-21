import java.util.*;

class insertionSort {
	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(5);
		list.add(4);
		list.add(3);
		insertionSort(list);
		print(list);
	}

	private static <T extends Comparable> void insertionSort(List<T> list) {
		for (int i = 0; i < list.size(); i++) {
			for (int j = i; j > 0; j--) {
				if (list.get(j).compareTo(list.get(j - 1)) <= 0) {
					T temp = list.get(j);
					list.set(j, list.get(j - 1));
					list.set(j - 1, temp);
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

/*


Note: Must be compiled with -Xlint:unchecked option


*/