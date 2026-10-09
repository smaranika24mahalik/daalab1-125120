#include <stdio.h>

#define MAX 20

int visited[1 << MAX];
int parent[1 << MAX];
int moveBit[1 << MAX];
int queue[1 << MAX];

int main() {
    int n, i, front = 0, rear = 0;
    int start, goal, states;

    printf("Enter number of switches (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
        return 0;

    states = 1 << n;
    start = states - 1;
    goal = 0;

    for (i = 0; i < states; i++)
        parent[i] = -1;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int s = queue[front++];

        if (s == goal)
            break;

        for (i = 0; i < n; i++) {
            int legal;

            if (i == n - 1)
                legal = 1;
            else {
                int mask = (1 << (n - i - 1)) - 1;
                legal = ((s & mask) == (1 << (n - i - 2)));
            }

            if (legal) {
                int next = s ^ (1 << i);

                if (!visited[next]) {
                    visited[next] = 1;
                    parent[next] = s;
                    moveBit[next] = i;
                    queue[rear++] = next;
                }
            }
        }
    }

    if (!visited[goal]) {
        printf("Solution not found\n");
        return 0;
    }

    int path[1 << MAX], len = 0, cur = goal;

    while (cur != start) {
        path[len++] = cur;
        cur = parent[cur];
    }

    printf("Minimum moves = %d\n", len);

    for (i = len - 1; i >= 0; i--)
        printf("Toggle switch %d\n",
               n - moveBit[path[i]]);

    return 0;
}