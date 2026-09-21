class Solution {
public:
    int search(vector<int>& A, int key) {
        
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        // Complete this function
        int l=0;
        int h=A.size()-1;
        int  r=h;
        while(l<=r ){
            int mid=(l+r)/2;
            if(A[mid]==key )return mid;
            if(A[l]<=A[mid]){
                if(A[l]<=key && A[mid]>=key){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(A[mid]<=key && A[r]>=key){
                   l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }

};