class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> result;
        string prefijo = "";
        
        for (int i = 0; i < searchWord.size(); ++i) {
            prefijo += searchWord[i]; 
            vector<string> s;
            
            for (int j = 0; j < products.size(); ++j) {
                if (products[j].find(prefijo) == 0) {
                    s.push_back(products[j]);
                    if (s.size() == 3) break;
                }
            }
            result.push_back(s);
        }
        
        return result;
    }
};
