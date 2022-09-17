#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        std::vector<std::vector<bool>> is_substr_palindrome_matrix = initialize_memoized_matrix(s);
        int string_length = s.length();
        int result_left_index = 0, result_right_index = 0;

        for (int atomic_substr_index = 0; atomic_substr_index < string_length; atomic_substr_index++)
            is_substr_palindrome_matrix[atomic_substr_index][atomic_substr_index] = true;

        for (int substr_size = 2; substr_size <= string_length; substr_size++)
        {
            int final_left_index = string_length - substr_size + 1;
            for (int substr_left_index = 0; substr_left_index <= final_left_index; substr_left_index++)
            {
                int substr_right_index = substr_left_index + substr_size - 1;
                bool is_inner_substr_palindrome = substr_size <= 2 ? true : is_substr_palindrome_matrix[substr_left_index + 1][substr_right_index - 1];
                bool is_substr_palindrome = (s[substr_left_index] == s[substr_right_index]) && is_inner_substr_palindrome;
                is_substr_palindrome_matrix[substr_left_index][substr_right_index] = is_substr_palindrome;

                if (is_substr_palindrome)
                {
                    result_left_index = substr_left_index;
                    result_right_index = substr_right_index;
                }
            }
        }

        int result_length = result_right_index - result_left_index + 1;
        string largest_palindrome_substr = s.substr(result_left_index, result_length);
        return largest_palindrome_substr;
    }

private:
    vector<vector<bool>> initialize_memoized_matrix(string &s)
    {
        std::vector<std::vector<bool>> is_substr_palindrome_matrix(s.length(), std::vector<bool>(s.length(), false));
        return is_substr_palindrome_matrix;
    }
};

int main(void)
{
    string a("uzhynqvopdbnkvuxizirzjsslptlhmvyfqhqvqffmqldkrrdwapbdcxqbchvxqixmvbbtalrgzvkobyxlkonkfknabjwzeoazankqzuhexhcwkbvwtioubrcujqqeqoedhploqklhgeilwwnndbnzeadzefkcvaxdhgnmocadvvzjocoweyoidhleuwhmavpdiizbwkukpstyorlwwyiwwyyyzqqgipzzlxsgcdjscdfvrrrqmllbdjkkuisxeqaprfblvjuixajhucmcvffmevaztvadrujbthlnsdrxzvbldwxbazxmilpkbccigkihcgjbtpvignmrgzdqnufaacxtihfgwrllrwgfhitxcaafunqdzgrmngivptbjgchikgiccbkplimxzabxwdlbvzxrdsnlhtbjurdavtzavemffvcmcuhjaxiujvlbfrpaqexsiukkjdbllmqrrrvfdcsjdcgsxlzzpigqqzyyywwiywwlroytspkukwbziidpvamhwuelhdioyewocojzvvdacomnghdxavckfezdaeznbdnnwwlieghlkqolphdeoqeqqjucrbuoitwvbkwchxehuzqknazaoezwjbankfknoklxybokvzgrlatbbvmxiqxvhcbqxcdbpawdrrkdlqmffqvqhqfyvmhltplssjzrizixuvknbdpovqnyhzu");
    Solution solver;
    string result = solver.longestPalindrome(a);
    cout << result << '\n';
    return 0;
}