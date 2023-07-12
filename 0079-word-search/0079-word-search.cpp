class Solution {
public:
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        
//         for(int i =0; i < board.size(); i++) {
           
//             for(int j=0; j<board[0].size(); j++) {
//                 if(word[0] == board[i][j] &&  allDir(i,j,0,vis,word,board)) 
//                     return true;
                    
                
              
//             }
//         }
//         return false;
//     }
    
//     private : 
//     bool allDir(int i, int j, int  k ,vector<vector<int>> vis, string word ,vector<vector<char>>& board ) {
//          if(k == word.length()) return true;
//         if(i < 0 || j <0 || i >= board.size() || j >=board[0].size() || word[k] != board[i][j] || vis[i][j] ==1) return false;
//         board[i][j] = '*';
       
//         //cout << board[i][j];
//      bool flag = allDir(i+1, j, k+1, vis, word, board) || allDir(i-1, j, k+1, vis, word, board) || allDir(i, j+1, k+1, vis, word, board) 
//             || allDir(i, j-1, k+1, vis, word, board);
//         board[i][j] = word[k];
//         return flag;
        
//     }
    
       bool dfs(int i, int j,vector<vector<char>>& a, string word, int index, int n, int m ) {
        if(index == word.size()) {return true;}
        if(i < 0 || i>= n || j<0|| j>=m || a[i][j] != word[index]) return false ;
         int temp = a[i][j];
        a[i][j] = '*';
        bool  result = dfs(i+1,j,a,word,index+1,n,m) ||
                     dfs(i,j+1,a,word,index+1,n,m)||
                     dfs(i,j-1,a,word,index+1,n,m)||
                     dfs(i-1,j,a,word,index+1,n,m);
        
        a[i][j]=temp;
    return result;
    
    }
    
    bool exist(vector<vector<char>>& a, string word) {
        int n = a.size(), m =a[0].size();
        for(int i= 0; i<n ;i++) {
            for(int j =0; j<m ; j++) {
                
                if(dfs(i,j, a,word,0,n,m)) {
                    return true;
                }
            }
        }
        return false;
    }
};