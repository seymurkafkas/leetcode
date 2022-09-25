#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *previous_min = nullptr;
        ListNode *head = nullptr;
        ListNode *min = nullptr;

        while (min = get_min_and_pop(lists))
        {
            if (!head)
                head = min;

            (previous_min && (previous_min->next = min));
            previous_min = min;
        }

        return head;
    }

private:
    ListNode *get_min_and_pop(vector<ListNode *> &lists)
    {
        ListNode *result = nullptr;
        int list_size = lists.size();
        int index_of_min;

        for (int i = 0; i < list_size; ++i)
        {
            ListNode *head_node = lists[i];
            if (!head_node)
                continue;

            if (result == nullptr || result->val >= head_node->val)
            {
                result = head_node;
                index_of_min = i;
            }
        }

        result && (lists[index_of_min] = result->next);
        return result;
    }
};