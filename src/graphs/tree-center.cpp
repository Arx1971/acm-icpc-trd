#define MAX_SIZE 50000

vector<int> L[MAX_SIZE];

bool visited[MAX_SIZE];
int V, prev[MAX_SIZE], Q[MAX_SIZE], tail;

int most_distant(int s) {
  fill(visited, visited + V, false);
  visited[s] = true;
  Q[0] = s;
  tail = 1;
  prev[s] = -1;

  int ans = s;

  for (int k = 0; k < V; ++k) {
    int aux = Q[k];
    ans = aux;

    for (int i = L[aux].size() - 1; i >= 0; --i) {
      int v = L[aux][i];
      if (visited[v]) continue;
      visited[v] = true;
      Q[tail] = v;
      ++tail;
      prev[v] = aux;
    }
  }

  return ans;
}

void get_center() {
  int s = most_distant(0);
  int e = most_distant(s);
  int v = e, L = 0;

  while (v != -1) {
    Q[L] = v;
    v = prev[v];
    ++L;
  }

  if (L & 1)
    printf("%d\n", 1 + Q[L / 2]);
  else
    printf("%d %d\n", 1 + min(Q[L / 2 - 1], Q[L / 2]),
           1 + max(Q[L / 2 - 1], Q[L / 2]));
}
