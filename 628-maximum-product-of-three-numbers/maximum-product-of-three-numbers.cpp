class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int largest=INT_MIN;
        int slargest=INT_MIN;
        int tlargest=INT_MIN;

        int smallest=INT_MAX;
        int ssmallest=INT_MAX;
        for(int x: nums){
            if (x >= largest) {
                tlargest = slargest;
                slargest = largest;
                largest = x;
            }
            else if (x >= slargest) {
                tlargest = slargest;
                slargest = x;
            }
            else if (x > tlargest) {
                tlargest = x;
            }
            if (x <= smallest) {
                ssmallest = smallest;
                smallest = x;
            }
            else if (x < ssmallest) {
                ssmallest = x;
            }
        }
        
        return max(largest*slargest*tlargest,largest*smallest*ssmallest);
    }
};