class Solution {
public:
    int part(vector<int> &v,int l,int r)
    {
        int pivot = v[r];
        int i=l;
        for(int j=l;j<r;j++)
        {
            if(v[j] <= pivot) 
            {
                swap(v[i],v[j]);i++;
            }
        }
        swap(v[i],v[r]);
        return i;
    }
    void quicksort(vector<int> &v,int l,int r)
    {
        if(l>=r) return;
        int p = part(v,l,r);
        quicksort(v,l,p-1);
        quicksort(v,p+1,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
        
    }
};