stack<int> st;
for(int i=0;i<s.length();i++){
//Opening
if(s[i]=='('){
st.push(i);
}
//Closing
else{
if(st.size()>0 and s[st.top()]=='('){
st.pop();
}
else{
// invalid index.
}
}
