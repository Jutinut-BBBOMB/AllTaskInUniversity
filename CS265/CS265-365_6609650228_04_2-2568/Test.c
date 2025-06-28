#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_EDGES 20
#define MAX_EXPAND 30

// Structure for a graph node
typedef struct {
    char name;
    int heuristic;
} Node;

// Structure for edges
typedef struct {
    char from;
    char to;
    int cost;
} Edge;

// Structure for queue (BFS)
typedef struct {
    char data[MAX_NODES];
    int front, rear;
} Queue;

// Structure for stack (DFS)
typedef struct {
    char data[MAX_NODES];
    int top;
} Stack;

// Graph definition
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes = 0, num_edges = 0;

// Function prototypes
int isVisited(char visited[], int visitCount, char node);
void DFS(char start, char goal);
void BFS(char start, char goal);
void UCS(char start, char goal);
void Greedy(char start, char goal);
void AStar(char start, char goal);

// Function to add a node to the graph
void addNode(char name, int heuristic) {
    nodes[num_nodes].name = name;
    nodes[num_nodes].heuristic = heuristic;
    num_nodes++;
}

// Function to add an edge
void addEdge(char from, char to, int cost) {
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    edges[num_edges].cost = cost;
    num_edges++;
}

// Function to check if a node has been visited
int isVisited(char visited[], int visitCount, char node) {
    for (int i = 0; i < visitCount; i++) {
        if (visited[i] == node) return 1;
    }
    return 0;
}

// DFS Implementation
void DFS(char start, char goal) {
    Stack stack;
    stack.top = -1;
    stack.data[++stack.top] = start;
    
    char visited[MAX_NODES];
    int visitCount = 0;
    int expandCount = 0;
    
    printf("DFS Path: ");
    
    while (stack.top != -1) {
        if (expandCount++ > MAX_EXPAND) {
            printf("\nExceeded max expansions. No solution found.\n");
            return;
        }
        
        char current = stack.data[stack.top--];
        if (isVisited(visited, visitCount, current)) continue;
        
        visited[visitCount++] = current;
        printf("%c ", current);
        
        if (current == goal) {
            printf("\nSolution Found!\n");
            return;
        }
        
        for (int i = num_edges - 1; i >= 0; i--) {
            if (edges[i].from == current && !isVisited(visited, visitCount, edges[i].to)) {
                stack.data[++stack.top] = edges[i].to;
            }
        }
    }
    printf("\nNo solution found.\n");
}

// BFS Implementation
void BFS(char start, char goal) {
    Queue queue;
    queue.front = 0;
    queue.rear = 0;
    queue.data[queue.rear++] = start;
    
    char visited[MAX_NODES];
    int visitCount = 0;
    int expandCount = 0;
    
    printf("BFS Path: ");
    
    while (queue.front < queue.rear) {
        if (expandCount++ > MAX_EXPAND) {
            printf("\nExceeded max expansions. No solution found.\n");
            return;
        }
        
        char current = queue.data[queue.front++];
        if (isVisited(visited, visitCount, current)) continue;
        
        visited[visitCount++] = current;
        printf("%c ", current);
        
        if (current == goal) {
            printf("\nSolution Found!\n");
            return;
        }
        
        for (int i = 0; i < num_edges; i++) {
            if (edges[i].from == current && !isVisited(visited, visitCount, edges[i].to)) {
                queue.data[queue.rear++] = edges[i].to;
            }
        }
    }
    printf("\nNo solution found.\n");
}

void UCS(char start, char goal) {
    int expandCount = 0;
    int visited[MAX_NODES] = {0};  // เก็บสถานะการเยี่ยมชม
    int g_cost[MAX_NODES];         // ค่า cost ที่คำนวณจากเส้นทาง
    char parent[MAX_NODES];        // เก็บ parent ของแต่ละ node สำหรับย้อนเส้นทาง

    for (int i = 0; i < MAX_NODES; i++) {
        g_cost[i] = INT_MAX;  // กำหนดค่าเริ่มต้นที่ไม่มีการเยี่ยมชม
    }
    g_cost[start - 'A'] = 0;  // ค่าเริ่มต้นของ start node เป็น 0
    
    // ใช้ array เพื่อเก็บ node ที่จะตรวจสอบ
    char queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = start;

    printf("UCS Path: ");
    
    while (front < rear) {
        if (expandCount++ > MAX_EXPAND) {
            printf("\nExceeded max expansions. No solution found.\n");
            return;
        }

        char current = queue[front++];
        if (visited[current - 'A']) continue;
        visited[current - 'A'] = 1;
        
        printf("%c ", current);
        
        if (current == goal) {
            printf("\nSolution Found!\n");
            return;
        }

        // ตรวจสอบ edge ที่เชื่อมโยงกับ node ปัจจุบัน
        for (int i = 0; i < num_edges; i++) {
            if (edges[i].from == current && !visited[edges[i].to - 'A']) {
                int new_cost = g_cost[current - 'A'] + edges[i].cost;
                if (new_cost < g_cost[edges[i].to - 'A']) {
                    g_cost[edges[i].to - 'A'] = new_cost;
                    parent[edges[i].to - 'A'] = current;
                    queue[rear++] = edges[i].to;
                }
            }
        }
    }
    printf("\nNo solution found.\n");
}

// Function to implement Greedy Best-First Search
void Greedy(char start, char goal) {
    int expandCount = 0;
    int visited[MAX_NODES] = {0};  // เก็บสถานะการเยี่ยมชม
    char queue[MAX_NODES];
    int front = 0, rear = 0;
    
    // ใช้ heuristic สำหรับการตัดสินใจในการเลือก node
    int heuristic[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        heuristic[nodes[i].name - 'A'] = nodes[i].heuristic;
    }
    
    queue[rear++] = start;

    printf("Greedy Path: ");
    
    while (front < rear) {
        if (expandCount++ > MAX_EXPAND) {
            printf("\nExceeded max expansions. No solution found.\n");
            return;
        }

        // เลือก node ที่มีค่า heuristic ต่ำที่สุด
        char current = queue[front++];
        if (visited[current - 'A']) continue;
        visited[current - 'A'] = 1;
        
        printf("%c ", current);
        
        if (current == goal) {
            printf("\nSolution Found!\n");
            return;
        }

        // ตรวจสอบ edge ที่เชื่อมโยงกับ node ปัจจุบัน
        for (int i = 0; i < num_edges; i++) {
            if (edges[i].from == current && !visited[edges[i].to - 'A']) {
                queue[rear++] = edges[i].to;
            }
        }
    }
    printf("\nNo solution found.\n");
}

// Function to implement A* Search
void AStar(char start, char goal) {
    int expandCount = 0;
    int visited[MAX_NODES] = {0};
    int g_cost[MAX_NODES], f_cost[MAX_NODES];
    char queue[MAX_NODES];
    int front = 0, rear = 0;
    char parent[MAX_NODES];
    
    // กำหนดค่า heuristic
    for (int i = 0; i < num_nodes; i++) {
        g_cost[i] = INT_MAX;
        f_cost[i] = INT_MAX;
    }
    
    g_cost[start - 'A'] = 0;
    f_cost[start - 'A'] = nodes[start - 'A'].heuristic;
    queue[rear++] = start;

    printf("A* Path: ");
    
    while (front < rear) {
        if (expandCount++ > MAX_EXPAND) {
            printf("\nExceeded max expansions. No solution found.\n");
            return;
        }
        
        // เลือก node ที่มีค่า f_cost ต่ำที่สุด
        char current = queue[front++];
        if (visited[current - 'A']) continue;
        visited[current - 'A'] = 1;
        
        printf("%c ", current);
        
        if (current == goal) {
            printf("\nSolution Found!\n");
            return;
        }

        // ตรวจสอบ edge ที่เชื่อมโยงกับ node ปัจจุบัน
        for (int i = 0; i < num_edges; i++) {
            if (edges[i].from == current && !visited[edges[i].to - 'A']) {
                int new_g_cost = g_cost[current - 'A'] + edges[i].cost;
                if (new_g_cost < g_cost[edges[i].to - 'A']) {
                    g_cost[edges[i].to - 'A'] = new_g_cost;
                    f_cost[edges[i].to - 'A'] = new_g_cost + nodes[edges[i].to - 'A'].heuristic;
                    queue[rear++] = edges[i].to;
                }
            }
        }
    }
    printf("\nNo solution found.\n");
}


// Function to select and run an algorithm
void selectAlgorithm(char algorithm, char start, char goal) {
    switch (algorithm) {
        case '1':
            DFS(start, goal);
            break;
        case '2':
            BFS(start, goal);
            break;
        case '3':
            UCS(start, goal);
            break;
        case '4':
            Greedy(start, goal);
            break;
        case '5':
            AStar(start, goal);
            break;
        default:
            printf("Invalid selection.\n");
    }
}

int main() {
    // Define nodes (example from the graph)
    addNode('S', 10);
    addNode('A', 8);
    addNode('B', 9);
    addNode('C', 7);
    addNode('D', 4);
    addNode('E', 3);
    addNode('F', 0);
    addNode('G', 6);
    addNode('H', 6);
    
    // Define edges (example from the graph)
    addEdge('S', 'A', 3);
    addEdge('S', 'B', 2);
    addEdge('S', 'C', 4);
    addEdge('A', 'G', 2);
    addEdge('A', 'H', 4);
    addEdge('A', 'C', 3);
    addEdge('B', 'C', 4);
    addEdge('C', 'D', 3);
    addEdge('G', 'D', 4);
    addEdge('G', 'E', 5);
    addEdge('H', 'D', 4);
    addEdge('E', 'F', 5);
    addEdge('D', 'F', 3);
    addEdge('E', 'D', 2);
    
    char algorithm;
    char start, goal;
    
    printf("Select Algorithm:\n");
    printf("1. DFS\n");
    printf("2. BFS\n");
    printf("3. UCS\n");
    printf("4. Greedy Best-First Search\n");
    printf("5. A* Search\n");
    printf("Enter choice: ");
    scanf(" %c", &algorithm);
    
    printf("Enter start node: ");
    scanf(" %c", &start);
    printf("Enter goal node: ");
    scanf(" %c", &goal);
    
    selectAlgorithm(algorithm, start, goal);
    
    return 0;
}
