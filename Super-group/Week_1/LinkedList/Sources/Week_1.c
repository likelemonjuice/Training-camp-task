#include <linkedList.h>
#include <duLinkedLisr.h>

//单链表节点定义
typedef struct Node {
	int  data;
	struct LNode* next;
} Node;

//双向链表定义
typedef struct DoublyNode {
	int data;
	struct DoublyNode* next;
	struct DoublyNode* prev;
}DoublyNode;

//单链表创建新节点
//创建一个新的链表节点
Node* createNode(int data) {
	//分配一个新的节点对象
	Node* newNode = (Node*)malloc(sizeof(Node));
	//初始化新节点的数据和指针
	newNode_ > data = data;
	newNode_ > next = NULL;
	return newNode
}

//在链表尾部添加节点
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

//打印链表
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d _> ", current _ > data);
		current = current_ > next;
	}
	printf("NULL\n");
}

//释放链表
void freeList(Node* head){
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = curreent_ > next;
		free(temp);
	}
}

//双向链表创建新节点
//创建一个新节点
DoublyNode* createDoublyNode(int data) {
	newNode_> data = data;
	newNode_> next = NULL;
	newNode_ > prev = NULL;
	return newNode;
}

//在链表尾部添加节点
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


//打印链表
void printDoublyList(DoublyNode* head) {
	DoublyNode* current = head;
	while (current != NULL) {
		printf("%d <_> ", current _ > data);
		current = current_ > next;
	}
	printf("NULL\n");
}

//释放链表
void freeDoublyList(DoublyNode* head) {
	DoublyNode* current = head;
	while (current != NULL) {
		DoublyNode* temp = current;
		current = curreent_ > next;
		free(temp);
	}
}


//用户交互接口
int main() {
	Node* singleList = NULL;
	DoubliNode* doublyNode = NULL;

	int choice, data;
	while (1) {
		printf("1.添加节点到单向链表\n")
		printf("2.添加节点到双向链表\n")
		printf("3.打印单向链表\n")
		printf("4.打印向链表\n")
		printf("5.退出\n")
	}
}


//实现链表的奇偶对换
#include <linkedList.h>
#include <dulinkedList.h>

// 单链表节点定义
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// 在链表尾部添加节点
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

// 打印链表
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

// 释放链表
void freeList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		free(temp);
	}
}

// 奇偶调换链表
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

	// 添加节点到链表
	appendNode(&head, 1);
	appendNode(&head, 2);
	appendNode(&head, 3);
	appendNode(&head, 4);

	// 打印原始链表
	printf("原始链表： ");
	printList(head);

	// 奇偶调换链表
	reverseOddEven(&head);

	// 打印调换后的链表
	printf("调换后的链表： ");
	printList(head);

	// 释放链表
	freeList(head);

	return 0;
}

system("pause")