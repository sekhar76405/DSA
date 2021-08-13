#include<iostream>
#include<vector>
using namespace std;


// arr.size = 4
// dp[5][5]
// 0 to 4 but we want 1 to 4
// int i = 0 to i <arr.size() + 1

int main(){
    vector<int> arr{1,2,3,-4,5,6};
    
  vector<int> arr{5,4,-1,7,8};
    
    //int dp[arr.size() + 1][arr.size() + 1] = {};
    
          int** dp = new int*[arr.size()+ 1];
        for(size_t i = 0; i < arr.size() + 1; ++i)
            dp[i] = new int[arr.size() + 1];
        
       for(int i = 0; i<arr.size()+1; i++){
        for(int j = 0; j<arr.size()+1; j++){

           dp[i][j] = 0;
        }
        
    }
    
    int max = INT_MIN;



    for(int i = 1; i<arr.size() + 1; i++){
            dp[i][i] = dp[i-1][i-1] + arr[i - 1];

            if(max <= dp[i][i]){
                max = dp[i][i];
            }

            dp[i][i-1] = dp[i][i] - dp[i-1][i-1];

            if(max <= dp[i][i-1]){
                max = dp[i][i-1];
            }
    }

    

    
    for(int i = 1; i<arr.size() + 1; i++){
        for(int j = i-2; j>=1; j--){

            dp[i][j] = dp[j+1][j] + dp[i][j+1];

            if(max <= dp[i][j]){
                max = dp[i][j];
            }
        }
    }
  
    //return max;
    cout<<max;

    return 0;
}