#include <bits/stdc++.h>
using namespace std;
int C=0;
int A[1<<20][2];
int LOWTIME(int LEFTSIDE, bool TURN, int ARRAY[],int n)
{
if(!LEFTSIDE)
return 0;
int RESULT = A[LEFTSIDE][TURN];
if (~RESULT)
return RESULT;
int RIGHTSIDE=((1<<n)-1)^LEFTSIDE;
if (TURN==1)
{
int B = INT_MAX, PEOPLE;
for (int i=0;i<n;++i)
{
C++;
if (RIGHTSIDE&(1<<i))
{
if (B>ARRAY[i])
{
PEOPLE=i;
B=ARRAY[i];
}
}
}
RESULT=ARRAY[PEOPLE]+LOWTIME(LEFTSIDE|(1<<PEOPLE),TURN^1,ARRAY,n);
}
else
{
if (__builtin_popcount(LEFTSIDE)==1)
{
for (int i=0;i<n;++i)
{
if (LEFTSIDE&(1<<i))
{
RESULT=ARRAY[i];
break;
}
}
}
else
{
RESULT=INT_MAX;
for (int i=0;i<n;++i)
{
if (!(LEFTSIDE&(1<<i)))
continue;
for(int j=i+1;j<n;++j)
{
if (LEFTSIDE&(1<<j))
{
int VALUE=max(ARRAY[i],ARRAY[j]);
VALUE += LOWTIME(LEFTSIDE^(1<<i)^(1<<j),TURN^1,ARRAY,n);
RESULT = min(RESULT,VALUE);
}
}
}
}
}
return RESULT;
}
int TOTALTIME(int ARRAY[],int n)
{
int F=(1<<n)-1;
memset(A,-1,sizeof(A));
return LOWTIME(F,0,ARRAY,n);
}
int main(void)
{
int ARRAY[]={1,2,4,10};
int n=sizeof(ARRAY)/sizeof(ARRAY[0]);
cout<<"The total time taken is : "<<TOTALTIME(ARRAY,n)<<" Minutes\n";
cout<<"Operations : "<<C;
return 0;
}
