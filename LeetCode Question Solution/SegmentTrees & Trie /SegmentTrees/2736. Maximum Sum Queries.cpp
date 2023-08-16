template<class T> struct Seg {
	const T ID = 0; // change here
 	T comb(T a, T b) { return max(a,b); }//change here
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void init(vector<int> arr) { 
		n = arr.size(); seg.resize(2*n); 
		for(int i = 0; i<n;i++) seg[i+n] = arr[i];
		push();
	}
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void push() { for(int i = n-1; i > 0; i--) seg[i] = comb(seg[i<<1], seg[i<<1|1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> g;
        for(int i = 0 ; i < nums1.size(); i++) g.push_back({nums1[i], nums2[i]});
        sort(g.begin(), g.end());
        reverse(g.begin(), g.end());
        vector<pair<int, int>> p;
        int ymx = 0;
        vector<int> arr;
        for(pair<int, int> pp : g) {
            if (pp.second > ymx){
                ymx = pp.second;
                p.push_back(pp);
            }
        }
        int m = p.size();
        int x[m], y[m];
        for(int i = 0; i < m ; i++) {
            x[i] = p[i].first;
            y[i] = p[i].second;
            arr.push_back(x[i] + y[i]);    
        }
        Seg<int> st;
        st.init(arr);
        vector<int> re;
        for(vector<int>& q : queries){
            int ll =0, rr = m-1;
            while(ll < rr){
                int m = (ll+rr+1)/2;
                if (x[m] >= q[0]) ll = m;
                else rr = m-1;
            }
            int r = ll;
            if (x[r] < q[0]) r = -1; 
            int l = lower_bound(y, y+m, q[1]) - y;
            if(l > r) re.push_back(-1);
            else re.push_back(st.query(l, r));
        }
        return re;
        
    }
};
