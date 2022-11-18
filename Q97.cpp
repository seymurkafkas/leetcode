#include <string>
#include <iostream>
#include <vector>
#include <utility>

enum Turn
{
    MOVE_S1,
    MOVE_S2
};

struct Action
{
    int match_amount;

    static Action make_action(int match_amount)
    {
        Action result;
        result.match_amount = match_amount;
        return result;
    }
};

struct State
{
    int s1_idx;
    int s2_idx;
    int s3_idx;

    Turn turn;

    static State make_initial_state()
    {
        State initial_state;
        initial_state.s1_idx = 0;
        initial_state.s2_idx = 0;
        initial_state.s3_idx = 0;
        initial_state.turn = MOVE_S1;
        return initial_state;
    }

    State next_state(Action action)
    {
        State next_state = *this;
        next_state.turn = turn == MOVE_S1 ? MOVE_S2 : MOVE_S1;

        if (turn == MOVE_S1)
            next_state.s1_idx += action.match_amount;
        else if (turn == MOVE_S2)
            next_state.s2_idx += action.match_amount;

        next_state.s3_idx += action.match_amount;
        return next_state;
    }

    bool isTerminal(std::string &s1, std::string &s2, std::string &s3)
    {
        return s1_idx == s1.size() && s2_idx == s2.size() && s3_idx == s3.size();
    }

    int getMatchLength(std::string &s1, std::string &s2, std::string &s3)
    {
        int match_count = 0;
        int j = s3_idx;

        if (turn == MOVE_S1)
        {
            for (int i = s1_idx; i < s1.size(); i++)
            {
                if (s1[i] != s3[j])
                    break;

                match_count++;
                j++;
            }
        }
        else if (turn == MOVE_S2)
        {
            for (int i = s2_idx; i < s2.size(); i++)
            {
                if (s2[i] != s3[j])
                    break;

                match_count++;
                j++;
            }
        }
        return match_count;
    }
};

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int s1_length = s1.length();
        int s2_length = s2.length();

        auto initial_state = State::make_initial_state();
        return isInterleaveMemoized(initial_state, s1, s2, s3);
    }

private:
    bool isInterleaveMemoized(State state, string &s1, string &s2, string &s3)
    {
        if (state.isTerminal(s1, s2, s3))
            return true;

        int match_length = state.getMatchLength(s1, s2, s3);

        for (int i = 0; i < match_length; i++)
        {
            Action permissible_action = Action::make_action(i + 1);
            State next_state = state.next_state(permissible_action);

            bool is_interleave = isInterleaveMemoized(next_state, s1, s2, s3);
            if (is_interleave)
                return true;
        }

        return false;
    }
};

int main(void)
{
    std::string s1("aabcc");
    std::string s2("dbbca");
    std::string s3("aadbbcbcac");
    Solution solver;
    bool result = solver.isInterleave(s1, s2, s3);
    std::cout << result;
}