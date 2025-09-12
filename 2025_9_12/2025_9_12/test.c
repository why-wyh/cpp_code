#define _CRT_SECURE_NO_WARNINGS 


//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {
    ListNode* new = NULL;
    ListNode* newhead;
    ListNode* newtail;
    ListNode* pcur = head;
    newhead = newtail = new;
    if (head == NULL)
    {
        return NULL;
    }
    while (pcur)
    {
        if (pcur->val != val)
        {
            if (newhead == NULL)
            {
                newhead = newtail = pcur;
            }
            else {
                newtail->next = pcur;
                newtail = newtail->next;
            }
        }
        pcur = pcur->next;

    }
    if (newtail)
    {
        newtail->next = NULL;
    }
    return newhead;

}




//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head) {
    ListNode* n1, * n2, * n3;
    if (head == NULL)
    {
        return NULL;
    }
    n1 = NULL, n2 = head, n3 = head->next;
    while (n2)
    {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    return n1;

}



//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    ListNode* newhead = NULL;
    ListNode* newtail = NULL;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    while (p1 && p2)
    {
        if (p1->val >= p2->val)
        {
            if (newhead == NULL)
            {
                newhead = newtail = p2;
            }
            else {
                newtail->next = p2;
                newtail = newtail->next;
            }
            p2 = p2->next;
        }
        else {
            if (newhead == NULL)
            {
                newhead = newtail = p1;
            }
            else {
                newtail->next = p1;
                newtail = newtail->next;
            }
            p1 = p1->next;
        }
    }
    if (p1)
    {
        newtail->next = p1;
        p1 = p1->next;
    }
    if (p2)
    {
        newtail->next = p2;
        p2 = p2->next;
    }
    return newhead;
}