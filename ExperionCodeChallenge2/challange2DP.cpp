/*compiler requirement C++14 */
#include<bits/stdc++.h>
using namespace std;
int intarray[100], cn[100],m,n,cm[100],minmc=9999,arrayx[20],finalcost = 0,finalmincost = 99999999,minpos [100][100];
void findposmask(int type ,int mask )
{  int i,mincost=9999,k =0;
   if(type == m){return;}i= arrayx[type];
   for(int start = 0; start < n-(cn[i]-1);start+=minmc)
   {   int cost = 0;
       for(int j = start;j<start+cn[i];j++)
       { if(intarray[j]-(i+1) !=0){cost++;}}
       if((cost<mincost) )
       {   k=0;minpos[i][k] = 0;mincost = cost;
           for(int y=0;y<(cn[i]);y++)
           {minpos[i][k] = minpos[i][k]^(1<<((y+start)));} }
       else if((cost==mincost))
       {   k++;minpos[i][k] = 0;
           for(int y=0;y<(cn[i]);y++)
                { minpos[i][k] = minpos[i][k]^(1<<((y+start)));}}}
    if(k==0 && (mask&minpos[i][0]))
    { mincost =1;
      for(int h = 0; h<n;h++)
      {minpos[i][h] = h;}}
      for(int q =0 ; q< k+1 ;q++)
            { if (mask&minpos[i][q]){continue;}
                finalcost += mincost;
                if(type == m-1){finalmincost = min(finalmincost,finalcost);}
                findposmask(type+1 ,(mask ^((minpos[i][q]))));
                finalcost -= mincost; }}
int main()
{   cin>>n>>m;
    for(int i = 0; i < n; ++i) {
       arrayx[i] = i; cin >> intarray[i]; ++cn[intarray[i]-1]; ++cm[intarray[i]-1];}
	if(n<3){cout<<0;return 0;}
    for (int c = 0 ; c < m ; c++)
    {   if (cn[c]<minmc ){ minmc = cn[c];}
        for (int d = 0 ; d < m - c - 1; d++)
        {    if (cm[d] < cm[d+1])
            { int temp = arrayx[d]; arrayx[d] = arrayx[d+1];arrayx[d+1] = temp;
              int swap = cm[d];cm[d] = cm[d+1];cm[d+1] = swap;}}}
findposmask(0,0);
cout<<(finalmincost==99999999?0:finalmincost);
}


