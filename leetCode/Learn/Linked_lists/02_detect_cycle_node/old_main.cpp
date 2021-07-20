#include <iostream>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // check if linked list is empty or only one node exists, return null
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }

        ListNode *temp = head;

        map<ListNode *, bool> encounteredNodes;

        while (temp != nullptr)
        {
            if (encounteredNodes.count(temp) != 0)
            {
                return temp;
            }
            encounteredNodes.insert({temp, true});
            temp = temp->next;
        }

        return nullptr;
    }
};

ListNode *flyods_hare_tortoise(ListNode *head)
{
    // check if linked list is empty or only one node exists, return null
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    ListNode *temp = head;
    // phase 1: get the node, where hare and tortoise 1st met
}

int main()
{

    return 0;
}