class Solution {
public:
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int l =0, r= matrix.size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            cout << matrix[mid][0] <<" ";
            if(matrix[mid][0] == target) return true;
            else if (target > matrix[mid][0]) l = mid+1;
            else  r= mid-1;
        }
        cout <<"{"<< l<<"}";
        l--;
        if(l<0) return false;
        int k =0, j = matrix[0].size()-1;
        while(k<=j) {
            int mid = k + (j-k)/2;
            cout << matrix[l][mid] <<" ";
            if(matrix[l][mid] == target) return true;
            else if (target > matrix[l][mid]) k = mid+1;
            else j= mid-1;
        }
        return false;
        
    }
};