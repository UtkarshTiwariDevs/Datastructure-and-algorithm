#include <iostream>
using namespace std;

//permutation
void permutations(string s,string ans)
{
    if (s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    for(int i=0;i<s.length();i++){
        char ch=s[i];
        string ros=s.substr(0,i) + s.substr(i+1);
        permutations(ros,ans +ch);
    }
}
//count path
int countpath(int s,int e)
{
    if(s==e)
        return 1;
    if(s>e)
        return 0;

    int count = 0;
    for(int i=1;i<=6;i++)
        count+=countpath(s+i,e);
    return count;
}

//count path maze
int countPathMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n)
        return 0;
    return (countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1));
}
int main()
{
    
    cout<<countPathMaze(9,0,0);
    cout<<endl;
    return 0;
}