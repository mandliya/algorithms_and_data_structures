using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	   cin>>s;
	    
	    string str="";
	    int i=1;
	    stack<int> st;
	    for(int j=0;j<s.length();j++){
	        if(s[j]=='(') {  st.push(i);str+=to_string(i);str+=" ";i++;}
	        else if(s[j]==')')  {
	            str+=to_string(st.top()) ;str+=" ";
	            st.pop();
	        }
	    }
	    //cout<<i<<endl;
	    cout<<str<<endl;
	    
	}
	return 0;
}