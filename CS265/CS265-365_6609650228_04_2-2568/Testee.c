#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 6


char nodes[MAX_NODES] = {'S', 'A', 'B', 'C', 'D', 'F'};


int graph[MAX_NODES][MAX_NODES] = {
    {0, 2, 4, 0, 0, 0},
    {0, 0, 1, 5, 0, 0},
    {0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 2, 6},
    {0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0}
};


int heuristic[MAX_NODES] = {7, 6, 2, 1, 0, 0};


int getNodeIndex(char c) {
	int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i] == c) return i;
    }
    return -1; 
}

// DFS 
void dfs(int node, int goal, int visited[]) {
	int i;
    printf("%c -> ", nodes[node]);
    visited[node] = 1;
    if (node == goal) {
        printf("Goal reached!\n");
        return;
    }
    for ( i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, goal, visited);
        }
    }
}

// BFS
void bfs(int start, int goal) {
    int queue[MAX_NODES], front = 0, rear = 0, visited[MAX_NODES] = {0}, i;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%c -> ", nodes[node]);

        if (node == goal) {
            printf("Goal reached!\n");
            return;
        }

        for (i = 0; i < MAX_NODES; i++) {
            if (graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// UCS
typedef struct {
    int node, cost;
} PQNode;

typedef struct {
    PQNode heap[MAX_NODES];
    int size;
} PriorityQueue;

void push(PriorityQueue *pq, int node, int cost) {
    int i = pq->size++;
    while (i > 0 && pq->heap[(i - 1) / 2].cost > cost) {
        pq->heap[i] = pq->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->heap[i].node = node;
    pq->heap[i].cost = cost;
}

PQNode pop(PriorityQueue *pq) {
    PQNode top = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];

    int i = 0;
    while (2 * i + 1 < pq->size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = left;
        if (right < pq->size && pq->heap[right].cost < pq->heap[left].cost) {
            smallest = right;
        }
        if (pq->heap[i].cost <= pq->heap[smallest].cost) break;

        PQNode temp = pq->heap[i];
        pq->heap[i] = pq->heap[smallest];
        pq->heap[smallest] = temp;

        i = smallest;
    }
    return top;
}

void ucs(int start, int goal) {
    PriorityQueue pq = {0};
    push(&pq, start, 0);
    int visited[MAX_NODES] = {0},i;

    while (pq.size > 0) {
        PQNode current = pop(&pq);
        if (visited[current.node]) continue;

        printf("%c -> ", nodes[current.node]);
        visited[current.node] = 1;

        if (current.node == goal) {
            printf("Goal reached!\n");
            return;
        }

        for (i = 0; i < MAX_NODES; i++) {
            if (graph[current.node][i] && !visited[i]) {
                push(&pq, i, current.cost + graph[current.node][i]);
            }
        }
    }
}


void searchAlgorithm(int algorithm, int start, int goal) {
    int visited[MAX_NODES] = {0};

    switch (algorithm) {
        case 1:
            printf("DFS Path: ");
            dfs(start, goal, visited);
            break;
        case 2:
            printf("BFS Path: ");
            bfs(start, goal);
            break;
        case 3:
            printf("UCS Path: ");
            ucs(start, goal);
            break;
        default:
            printf("Invalid selection!\n");
    }
}

int main() {
    char startChar, goalChar;
    int algorithm, startNode, goalNode;

    
    printf("Enter Initial Node (S, A, B, C, D, F): ");
    scanf(" %c", &startChar);
    printf("Enter Goal Node (S, A, B, C, D, F): ");
    scanf(" %c", &goalChar);

    
    startNode = getNodeIndex(startChar);
    goalNode = getNodeIndex(goalChar);

    
    if (startNode == -1 || goalNode == -1) {
        printf("Invalid Node Input!\n");
        return 1;
    }

    
    printf("Select Algorithm:\n");
    printf("1. Depth-First Search (DFS)\n");
    printf("2. Breadth-First Search (BFS)\n");
    printf("3. Uniform Cost Search (UCS)\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &algorithm);

    searchAlgorithm(algorithm, startNode, goalNode);

    return 0;
}
