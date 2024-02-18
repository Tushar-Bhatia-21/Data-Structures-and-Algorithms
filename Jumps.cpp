/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void jump(int k, int arr[],int n)
{
    if(k==0)
    {
        cout<<"No Jumps atp"<<endl;
    
        return;
    }
    int i=0;
    for(i=0;i<n;i++)
    {
        if(i+arr[i]>=n-1)
        {
         cout<<"Reached @  "<<i<<endl;
         return;
    }    
        int maxJump=i+1;
        int maxReach=i+arr[i];
        for(int j=i+1;j<=maxReach;j++)
        {
            if(j+arr[j]>maxJump+arr[maxJump])
            {
                maxJump=j;
            }
        }
        i=maxJump;
        cout<<"Jumped at:"<<i<<endl;

         if (i == k) {
            cout << "Reached position " << k << endl;
            return;
         }
    }
    cout<<"Could not reach end"<<endl;
}

int main()
{
    int n=0;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[n];
    }
    int k=0;
    cin>>k;
    jump(k,arr,n);
    return 0;
}
