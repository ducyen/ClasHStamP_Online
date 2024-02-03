#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <termios.h>
#include <fcntl.h>

#define INTERVAL_SEC 2

// Node for the message queue
typedef struct node {
    char data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    pthread_mutex_t lock;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    pthread_mutex_init(&q->lock, NULL);
}

// Enqueue a message
void enqueue(Queue* q, char data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    pthread_mutex_lock(&q->lock);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    pthread_mutex_unlock(&q->lock);
}

// Dequeue a message
char dequeue(Queue* q) {
    pthread_mutex_lock(&q->lock);
    if (q->front == NULL) {
        pthread_mutex_unlock(&q->lock);
        return '\0';
    }

    Node* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    pthread_mutex_unlock(&q->lock);
    return data;
}

// Check for keyboard hit
int kbhit(void) {
    // [Implementation remains the same as before]
}

// Keyboard Thread
void* keyboard_thread(void* arg) {
    Queue* q = (Queue*)arg;
    printf("Keyboard thread started. Press 'q' to exit.\n");

    while (1) {
        if (kbhit()) {
            char c = getchar();
            enqueue(q, c);
            if (c == 'q') {
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);
            }
        }
        usleep(100000); // Sleep for 100 milliseconds
    }
    return NULL;
}

// Timer Thread
void* timer_thread(void* arg) {
    Queue* q = (Queue*)arg;

    while (1) {
        sleep(INTERVAL_SEC);
        char msg = dequeue(q);
        if (msg != '\0') {
            printf("Timer received message: %c\n", msg);
        }
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    Queue q;

    initQueue(&q);

    // Create threads
    if (pthread_create(&thread1, NULL, keyboard_thread, (void*)&q) != 0) {
        perror("pthread_create for keyboard thread");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thread2, NULL, timer_thread, (void*)&q) != 0) {
        perror("pthread_create for timer thread");
        return EXIT_FAILURE;
    }

    // Join Threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return EXIT_SUCCESS
