
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> list;

        int n = matrix.size();
        int m = matrix[0].size();

        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = m - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {

     
            for (int col = colStart; col <= colEnd; col++) {
                list.push_back(matrix[rowStart][col]);
            }
            rowStart++;


            for (int row = rowStart; row <= rowEnd; row++) {
                list.push_back(matrix[row][colEnd]);
            }
            colEnd--;


            if (rowStart <= rowEnd) {
                for (int col = colEnd; col >= colStart; col--) {
                    list.push_back(matrix[rowEnd][col]);
                }
                rowEnd--;
            }

            if (colStart <= colEnd) {
                for (int row = rowEnd; row >= rowStart; row--) {
                    list.push_back(matrix[row][colStart]);
                }
                colStart++;
            }
        }

        return list;
    }
};
