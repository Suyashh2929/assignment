   
    //valid parenthesis

bool isValid(string s) {
        stack<char>st;
        int flag=0;
        if(s.length()==1){
            flag=1;
        }
        else{
            for(int i=0;i<s.length();i++){
                if((st.empty() || (st.top()=='('||st.top()=='{'||st.top()=='['))&&(s[i]=='{'||s[i]=='('||s[i]=='[')){
                    st.push(s[i]);
                }
                else if(st.empty()&&(s[i]==')'||s[i]==']'||s[i]=='}')){
                    flag=1;
                    break;
                }
                else if((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')||(st.top()=='['&&s[i]==']')){
                    st.pop();
                }
                else if((st.top()=='('&&s[i]!='}')||(st.top()=='{'&&s[i]!='}')||(st.top()=='['&&s[i]!=']')){
                    flag=1;
                    break;
                }
            }

        }

            if(st.empty()&& flag==0){
                return true;
            }
            else{
                return false;
            }
        }


////////////////////////////////////////////////////////////////////////////////////////////////
        
        //next greater element to the left

void nextGreaterElementLeft(vector<int> &vec){
int size = vec.size();

stack s;
vector <int>ans;
for(int i = 0; i &l; size; i++){
	if(s.empty()){
      	s.push(vec[i]);
    	ans.push_back(-1);
    } else if(s.top() &gt; vec[i]){
        ans.push_back(s.top());
        s.push(vec[i]);
    }else{
    	while(!s.empty()){
        	if(s.top() &gt; vec[i]){
              	ans.push_back(s.top());
        		s.push(vec[i]);
              	break;
            }
          	s.pop();
        }
      	if(s.empty()){
          	s.push(vec[i]);
        	ans.push_back(-1);
        }
    }
}

vec = ans;

}

///////////////////////////////////////////////////////////////////////////////////////////////

//next greater element to the right
vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long>v;
    stack<long long>s;
        
        for(int i=n-1; i>=0; i--){
            if(s.size()==0)
            {
              v.push_back(-1);  
            }
            else if(s.size()>0 && s.top()>arr[i])
            {
                v.push_back(s.top());
            }
            else if(s.size()>0 && s.top()<=arr[i])
            {
                while(s.size()>0 && s.top()<=arr[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(s.top());
                }
            }
            s.push(arr[i]);
        }
        reverse(v.begin(),v.end());
        
        return v;
}

//////////////////////////////////////////////////////////////////////////////////////////////

//next smaller element to the left

vector<int> nextSmallestElementToLeft(int n, int a[]){
    
    vector<int>res;
    stack<int> s;
    s.push(-1);
    
    for(int i=0; i<n; i++)
    {
        while(s.top()>=a[i] && s.top()!=-1)
            s.pop();
        res.push_back(s.top());
        s.push(a[i]);
    }
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////

//next smaller element to the right

vector<int> nextSmallestElementToRight(vector<int> arr, int n) 
{ 
 vector<int> ans(n,-1);
 stack<int> st;
 st.push(-1);
 for(int i=n-1;i>=0;i--)
 {
  while(st.top()>=arr[i])
      st.pop();
  ans[i]=st.top();
  st.push(arr[i]);
 }
  return ans;
}
