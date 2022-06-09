#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int > st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.push(ele);
    insertAtBottom(st,ele);

    st.push(topele);
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}

int main()
{

    return 0;
}