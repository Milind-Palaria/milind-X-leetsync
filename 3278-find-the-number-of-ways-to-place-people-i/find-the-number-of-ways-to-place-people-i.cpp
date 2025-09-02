class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        int ans=0;
        for(int i=0; i<points.size(); i++)
        {
            for(int j=0; j<points.size(); j++)
            {
                if((i!=j)&&(points[i][0] >= points[j][0])&&(points[i][1] <= points[j][1]))
                {
                    int flag=1;
                    cout<<points[i][0]<<points[i][1]<<"   "<<points[j][0]<<points[j][1]<<endl;
                    for(int k=0; k<points.size(); k++)
                    {
                        if((i!=k)&&(j!=k)&&(points[k][0] <= points[i][0])&&(points[k][0] >= points[j][0])&&(points[k][1] <= points[j][1])&&(points[k][1] >= points[i][1]))
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        ans++;
                    }
                }
            }
        } 
        return ans;  
    }
};