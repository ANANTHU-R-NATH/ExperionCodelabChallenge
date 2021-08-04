/* High Complexity solution 
   creates and checks all possible combinations of m 
   against orginal input to detemine mnimum K
   proper solution requires knowlege of BitMask
*/
#include <bits/stdc++.h>
using namespace std;

int counter = 0;
int intarray[100], cn[100];

int k = 99999;

void perm(int a[], int level,int m){
    int tempperm[m];
    static int flag[10] = {0};
    static int res[10];
    int changeCount = 0;
    if(a[level] == '\0'){
        res[level] = '\0';
        int x = 0;
        for(int i = 0; res[i] != '\0'; ++i){
            for(int j=1;j <= cn[res[i]-1];j++)
            {
                if(intarray[x]-res[i] != 0)
                { changeCount++;}
                x++;
            }
        }
        if(changeCount < k)
        {
        k = changeCount;
        }
        ++counter;
    }
    else{
        for(int i = 0; a[i] != '\0'; ++i){
            if(flag[i] == 0){
                res[level] = a[i];
                flag[i] = 1;
                perm(a, level + 1,m);
                flag[i] = 0;
            }
        }
    }
}

int main(){
    int n,m ;
	
    cin>>n>>m;
    
    for(int i = 0; i < n; ++i) {
        cin >> intarray[i]; 
        ++cn[intarray[i]-1];
    }
    int permInput[m];
    for (int i = 0;i<m;i++)
    {
        permInput[i] = i+1;
    }
    
    perm(permInput,0,m);
    
    cout<<k;
    return 0;
}