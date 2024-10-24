class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }


        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int camino_abajo_izq = triangle[i+1][j];     
                int camino_abajo_der = triangle[i+1][j+1];   
                triangle[i][j] += min(camino_abajo_izq, camino_abajo_der);
            }
        }
        return triangle[0][0];
    }
};