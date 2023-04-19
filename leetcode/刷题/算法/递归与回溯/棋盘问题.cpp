//1.按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//class Solution {
//private:
//    vector<vector<string>> result;
//    // n 为输入的棋盘大小
//    // row 是当前递归到棋盘的第几行了
//    void backtracking(int n, int row, vector<string>& chessboard) {
//        if (row == n) {
//            result.push_back(chessboard);
//            return;
//        }
//        for (int col = 0; col < n; col++) {
//            if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
//                chessboard[row][col] = 'Q'; // 放置皇后
//                backtracking(n, row + 1, chessboard);
//                chessboard[row][col] = '.'; // 回溯，撤销皇后
//            }
//        }
//    }
//    bool isValid(int row, int col, vector<string>& chessboard, int n) {
//        // 检查列
//        for (int i = 0; i < row; i++) { // 这是一个剪枝
//            if (chessboard[i][col] == 'Q') {
//                return false;
//            }
//        }
//        // 检查 45度角是否有皇后
//        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
//            if (chessboard[i][j] == 'Q') {
//                return false;
//            }
//        }
//        // 检查 135度角是否有皇后
//        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
//            if (chessboard[i][j] == 'Q') {
//                return false;
//            }
//        }
//        return true;
//    }
//public:
//    vector<vector<string>> solveNQueens(int n) {
//        result.clear();
//        std::vector<std::string> chessboard(n, std::string(n, '.'));
//        backtracking(n, 0, chessboard);
//        return result;
//    }
//};
//2.编写一个程序，通过填充空格来解决数独问题。
//数独的解法需 遵循如下规则：
//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//数独部分空格内已填入了数字，空白格用 '.' 表示。
//class Solution {
//private:
//    bool backtracking(vector<vector<char>>& board, int row) {
//        for (int i = 0; i < board.size(); i++) {        // 遍历行
//            for (int j = 0; j < board[0].size(); j++) { // 遍历列
//                if (board[i][j] == '.') {
//                    for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
//                        if (isValid(i, j, k, board)) {
//                            board[i][j] = k;                // 放置k
//                            if (backtracking(board)) return true; // 如果找到合适一组立刻返回
//                            board[i][j] = '.';              // 回溯，撤销k
//                        }
//                    }
//                    return false;  // 9个数都试完了，都不行，那么就返回false
//                }
//            }
//        }
//        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
//    }
//    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
//        for (int i = 0; i < 9; i++) { // 判断行里是否重复
//            if (board[row][i] == val) {
//                return false;
//            }
//        }
//        for (int j = 0; j < 9; j++) { // 判断列里是否重复
//            if (board[j][col] == val) {
//                return false;
//            }
//        }
//        int startRow = (row / 3) * 3;
//        int startCol = (col / 3) * 3;
//        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
//            for (int j = startCol; j < startCol + 3; j++) {
//                if (board[i][j] == val) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        backtracking(board);
//    }
//};
