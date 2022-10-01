#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *mid_node = get_mid_node(head);
        ListNode *reversed_half_list_head = get_reversed_list_head(mid_node);
        ListNode *front = head;
        ListNode *back = reversed_half_list_head;

        for (;; front = front->next, back = back->next)
        {
            if (!front || !back)
                return true;
            int left_value = front->val;
            int right_value = back->val;
            if (left_value != right_value)
                return false;
        }

        return true;
    }

private:
    ListNode *get_mid_node(ListNode *head)
    {
        ListNode *node = head;
        ListNode *node_fast = head;
        while (node_fast != nullptr)
        {
            node = node->next;
            node_fast = node_fast->next;
            if (!node_fast)
                return node;
            node_fast = node_fast->next;
        }
        return node;
    }

    ListNode *get_reversed_list_head(ListNode *old_head)
    {
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        for (ListNode *node = old_head; node; node = next)
        {
            next = node->next;
            node->next = prev;
            prev = node;
        }
        return prev;
    }
};