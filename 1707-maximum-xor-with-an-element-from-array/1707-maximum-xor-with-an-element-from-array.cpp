class Node{
    public:
    Node* a[2];
    Node(){
        a[0] = a[1] = NULL;
    }
    void insert(Node* root,int num){
        Node* temp = root;
        for(int i=30;i>=0;i--){
            int idx = ((num>>i)&1);
            if(temp->a[idx]==NULL){
                temp->a[idx] = new Node();
            }
            temp = temp->a[idx];
        }
    }
    int get(Node* root, int num){
        int res = 0;
        Node* temp = root;
        for(int i=30;i>=0;i--){
            int idx = ((num>>i)&1);
            if(temp->a[idx^1]!=NULL){
                res |= (1<<i);
                temp = temp->a[idx^1];
            }
            else if(temp->a[idx]!=NULL){
                temp = temp->a[idx]; 
            }
            else return -1;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        Node* root = new Node();
        int n = arr.size();
        Node tri;
        sort(arr.begin(),arr.end());
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(), q.end());
        vector<int> ans(q.size());
        int j = 0;
        for(auto x:q){
            int i = x[2];
            int limit = x[0];
            int num = x[1];
            while(j<n&&arr[j]<=limit){
                tri.insert(root, arr[j]);
                j++;
            }
            int cur = tri.get(root, num);
            ans[i] = cur;
        }
        return ans;
    }
};