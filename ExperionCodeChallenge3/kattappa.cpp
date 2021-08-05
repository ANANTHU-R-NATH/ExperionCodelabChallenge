#include<bits/stdc++.h>
using namespace std;
int main()
{int n,even =0;
cin>>n;
for(int j,i=0;i<n;i++)
{cin>>j;if(!(j&1)){++even;}}
cout<<((even>(n >> 1))?"READY FOR BATTLE ":"NOT READY ");
return 0;}

/* assuming 0 is even ,bahubali with his {2} even hands as weapons
is lucky, even if he has 0 weapons, he has two hands for weapons = even number of weapons
 no soldiers = no battle */
 /*######### compiler requirement : c++14*/
