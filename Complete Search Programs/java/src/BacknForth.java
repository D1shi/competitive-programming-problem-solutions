/*=
	MADE BY DISHI

	code to put in main:
		BacknForth bf = new BacknForth();
		bf.getPossible(0, 1000, bf.a, 1000, bf.b);
		bf.io.println(bf.possible.size());
		bf.io.close();
=*/

import java.util.*;

public class BacknForth {
	List<Integer> a, b;
	Set<Integer> possible;

	IOHandler io;

	public BacknForth() throws Exception {
		/*=
      REASONING:
      todo
    =*/

		io = new IOHandler();
		a = new ArrayList<>();
		b = new ArrayList<>();
		possible = new HashSet<>();

		for (int i = 0; i < 10; i++) {
			a.add(io.nextInt());
		}

		for (int i = 0; i < 10; i++) {
			b.add(io.nextInt());
		}
	}

	public void getPossible(int day, int a, List<Integer> aB, int b, List<Integer> bB) {
		if (day == 4) {
			possible.add(a);
			return;
		}

		for (int i = 0; i < aB.size(); i++) {
			int t = aB.get(i);

			List<Integer> newA = new ArrayList<>(aB);
			newA.remove(i);
			List<Integer> newB = new ArrayList<>(bB);
			newB.add(t);

			getPossible(day + 1, b + t, newB, a - t, newA);
		}
	}
}