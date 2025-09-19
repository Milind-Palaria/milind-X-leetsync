class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows+1,vector<int>(26,0));
    }
    pair<int,int> location(string cell){
        int y = cell[0]-'A';
        int x=0;
        int i=1,n=cell.size();
        while(i<n){
            x*=10;
            x+=(cell[i]-'0');
            i++;
        }
        return {x,y};
    }
    void setCell(string cell, int value) {
        auto temp = location(cell);
        int x = temp.first;
        int y = temp.second;
        sheet[x][y] = value;
    }
    
    void resetCell(string cell) {
        auto temp = location(cell);
        int x = temp.first;
        int y = temp.second;
        sheet[x][y] = 0;
    }
    
    int getValue(string formula) {
        string s;
        int ans=0;
        int i=1;
        while(formula[i]!='+'){
            s+=formula[i];
            i++;
        }
        i++;
        if(s[0]>='A'){
            auto temp = location(s);
            int x = temp.first;
            int y = temp.second;
            ans+=sheet[x][y];
        }
        else {
            ans+=stoi(s);
        }

        string t;
        while(i<formula.size()){
            t+=formula[i];
            i++;
        }
        if(t[0]>='A'){
            auto temp = location(t);
            int x = temp.first;
            int y = temp.second;
            ans+=sheet[x][y];
        }
        else {
            ans+=stoi(t);
        }
        return ans;
    }
};
