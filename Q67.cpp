#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int a_size = a.size();
        int b_size = b.size();
        int digit_count = max(a_size, b_size) + 1;
        std::string result(digit_count, '0');
        bool carry = false;
        bool current_digit;

        for (int i = 0; i <= digit_count - 1; ++i)
        {
            bool first_operand = false;
            bool second_operand = false;

            int first_operand_index = a_size - 1 - i;
            if (first_operand_index >= 0)
                first_operand = a[first_operand_index] == '1' ? true : false;

            int second_operand_index = b_size - 1 - i;
            if (second_operand_index >= 0)
                second_operand = b[second_operand_index] == '1' ? true : false;

            current_digit = first_operand ^ second_operand ^ carry;
            carry = (first_operand && second_operand) || (first_operand && carry) || (second_operand && carry);

            result[digit_count - 1 - i] = current_digit ? '1' : '0';
        }

        bool is_leading_one = current_digit;

        if (!is_leading_one)
            result = result.substr(1, string::npos);

        return result;
    }
};

int main()
{
    std::string input("00111");
    std::string input_2("11000");
    Solution a;
    std::cout << a.addBinary(input, input_2);
}