#include <linkedList.h>
#include <duLinkedLisr.h>

//������ڵ㶨��
typedef struct Node {
	int  data;
	struct LNode* next;
} Node;

//˫��������
typedef struct DoublyNode {
	int data;
	struct DoublyNode* next;
	struct DoublyNode* prev;
}DoublyNode;

//���������½ڵ�
//����һ���µ�����ڵ�
Node* createNode(int data) {
	//����һ���µĽڵ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	//��ʼ���½ڵ�����ݺ�ָ��
	newNode_ > data = data;
	newNode_ > next = NULL;
	return newNode
}

//������β����ӽڵ�
void appendNode(Node** head, int data) {
	Node newNode = createNode(data);
	if (*head == NULL) {
		*head == newNode;
		return;
	}
	Node* current = *head;
	while (current _ > next != NULL) {
		current = current_ > next;
	}
	current_ > next = newNode;
}

//��ӡ����
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d _> ", current _ > data);
		current = current_ > next;
	}
	printf("NULL\n");
}

//�ͷ�����
void freeList(Node* head){
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = curreent_ > next;
		free(temp);
	}
}

//˫���������½ڵ�
//����һ���½ڵ�
DoublyNode* createDoublyNode(int data) {
	newNode_> data = data;
	newNode_> next = NULL;
	newNode_ > prev = NULL;
	return newNode;
}

//������β����ӽڵ�
void appendDoublyNode(DoublyNode** head, int data) {
	DoublyNode* = newNode = createDoublyNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	DoublyNode* curent = *head;
	while (current _ > next != NULL) {
		current = current_ > next;
		}
		current_ > next = newNode;
		newNode_ > prev = current;
	}


//��ӡ����
void printDoublyList(DoublyNode* head) {
	DoublyNode* current = head;
	while (current != NULL) {
		printf("%d <_> ", current _ > data);
		current = current_ > next;
	}
	printf("NULL\n");
}

//�ͷ�����
void freeDoublyList(DoublyNode* head) {
	DoublyNode* current = head;
	while (current != NULL) {
		DoublyNode* temp = current;
		current = curreent_ > next;
		free(temp);
	}
}


//�û������ӿ�
int main() {
	Node* singleList = NULL;
	DoubliNode* doublyNode = NULL;

	int choice, data;
	while (1) {
		printf("1.��ӽڵ㵽��������\n")
		printf("2.��ӽڵ㵽˫������\n")
		printf("3.��ӡ��������\n")
		printf("4.��ӡ������\n")
		printf("5.�˳�\n")
	}
}


//ʵ���������ż�Ի�
#include <linkedList.h>
#include <dulinkedList.h>

// ������ڵ㶨��
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// �����½ڵ�
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// ������β����ӽڵ�
void appendNode(Node** head, int data) {
	Node* newNode = createNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	Node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

// ��ӡ����
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

// �ͷ�����
void freeList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}

// ��ż��������
void reverseOddEven(Node** head) {
	Node* oddHead = NULL, * evenHead = NULL, * oddCurrent = NULL, * evenCurrent = NULL, * temp = NULL;

	Node* current = *head;
	int isOdd = 1;

	while (current != NULL) {
		if (isOdd) {
			if (oddHead == NULL) {
				oddHead = current;
			}
			else {
				oddCurrent->next = current;
			}
			oddCurrent = current;
		}
		else {
			if (evenHead == NULL) {
				evenHead = current;
			}
			else {
				evenCurrent->next = current;
			}
			evenCurrent = current;
		}
		isOdd = !isOdd;
		current = current->next;
	}

	if (oddHead != NULL && evenHead != NULL) {
		oddCurrent->next = evenHead;
		evenCurrent->next = NULL;
		*head = oddHead;
	}
}

int main() {
	Node* head = NULL;

	// ��ӽڵ㵽����
	appendNode(&head, 1);
	appendNode(&head, 2);
	appendNode(&head, 3);
	appendNode(&head, 4);

	// ��ӡԭʼ����
	printf("ԭʼ���� ");
	printList(head);

	// ��ż��������
	reverseOddEven(&head);

	// ��ӡ�����������
	printf("����������� ");
	printList(head);

	// �ͷ�����
	freeList(head);

	return 0;
}

system("pause")