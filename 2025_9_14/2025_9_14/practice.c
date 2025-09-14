#define _CRT_SECURE_NO_WARNINGS
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* ret = NULL;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}









/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param n int整型
 * @param m int整型
 * @return int整型
 */
#include <stdlib.h>
typedef  struct ListNode ListNode;

ListNode* buynewnode(int x) {
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}
ListNode* creatlinklist(int n) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* taill = head;
    for (int i = 1; i <= n; i++) {
        ListNode* newnode = buynewnode(i);
        taill->next = newnode;
        taill = taill->next;
    }
    taill->next = head;
    return taill;
}

int ysf(int n, int m) {
    ListNode* prv = creatlinklist(n);
    ListNode* pcur = prv->next;
    int count = 1;
    while (pcur != pcur->next)
    {
        if (count == m)
        {
            prv->next = pcur->next;
            ListNode* desy = pcur;
            pcur = pcur->next;
            free(desy);
            desy = NULL;
            count = 1;
        }
        else {
            count++;
            prv = prv->next;
            pcur = pcur->next;
        }
    }


}