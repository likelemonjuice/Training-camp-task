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

    // ��ʼ������
    InitLQueue(&Q);

    // ���Ԫ�ص�����
    while (1) {
        printf("������Ҫ��ӵ����е����ݣ�����'exit'��������");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        EnLQueue(&Q, (void*)input);
    }

    // �������Ƿ�Ϊ��
    if (IsEmptyLQueue(&Q)) {
        printf("�����ǿյ�\n");
    }
    else {
        printf("���в�Ϊ��\n");
    }

    // ��ȡ���еĳ���
    printf("���еĳ���: %d\n", LengthLQueue(&Q));

    // ��ȡ���е�ͷ��Ԫ��
    if (GetHeadLQueue(&Q, &data)) {
        printf("���е�ͷ��Ԫ��: %s\n", (char*)data);
    }
    else {
        printf("��ȡͷ��Ԫ��ʧ��\n");
    }

    // �Ӷ�����ɾ��Ԫ��
    for (int i = 0; i < 5; i++) {
        DeLQueue(&Q);
    }

    // ��ȡ���еĳ���
    printf("ɾ��Ԫ�غ�Ķ��г���: %d\n", LengthLQueue(&Q));

    // ���ٶ���
    DestoryLQueue(&Q);

    // �������Ƿ�Ϊ��
    if (IsEmptyLQueue(&Q)) {
        printf("���ٺ�Ķ����ǿյ�\n");
    }
    else {
        printf("���ٺ�Ķ��в�Ϊ��\n");
    }

    return 0;
}
