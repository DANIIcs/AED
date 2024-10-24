class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        if (numRows == 0) {
            return pascalTriangle;
        }

        pascalTriangle.push_back({1});

        for (int i = 1; i < numRows; i++) {
            vector<int> newR = {1};

            for (int j = 1; j < i; j++) {
                int value = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
                newR.push_back(value);
            }

            newR.push_back(1);

            pascalTriangle.push_back(newR);
        }

        return pascalTriangle;
    }
};