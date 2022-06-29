class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=(n1+n2)/2+1;
        int c=0,i=0,j=0;
        double mid1,mid2;
        while(c<n && i<n1 && j<n2){
            if(c==n-2){
                mid1=min(nums1[i],nums2[j]);
            }
            if(c==n-1){
                mid2=min(nums1[i],nums2[j]);
            }
            
            if(nums1[i]<=nums2[j]){
                i++;
            }
            else{
                j++;
            }
            c++;
        }
        while(c<n && i<n1){
            if(c==n-2){
                mid1=nums1[i];
            }
            if(c==n-1){
                mid2=nums1[i];
            }
            
            i++;
            c++;
        }
        while(c<n && j<n2){
            if(c==n-2){
                mid1=nums2[j];
            }
            if(c==n-1){
                mid2=nums2[j];
            }
            
            j++;
            c++;
        }
        if((n1+n2)%2==0){
            return (double)(mid1+mid2)/2;
        }
        return (double)mid2;
    }
};