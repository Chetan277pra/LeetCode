class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        n += 1;
        priority_queue<pair<int , char> > pq;
        int si = tasks.size();
        map<char , int > mpp;
        for(auto a : tasks){
            mpp[a]++;
        }
        for(auto a : mpp){
            pq.push({a.second , a.first});
        }
        while(!pq.empty()){
            mpp.clear();
            int temp = n;
            while(temp){
                if(pq.empty() and mpp.empty()) return ans;
                if(pq.empty() ) {
                    ans += temp;
                    break;
                }
                auto it = pq.top(); pq.pop();
                ans++;
                temp--;
                it.first--;
                cout <<it.first <<" " <<it.second<<"\n";
                if(it.first > 0) mpp[it.second] = it.first;
            }
            cout <<"bbahar"<<endl;
            // for(auto a : mpp){
            //     cout << a.first << " " <<a.second<<endl;
            // }
            for(auto a : mpp){
                pq.push({a.second , a.first});
            }
        }
        return ans;
    }
};