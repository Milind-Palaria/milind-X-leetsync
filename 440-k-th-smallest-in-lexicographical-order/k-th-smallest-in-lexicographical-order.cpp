class Solution {
public:
int f(long cur,long next,int n)
{
    int countnum=0;
    while(cur<=n)
    {
         countnum+=(next-cur);
         cur*=10;
         next*=10;
         next=min(next,long(n+1));
    }
    return countnum;
}
    int findKthNumber(int n, int k) {
     int cur=1;
     k-=1;
     while(k>0)
     {
        int count=f(cur,cur+1,n);
        if(count<=k)
        {
            cur++;
            k-=count;
        }
        else
        {
            cur*=10;
            k-=1;
        }
     } 
     return cur;  
    }
};