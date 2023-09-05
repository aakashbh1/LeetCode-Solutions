class Solution {
  public:
    int maxBoxes(int N, int K, int C, int col[]) {
        int fans = 0;
            for (int i = 0; i + 1 < N; i++)
                if (col[i] == C && col[i + 1] == C) {
                    // i and i + 1 is my centre
                    int ind = i + 2;
                    int beg = i - 1;
                    int ans = 2;
                    while (ind < N && beg >= 0 && col[ind] == col[beg]) {
                        int cnt = 2;
                        ind++;
                        beg--;
    
                        if (ind < N && col[ind] == col[ind - 1]) ind++, cnt++;
                        if (beg >= 0 && col[beg] == col[beg + 1]) beg--, cnt++;
    
                        if (cnt >= 3)
                            ans += cnt;
                        else
                            break;
                    }
                    fans = max(fans, ans);
                }
        return fans;
    }
};
