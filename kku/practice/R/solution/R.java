import java.util.Scanner;

public class R {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		while (scanner.hasNext()) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();
			if(n == -1 && m == -1) {
				break;
			}
			if(n < m) {
				System.out.println("CP");
			}
			if(n > m) {
				System.out.println("COE");
			}
			if(n == m) {
				System.out.println("DRAW");
			}
		}
		scanner.close();
	}
}
