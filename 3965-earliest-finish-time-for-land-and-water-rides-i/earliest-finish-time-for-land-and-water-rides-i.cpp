class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        for(int i = 0; i < n; i++)
        landDuration[i] += landStartTime[i];
        int m = waterStartTime.size();
        for(int i = 0; i < m; i++)
        waterDuration[i] += waterStartTime[i];
        int mini = INT_MAX;
        // first 
        // take shortest in first and so calculate the refrence with second
        int firstmini = INT_MAX;
        int ind1 = -1;
        for(int i = 0; i < n; i++){
            if(landDuration[i] < firstmini){
                firstmini = landDuration[i];
                ind1 = i;
            }
        }
        // now we have first mini thign;
        vector<int> temp(m);
        temp = waterDuration;
        for(int i = 0; i < m; i++){
            temp[i] += max( 0 , landDuration[ind1] - waterStartTime[i]);
        }
        sort(temp.begin() , temp.end());
        int curra = temp.front();
        // cout<<ind1<<" "<<curra;
        // now second

        int secondmini = INT_MAX;
        int ind2 = -1;
        for(int i = 0; i < m; i++){
            if(waterDuration[i] < secondmini){
                secondmini = waterDuration[i];
                ind2 = i;
            }
        }
        // now we have first mini thign;
        // cout<<endl;
        temp.resize(n , 0);
        temp = landDuration;
        // for(auto a : temp) cout<<a<<" ";
        // cout<<endl;
        // cout <<  waterDuration[ind1];
        for(int i = 0; i < n; i++){
            temp[i] += max( 0 , waterDuration[ind2] - landStartTime[i]);
        }
        sort(temp.begin() , temp.end());
        int currb = temp.front();
        cout<<endl;
        cout<<ind2<<" "<<currb;

         mini = min(curra , currb);
         return mini;
    }
};