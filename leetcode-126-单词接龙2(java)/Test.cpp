�����������ʣ�beginWord �� endWord����һ���ֵ� wordList���ҳ����д� beginWord �� endWord �����ת�����С�ת������ѭ���¹���

ÿ��ת��ֻ�ܸı�һ����ĸ��
ת����õ��ĵ��ʱ������ֵ��еĵ��ʡ�
˵�� :

���������������ת�����У�����һ�����б�
���е��ʾ�����ͬ�ĳ��ȡ�
���е���ֻ��Сд��ĸ��ɡ�
�ֵ��в������ظ��ĵ��ʡ�
����Լ��� beginWord �� endWord �Ƿǿյģ��Ҷ��߲���ͬ��

ʾ�� 1:
���� :
	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot", "dot", "dog", "lot", "log", "cog"]

��� :
   [
	   ["hit", "hot", "dot", "dog", "cog"],
	   ["hit", "hot", "lot", "log", "cog"]
   ]

   ʾ�� 2 :
   ���� :
	  beginWord = "hit"
	  endWord = "cog"
	  wordList = ["hot", "dot", "dog", "lot", "log"]

  ��� : []

   ���� : endWord "cog" �����ֵ��У����Բ����ڷ���Ҫ���ת�����С�

//����˼·��
//1.�ӿ�ʼ�ڵ�start�ҷ��������Ľڵ㡣���Ҽ�¼��set�С���Щ�ڵ��ǳ� length = 2�����Ҽ�¼��������ڵ��·��(path), ���ҽ��ýڵ����map�С�

//2.������һ����ȡ����set, �ٴα������������Ľڵ㣬���Ҽ�¼��set�С���Щ�ڵ��ǳ� length = 3�����Ҽ�¼��������ڵ��·��(path), ���ҽ��ýڵ����map�С�
//�������ơ������setΪ�գ���ֹͣ��Ȼ���map�л�ȡend�ڵ㣬��ӡpath����

class Solution {
			  private static final int INF = 1 << 20;
			  private Map<String, Integer> wordId; // ���ʵ�id��ӳ��
			  private ArrayList<String> idWord; // id�����ʵ�ӳ��
			  private ArrayList<Integer>[] edges; // ͼ�ı�

			  public Solution() {
				  wordId = new HashMap<>();
				  idWord = new ArrayList<>();
			  }

			  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
				  int id = 0;
				  // ��wordList���е��ʼ���wordId�� ��ͬ��ֻ����һ�� // ��Ϊÿһ�����ʷ���һ��id
				  for (String word : wordList) {
					  if (!wordId.containsKey(word)) {
						  wordId.put(word, id++);
						  idWord.add(word);
					  }
				  }
				  // ��endWord����wordList�� ���޽�
				  if (!wordId.containsKey(endWord)) {
					  return new ArrayList<>();
				  }
				  // ��beginWordҲ����wordId��
				  if (!wordId.containsKey(beginWord)) {
					  wordId.put(beginWord, id++);
					  idWord.add(beginWord);
				  }

				  // ��ʼ������õ�����
				  edges = new ArrayList[idWord.size()];
				  for (int i = 0; i < idWord.size(); i++) {
					  edges[i] = new ArrayList<>();
				  }
				  // ��ӱ�
				  for (int i = 0; i < idWord.size(); i++) {
					  for (int j = i + 1; j < idWord.size(); j++) {
						  // �����߿���ͨ��ת���õ� �������Ǽ佨һ�������
						  if (transformCheck(idWord.get(i), idWord.get(j))) {
							  edges[i].add(j);
							  edges[j].add(i);
						  }
					  }
				  }

				  int dest = wordId.get(endWord); // Ŀ��ID
				  List<List<String>> res = new ArrayList<>(); // ���
				  int[] cost = new int[id]; // ��ÿ����Ĵ���
				  for (int i = 0; i < id; i++) {
					  cost[i] = INF; // ÿ����Ĵ��۳�ʼ��Ϊ�����
				  }

				  // ����������� ������cost��Ϊ0
				  Queue<ArrayList<Integer>> q = new LinkedList<>();
				  ArrayList<Integer> tmpBegin = new ArrayList<>();
				  tmpBegin.add(wordId.get(beginWord));
				  q.add(tmpBegin);
				  cost[wordId.get(beginWord)] = 0;

				  // ��ʼ�����������
				  while (!q.isEmpty()) {
					  ArrayList<Integer> now = q.poll();
					  int last = now.get(now.size() - 1); // ������ʵĵ�
					  if (last == dest) { // ���õ�Ϊ�յ���������res��
						  ArrayList<String> tmp = new ArrayList<>();
						  for (int index : now) {
							  tmp.add(idWord.get(index)); // ת��Ϊ��Ӧ��word
						  }
						  res.add(tmp);
					  }
					  else { // �õ㲻Ϊ�յ� ��������
						  for (int i = 0; i < edges[last].size(); i++) {
							  int to = edges[last].get(i);
							  // �˴�<=Ŀ�����ڰѴ�����ͬ�Ĳ�ͬ·��ȫ����������
							  if (cost[last] + 1 <= cost[to]) {
								  cost[to] = cost[last] + 1;
								  // ��to����·����
								  ArrayList<Integer> tmp = new ArrayList<>(now); tmp.add(to);
								  q.add(tmp); // �����·���������
							  }
						  }
					  }
				  }
				  return res;
			  }

			  // �����ַ����Ƿ����ͨ���ı�һ����ĸ�����
			  boolean transformCheck(String str1, String str2) {
				  int differences = 0;
				  for (int i = 0; i < str1.length() && differences < 2; i++) {
					  if (str1.charAt(i) != str2.charAt(i)) {
						  ++differences;
					  }
				  }
				  return differences == 1;
			  }
}
