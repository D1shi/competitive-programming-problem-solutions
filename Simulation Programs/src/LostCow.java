import java.util.*;

public class LostCow {
	IOHandler io;
	int j, b;

	public LostCow() throws Exception {
		io = new IOHandler();
		j = io.nextInt();
		b = io.nextInt();
	}

	public static void main(String[] args) throws Exception {
		LostCow lc = new LostCow();
		lc.io.println(lc.run()); lc.io.close();
	}

	public int run() {
		if (j == b) return 0;

		List<Integer> zigzag = new ArrayList<>();
		int off = 1;

		while (true) {
			zigzag.add(j + off);
			off *= -2;
			if (j < b && j + off > b) break;
			if (j > b && j + off < b) break;
		}

		zigzag.add(j + off);
		int out = 1;

		for (int i = 0; i < zigzag.size() - 1; i++) {
			out += Math.abs(zigzag.get(i) - zigzag.get(i + 1));
		}

		out -= Math.abs(zigzag.get(zigzag.size() - 1) - b);
		return out;
	}
}