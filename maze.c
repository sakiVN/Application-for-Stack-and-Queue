#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int x, y, steps;
} Node;

int n, m, r, c;
int maze[MAX][MAX];
int visited[MAX][MAX];

// 4 directions
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

Node queue[MAX * MAX];
int front = 0, rear = 0;

void enqueue(int x, int y, int steps) {
    queue[rear++] = (Node){x, y, steps};
}

Node dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int isExit(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

int bfs(int startX, int startY) {
    enqueue(startX, startY, 0);
    visited[startX][startY] = 1;

    while (!isEmpty()) {
        Node current = dequeue();

        if (isExit(current.x, current.y)) {
            return current.steps;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                maze[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                enqueue(nx, ny, current.steps + 1);
            }
        }
    }

    return -1; // No escape
}

int main() {
    scanf("%d %d %d %d", &n, &m, &r, &c);
    r--; c--; // Return to 0

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maze[i][j]);

    if (maze[r][c] == 1) {
        printf("-1\n");
        return 0;
    }

    int result = bfs(r, c);
    if (result != -1) printf("%d\n", result + 1);
    else printf("%d\n", -1);

    return 0;
}
