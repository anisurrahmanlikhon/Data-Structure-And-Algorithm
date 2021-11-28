// A complete working C program to demonstrate all insertion methods
// on Linked List
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
struct Node* push(struct Node* head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. Make next of new node as head */
    new_node->next = head_ref;

    /* 4. move the head to point to the new node */
    head_ref    = new_node;
    return head_ref;
}

/* Given a node prev_node, insert a new node after the given
   prev_node */
void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }

    /* 2. allocate new node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    /* 3. put in the data  */
    new_node->data  = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
struct Node* append(struct Node* head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (head_ref == NULL)
    {
       head_ref = new_node;
       return head_ref;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return head_ref;
}

int countOfNodes(struct Node* head)
{
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;

}
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("\n\nThe Middle Element is %d\n", slow_ptr->data);
    }
}

void moveToFront(struct Node **head)
{

    if (*head == NULL || (*head)->next == NULL)
        return;


    struct Node *secLast = NULL;
    struct Node *last = *head;


    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }


    secLast->next = NULL;

    last->next = *head;


    *head = last;
}




void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

void printFront(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;

    }
}

/* Driver program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;

  // Insert 6.  So linked list becomes 6->NULL
  head=append(head, 6);

  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  head=push(head, 10);

  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
  head=push(head, 1);

  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
  head=append(head, 4);

  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
  insertAfter(head->next, 8);

  head=push(head, 3);

  insertAfter(head, 11);

  printf("\nCreated Linked List is: ");
  printList(head);
  printf("\n\nThe Counted Node is %d\n", countOfNodes(head));
  printMiddle(head);
  printf("\nDelete Last Add Front Linked List is: ");
  moveToFront(&head);
  printFront(head);
  printf("\n");
return 0;
}
