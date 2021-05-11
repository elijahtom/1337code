class Solution {
public:
    vector<int> sumZero(int n) {
        int middle = n/2;
        int offset = 0;
        vector<int> unique(n,0);

        if(n%2 == 0){
            middle--;
            while(middle + offset +1 < n){
                unique[middle - offset] = -1*(offset+1);
                unique[middle+ 1 + offset] = offset+1;
                offset++;
            }
        }

        else{
            offset++;
            while(middle+offset < n){
                unique[middle-offset] = -1*offset;
                unique[middle+offset] = offset;
                offset++;
            }
        }
        return unique;
    }
};