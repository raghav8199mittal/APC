double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()>B.size())return findMedianSortedArrays(B,A);
    
    int a = A.size();
    int b = B.size();
    
    int low =0;
    int high = a;
    
    while(low<=high)
    {
        int partA = (low+high)/2;
        int partB = (a+b+1)/2-partA;
        
        int endLeftA = (partA==0)?INT_MIN:A[partA-1];
        int startRightA = (partA==a)?INT_MAX:A[partA];
        
        int endLeftB = (partB==0)?INT_MIN:B[partB-1];
        int startRightB = (partB==b)?INT_MAX:B[partB];
        
        
        if(endLeftA<=startRightB && endLeftB<=startRightA)
        {
            if((a+b)%2==0)
                return  (double)(max(endLeftA,endLeftB)+min(startRightA,startRightB))/2;
            else
                return (double)(max(endLeftA,endLeftB));
        }
        else if(endLeftA>startRightB)
        {
            high = partA-1;
        }
        else if(endLeftB>startRightA)
        {
            low = partA+1;
        }
    }
}