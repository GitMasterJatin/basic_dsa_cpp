class Solution{
    public:
    bool isPowerofFour(long long n){
        bool condition1 = (n & (n - 1)) == 0;
        bool condition2 = n % 3 == 1;
        return condition1 && condition2;
    }
};
