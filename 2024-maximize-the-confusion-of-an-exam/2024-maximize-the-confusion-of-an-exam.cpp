class Solution {
public:
    int maxt(char a, string ans, int k) {
        int offense = k;
        int rans = INT_MIN, count =0;
        queue<int> qu;
        for(int i=0; i< ans.size() ; i++) {
            if(ans[i] == a) {
                count++;
            } else if( offense >0) {
                qu.push(i);
                offense--;
                count++;
            } else {
                qu.push(i);
                rans = max(rans, count);
                // offense = k;
               // count =0;
//                 while( i>=0 && (offense >0 || ans[i] == a)  ) {
//                     if(ans[i]!= a) offense--;
                    
//                     i--;
//                 }
                //offense = k;
                int j = qu.front()+1;
                qu.pop();
                count = i-j+1;
                rans = max(rans,count);
                
                
            }
           // cout << count << "\n";
        }
        rans = max(rans, count);
        return rans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max( maxt('T',answerKey,k), maxt('F',answerKey,k));
    }
};