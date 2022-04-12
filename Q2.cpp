#include <iostream>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool carry = false;

        ListNode *prevNode = nullptr;
        ListNode *head = nullptr;

        while (l1 || l2 || carry)
        {
            int leftValue = l1 ? l1->val : 0;
            int rightValue = l2 ? l2->val : 0;

            int currentSum = (leftValue + rightValue + carry);
            carry = currentSum >= 10;
            int digitSum = currentSum % 10;

            if (prevNode)
            {
                prevNode->next = new ListNode(digitSum);
                prevNode = prevNode->next;
            }

            else
            {
                head = new ListNode(digitSum);
                prevNode = head;
            }

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        return head;
    }
};

int main()
{

    try
    {
        Solution solver;
        ListNode *a = new ListNode(3);
        ListNode *b = new ListNode(6);
        ListNode *result = solver.addTwoNumbers(a, b);

        while (result)
        {
            std::cout << result->val << '\n';
            result = result->next;
        }
    }
    catch (std::string &error)
    {
        std::cout << error << '\n';
    }
}