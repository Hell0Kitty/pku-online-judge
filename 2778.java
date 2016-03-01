
	  return 3;
       }
	return -1;
     }

   public void insert(char[] key) {
	int index;
	int root = 0;
	for (int i = 0; i < key.length; i++) {
          if (trie[root].end > 0)
	    break;
	  index = get(key[i]);
	  if (trie[root].son[index] == -1) {
            trie[root].son[index] = ++NUM;
	    trie[NUM] = new trieP();
	   }
	  root = trie[root].son[index];
        }
	trie[root].end++;
    }


   public void acBuild() {
      int head = 0;
      int tail = 0;
      int temp = 0, p = 0, i;
      int q[] = new int[SIZE];
      q[tail++] = 0;
      while (head < tail) {
	temp = q[head++];
	for (i = 0; i < N; i++) {
	   p = trie[temp].son[i];
	   if (p != -1) {
	     if (temp == 0)
		trie[p].fail = 0;
	     else {
		trie[p].fail = trie[trie[temp].fail].son[i];
		if (trie[trie[p].fail].end > 0)
		  trie[p].end++;
	     }
	     q[tail++] = trie[temp].son[i];
	   } else {
	     if (temp == 0)
		trie[temp].son[i] = 0;
	     else
		trie[temp].son[i] = trie[trie[temp].fail].son[i];
	    }
	 }
       }

   }

  }

class trieP {
	int N = 4;
	int fail;
	int son[];
	int end;

	public trieP() {
          end = 0;
	  fail = -1;
	  son = new int[N];
	  for (int i = 0; i < N; i++)
	    son[i] = -1;
	}
}
