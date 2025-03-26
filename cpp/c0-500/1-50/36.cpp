class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (size_t r = 0; r < 9; r++)
        {
            for (size_t c = 0; c < 9; c++)
            {
                if (board[r][c] == '.') continue;

                int num = board[r][c] - '1'; // to convert 1 - 9 to index 0 - 8
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (rows[r][num] || cols[c][num] || boxes[boxIndex][num])
                {
                    return false;
                }

                rows[r][num] = cols[c][num] = boxes[boxIndex][num] = true;
            }
        }
        return true;
    }
};