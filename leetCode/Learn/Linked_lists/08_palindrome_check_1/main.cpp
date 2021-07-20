#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static ListNode *gp;

bool checkIfPalindrome(ListNode *head)
{
    if (head == nullptr)
    {
        return true;
    }
    if (!checkIfPalindrome(head->next))
        return false;
    if (!(gp->val == head->val))
        return false;
    gp = gp->next;
    return true;
}

bool isPalindrome(ListNode *head)
{
    gp = head;
    return checkIfPalindrome(head);
}
