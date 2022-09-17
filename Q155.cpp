#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class MinStack
{
public:
    MinStack() : minimum_value(INT_MAX)
    {
    }

    void push(int val)
    {
        values.emplace_back(val);
        if (val <= minimum_value)
        {
            min_history.emplace_back(minimum_value);
            minimum_value = val;
            std::cout << minimum_value << std::endl;
        }
    }

    void pop()
    {
        int top_element = this->top();
        if (top_element == minimum_value)
        {
            minimum_value = min_history.back();
            min_history.pop_back();
        }
        values.pop_back();
    }

    int top()
    {
        int top_element = values.back();
        return top_element;
    }

    int getMin()
    {
        return minimum_value;
    }

private:
    int minimum_value;
    std::vector<int> min_history;
    std::vector<int> values;
};

int main(void)
{
    int val = 3;
    MinStack *obj = new MinStack();
    obj->push(val);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
}
