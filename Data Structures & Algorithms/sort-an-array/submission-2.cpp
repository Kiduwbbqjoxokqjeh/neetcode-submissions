class Solution {
public:
    void merge(vector<int> &v,int l,int m,int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        int *a1 = new int[n1];
        int *a2 = new int[n2];
        for(int i=0;i<n1;i++)
        {
            a1[i] = v[l+i];
        }
        for(int i=0;i<n2;i++)
        {
            a2[i] = v[m+1+i];
        }
        int i=0,j=0,k=l;
        while(i<n1 and j<n2)
        {
            if(a1[i] <= a2[j])
            {
                v[k] = a1[i];
                i++;k++;
            }
            else
            {
                v[k] = a2[j];
                j++;k++;
            }
        }
        while(i<n1)
        {
            v[k] = a1[i];i++;k++;
        }
        while(j<n2)
        {
            v[k] = a2[j];j++;k++;
        }
        delete [] a1;
        delete [] a2;
    }
    void mergesort(vector<int> &v,int l,int r)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergesort(v,l,mid);
            mergesort(v,mid+1,r);
            merge(v,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};