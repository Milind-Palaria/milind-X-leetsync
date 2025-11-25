class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num=1; 
        if(num==1 && k==1) return 1;
        int len=0;
        for(int i=0;i<=k;i++){
            len++;
            num = (num*10+1)%k;
            if(num%k==0) return len+1;
        }
        return -1;
    }
};