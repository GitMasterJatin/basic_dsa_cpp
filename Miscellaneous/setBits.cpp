class Solution {
  public:
    int setBits(int N) {
        int cnt = 0;
        while( N ){
            cnt++;
            N = N&(N-1);
        }
        return cnt;
    }
};

---------------------------------------------------------------------------
// One Liner Using C++ Powers
  
class Solution {
  public:
    int setBits(int N) {
        return __builtin_popcount(N);
    }
};
