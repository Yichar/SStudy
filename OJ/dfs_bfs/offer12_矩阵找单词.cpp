class Solution {
public:
    int dir[4][2] = {0,1,1,0,0,-1,-1,0}; 
   
    int func(vector<vector<char>> &board,int x, int y,string word,int k){
        int n = board.size();
        int m = board[0].size();
        if(k == word.size() - 1) {
            return 0;
        }

        board[x][y] = '*';
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if( xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] != word[k+1] || board[xx][yy] == '*')
                continue;
            if(func(board,xx,yy,word,k+1) == 0)
                return 0;
        }
        board[x][y] = word[k];
        return -1;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        int n = board.size();
        int m = board[0].size();
        if(n * m < word.size()) 
                return false;
        
        for( int i = 0 ; i < n; i++){
            for( int j = 0; j < m; j++){
                if(board[i][j] == word[0]) {
                    if(func(board,i,j,word,0) == 0)
                        return true;
                }
            }
        }
        
       return false;
    }
        
};