*/     			Name : Mehul butta 
			Chitkara Institute of Engineering And Technology, Punjab
			
			this gives incorrect answer for only one test case*/

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>>n;
    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    
    for(int i=1;i<n;i++){
        prices[i]+= prices[i-1];
    }
    
    
    int d;
    cin>>d;
    while(d>0){
        int money;
        cin>>money;
        int ans1 =0 , ans2 = 0;
        int l =0, r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(prices[mid]  <= money  ){
                ans2 = money - prices[mid];
                ans1 = mid+1;
                l = ans1;
            }
            
            else
                r = mid -1;
            
        }
        
        if(prices[0] > money)
            ans2 = money;
        
        cout<<ans1<<" "<<ans2<<endl;
        
        d--;
    }
    
    return 0;
}





*/
		
			Name: Bhavya Tyagi
			Thapar Institute of Engineering & Technology, Patiala


				PROBLEM STATEMENT
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she 
manages to save some money out of it daily. After buying vegetables, she goes to 
"Momos Market", where there are ‘n’ number of shops of momos. Each of the shop of
momos has a rate per momo. She visits the market and starts buying momos (one from 
each shop) starting from the first shop. She will visit the market for ‘q’ days.
You have to tell that how many momos she can buy at each day if she starts buying 
from the first shop daily. She cannot use the remaining money of one day on some other 
day. But she will save them for other expenses in future, so, 
you also need to tell the sum of money left with her at the end of each day.
*/

	//This Code gives TLE for only 1 test case
	
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void momos(vector<ll> a,ll n,vector<ll> b,ll q)
{
    ll p=q,j=0;
    while(p--&&j<q)
    {
        ll moneyForDay=b[j],moneyLeft,count=0;
        for(ll i=0;i<n;i++)
    	{
            if(moneyForDay<a[i])
            {
               
                moneyLeft=moneyForDay;
                 break;
            }
        	moneyForDay=moneyForDay-a[i];
            count++;
   		}
        cout<<count<<" "<<moneyLeft<<endl;;
        j++;
    }
}
int main()
{
    ll n;
    vector<ll> a,b;
    cin>>n;
    ll m=n;
	while(m--)
    {
        ll input;
        cin>>input;
        a.push_back(input);
    }
    ll q;
    cin>>q;
    ll p=q;
    while(p--)
    {
        ll days;
        cin>>days;
        b.push_back(days);
    }
    
    momos(a,n,b,q);
	return 0;
}













//Code By the Original Author - Time-Limit-Exceeded for 3 testcases
/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she 
manages to save some money out of it daily. After buying vegetables, she goes to 
"Momos Market", where there are ‘n’ number of shops of momos. Each of the shop of
momos has a rate per momo. She visits the market and starts buying momos (one from 
each shop) starting from the first shop. She will visit the market for ‘q’ days.
You have to tell that how many momos she can buy at each day if she starts buying 
from the first shop daily. She cannot use the remaining money of one day on some other 
day. But she will save them for other expenses in future, so, 
you also need to tell the sum of money left with her at the end of each day.
*/

#include <bits/stdc++.h>

using namespace std;
pair<int, int> go(vector<int> sum, int q){
	//cout << "q "<<q << '\n';
	
	//Getting just greater index
	int pos = lower_bound(sum.begin(), sum.end(), q)-sum.begin();
	if (pos>sum.size()-1)
	{
		pos--;
	}
	if (sum.at(pos) > q)
	{
		pos--;
	}
	//cout << "Position "<< pos << '\n';
	
	if (pos<0)
	{
		int momos = 0;
		int money_left = q;
		return make_pair(momos, money_left);	
	}
	

	int momos = pos+1;
	int money_left = q-sum.at(pos);
	return make_pair(momos, money_left);

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	std::vector<int> v;
	std::vector<int> sum;
	int temp_sum = 0;

	while(n--){
		int a;
		cin>>a;
		v.push_back(a);
		temp_sum+=a;
		sum.push_back(temp_sum);
	}

	int q;
	cin>>q;
	while(q--){
	int total_money;
	cin>>total_money;
	
	pair<int, int> ans = make_pair(0,0);
	ans = go(sum, total_money);

	cout << ans.first<<" "<< ans.second << '\n';
	
	}

	return 0 ; 



}
