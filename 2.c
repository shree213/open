#include<stdio.h>
#include<stdbool.h>
#define INF 9999999
#define V 5
int G[V][V] = {
  {0, 10, 15, 0, 0},
  {4, 0, 45, 18, 32},
  {50, 34, 0, 51, 48},
  {0, 32, 23, 0, 33},
  {0, 36, 65, 34, 0}
};
int main() {
  int no_edge = 0;
  int selected[V];
  memset(selected, false, sizeof(selected));
  selected[0] = true;
  int x, y;
  printf("Edge : Weight\n");
  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;
    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }
  return 0;
}
