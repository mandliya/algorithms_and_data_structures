package jun20;

public class exitpoint {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] arr = { { 1, 0, 1, 0 }, { 0, 0, 0, 1 }, { 1, 0, 1, 0 } };
		int i = 0;
		int j = 0;
		int dir = 0;
		while (true) {
			dir = (dir + arr[i][j]) % 4;
			if (dir == 0) {
				j++;

				if (j > arr[0].length) {
					System.out.print(i + ", " + (j-1));
					break;
				}

			} else if (dir == 1) {
				i++;

				if (i == arr.length) {
					System.out.print((i-1) + ", " + j);
					break;
				}

			} else if (dir == 2) {
				j--;
				if (j == -1) {
					System.out.print(i + ", " + (j + 1));
					break;
				}
			} else if (dir == 3) {
				i--;
				if (i == -1) {
					System.out.print((i + 1) + ", " + j);
					break;
				}
			}

		}
	}
}