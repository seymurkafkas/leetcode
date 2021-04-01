
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
    ListNode *prev = nullptr;
    ListNode *head = nullptr;
    bool carry = false;
    while (l1 || l2 || carry)
    {

      int res = carry;
      if (l1)
      {

        res += l1->val;

        l1 = l1->next;
      }

      if (l2)
      {
        res += l2->val;
        l2 = l2->next;
      }

      if (res >= 10)
      {
        res -= 10;
        carry = true;
      }
      else
      {
        carry = false;
      }

      ListNode *current = new ListNode(res);
      if (prev)
      {
        prev->next = current;
      }
      else
      {
        head = current;
      }

      prev = current;
    }

    return head;
  }
};