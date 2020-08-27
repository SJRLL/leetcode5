输入: 5

输出 :
   [
	   [1],
	   [1, 1],
	   [1, 2, 1],
	   [1, 3, 3, 1],
	   [1, 4, 6, 4, 1]
   ]


	public static List<List<Integer>> generate(int numRows) {
		List<List<Integer>> res = new ArrayList<>();
		if (numRows == 0) {
			return res;
		}
		List<Integer> temp = new ArrayList<>();
		for (int i = 0; i < numRows; i++) {
			List<Integer> ints = new ArrayList<>();
			// 内层计算行
			for (int j = 0; j < i + 1; j++) {
				if (j == 0 || j == i) {
					ints.add(1);
				}
				else {
					ints.add(temp.get(j - 1) + temp.get(j));
				}
			}
			res.add(ints);
			temp = res.get(i);
		}
		return res;
	}
