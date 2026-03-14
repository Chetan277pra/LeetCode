class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1) return target[0] == 1;
        long long  totsum = accumulate(target.begin() , target.end() ,0ll);
        priority_queue<int> pq(target.begin() , target.end());
        while(pq.top() > 1){
            long long upar = pq.top();
            pq.pop();
            if(totsum - upar == 1) return true;
            totsum -= upar;
            if(upar <= totsum) return false;
            long long addkarna =  upar%totsum;
            // cout<<"tot: "<<totsum<<"  adk : "<<addkarna<<"\n";
            totsum += addkarna;
            if(addkarna < 1) return false;
            pq.push(addkarna);
            priority_queue<int> temp = pq;
            // while(!temp.empty()){
            //     int a = temp.top(); temp.pop();
            //     cout<<a<<" ";
            // }
            // cout<<endl;
        }
        if(pq.top() != 1) return false;
        return true;
    }
};