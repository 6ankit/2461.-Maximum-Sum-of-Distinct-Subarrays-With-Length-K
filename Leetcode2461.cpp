class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        if(k==1)
        {
            int maxi=INT_MIN;
            for(int i=0;i<arr.size();i++)
            {
                maxi=max(maxi,arr[i]);
            }
            return maxi;
        }
       vector<long long> brr(arr.size(),0);
  brr[0]=arr[0];
  unordered_set<int> st;
  for(int i=1;i<arr.size();i++)
  {
    brr[i]=brr[i-1]+arr[i];
  }
  int i=0;
  int sum=0;
  long long ans=INT_MIN;
  int m=0;
  while(i<brr.size())
{
   if(st.find(arr[i])!=st.end())
  {
     while(m<i&&st.find(arr[i])!=st.end())
     {
      st.erase(arr[m]);
      m+=1;
     }
  }   
   else 
  {
    if(i==m+k-1)
    {
      if(m==0) ans=brr[i];
      else ans=max(brr[i]-brr[m-1],ans);
      st.erase(arr[m]);
      m+=1;
    }
  }
      st.insert(arr[i]);
      i+=1;
}
if(ans==INT_MIN) return 0;
return ans;
    }
};
