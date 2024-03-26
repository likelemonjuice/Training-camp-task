// LQueue.c

#include "LQueue.h"

void InitLQueue(LQueue* Q) {
    CHECK_NULL(Q);
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

void DestoryLQueue(LQueue* Q) {
    CHECK_NULL(Q);
    Node* current = Q->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

Status IsEmptyLQueue(const LQueue* Q) {
    CHECK_NULL(Q);
    return Q->front == NULL ? SUCCESS : FAILURE;
}

Status GetHeadLQueue(LQueue* Q, void* e) {
    CHECK_NULL(Q);
    if (Q->front == NULL) {
        return FAILURE;
    }
    e = Q->front->data;
    return SUCCESS;
}

int LengthLQueue(LQueue* Q) {
    CHECK_NULL(Q);
    return Q->length;
}

Status EnLQueue(LQueue* Q, void* data) {
    CHECK_NULL(Q);
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return FAILURE;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (Q->rear == NULL) {
        Q->front = new_node;
        Q->rear = new_node;
    }
    else {
        Q->rear->next = new_node;
        Q->rear = new_node;
    }
    Q->length++;
    return SUCCESS;
}

Status DeLQueue(LQueue* Q) {
    CHECK_NULL(Q);
    if (Q->front == NULL) {
        return FAILURE;
    }
    Node* temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
    Q->length--;
    return SUCCESS;
}

void ClearLQueue(LQueue* Q) {
    CHECK_NULL(Q);
    while (Q->front != NULL) {
        DeLQueue(Q);
    }
}

void LPrint(void* q) {
    CHECK_NULL(q);
    Node* temp = *(Node**)q;
    while (temp != NULL) {
        printf("%p ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// main.c

#include <stdio.h>
#include "LQueue.h"

int main() {
    LQueue Q;
    void* data;
    char input[100];

    // 初始化队列
    InitLQueue(&Q);

    // 添加元素到队列
    while (1) {
        printf("请输入要添加到队列的数据（输入'exit'结束）：");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        EnLQueue(&Q, (void*)input);
    }

    // 检查队列是否为空
    if (IsEmptyLQueue(&Q)) {
        printf("队列是空的\n");
    }
    else {
        printf("队列不为空\n");
    }

    // 获取队列的长度
    printf("队列的长度: %d\n", LengthLQueue(&Q));

    // 获取队列的头部元素
    if (GetHeadLQueue(&Q, &data)) {
        printf("队列的头部元素: %s\n", (char*)data);
    }
    else {
        printf("获取头部元素失败\n");
    }

    // 从队列中删除元素
    for (int i = 0; i < 5; i++) {
        DeLQueue(&Q);
    }

    // 获取队列的长度
    printf("删除元素后的队列长度: %d\n", LengthLQueue(&Q));

    // 销毁队列
    DestoryLQueue(&Q);

    // 检查队列是否为空
    if (IsEmptyLQueue(&Q)) {
        printf("销毁后的队列是空的\n");
    }
    else {
        printf("销毁后的队列不为空\n");
    }

    return 0;
}
