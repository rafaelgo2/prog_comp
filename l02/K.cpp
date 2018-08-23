#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

#define MAXN (1<<18)

const int MAX = MAXN;

//COPIADO DA INTERNET

template<typename T> class cmplx {
private:
	T x, y;
public:
	cmplx () : x(0.0), y(0.0) {}
	cmplx (T a) : x(a), y(0.0) {}
	cmplx (T a, T b) : x(a), y(b) {}
	T get_real() { return this->x; }
	T get_img() { return this->y; }
	cmplx conj() { return cmplx(this->x, -(this->y)); }
	cmplx operator = (const cmplx& a) { this->x = a.x; this->y = a.y; return *this; }
	cmplx operator + (const cmplx& b) { return cmplx(this->x + b.x, this->y + b.y); }
	cmplx operator - (const cmplx& b) { return cmplx(this->x - b.x, this->y - b.y); }
	cmplx operator * (const T& num) { return cmplx(this->x * num, this->y * num); }
	cmplx operator / (const T& num) { return cmplx(this->x / num, this->y / num); }
	cmplx operator * (const cmplx& b) { 
		return cmplx(this->x * b.x - this->y * b.y, this->y * b.x + this->x * b.y); 
	}
	cmplx operator / (const cmplx& b) {
		cmplx temp(b.x, -b.y); cmplx n = (*this) * temp;
		return n / (b.x * b.x + b.y * b.y);
	}
};

//T = int/long long as per polynomial coefficients
//S = double/long double as per precision required
template<typename T, typename S> struct FFT {
	S PI;
	int n, L, *rev, last;
	cmplx<S> ONE, ZERO;
	cmplx<S> *omega_powers;

	FFT() {
		PI = acos(-1.0);
		ONE = cmplx<S>(1.0, 0.0);
		ZERO = cmplx<S>(0.0, 0.0);
		last = -1;
		int req = 1 << (32 - __builtin_clz(MAX));
		rev = new int[req]();
		omega_powers = new cmplx<S>[req];
	}

	~FFT() {
		delete [] rev;
		delete [] omega_powers;
	}

	void ReverseBits() {
		if (n != last) {
			for (int i = 1, j = 0; i < n; ++i) {
				int bit = n >> 1;
				for (; j >= bit; bit >>= 1) j -= bit;
				j += bit;
				rev[i] = j;
			}
		}
	}
 
	void DFT(vector<cmplx<S>> &A, bool inverse = false) {
		for(int i = 0; i < n; ++i) 
			if (rev[i] > i) swap(A[i], A[rev[i]]);
		for (int s = 1; s <= L; s++) {
			int m = 1 << s, half = m / 2;
			cmplx<S> wm(cosl(2.0 * PI / m), sinl(2.0 * PI / m));
			if (inverse) wm = ONE / wm;
			omega_powers[0] = ONE;
			for(int k = 1; k < half; ++k) {
				omega_powers[k] = omega_powers[k-1] * wm;
			}
			for (int k = 0; k < n; k += m) {
				for (int j = 0; j < half; j++) {
					cmplx<S> t = omega_powers[j] * A[k + j + half];
					cmplx<S> u = A[k + j];
					A[k + j] = u + t;
					A[k + j + half] = u - t;
				}
			}
		}
		if (inverse) {
			for (int i = 0; i < n; i++) A[i] = A[i] / n;
		}
	}
 
	// c[k] = sum_{i=0}^k a[i] b[k-i]
	vector<T> multiply(const vector<T> &a, const vector<T> &b) {
		L = 0;
		int sa = a.size(), sb = b.size(), sc = sa + sb - 1;
		while ((1 << L) < sc) L++; 
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S>> aa(n, ZERO), bb(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		for (int i = 0; i < sb; ++i) bb[i] = cmplx<S>(b[i], 0);
		DFT(aa, false); DFT(bb, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * bb[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}

	// c[k] = sum_{i=0}^k a[i] a[k-i], saves one FFT call
	vector<T> multiply(const vector<T> &a) {
		L = 0;
		int sa = a.size(), sc = sa + sa - 1;
		while ((1 << L) < sc) L++; 
		n = 1 << L;
		ReverseBits();
		last = n;
		vector<cmplx<S>> aa(n, ZERO), cc;
		for (int i = 0; i < sa; ++i) aa[i] = cmplx<S>(a[i], 0);
		DFT(aa, false);
		for (int i = 0; i < n; ++i) cc.push_back(aa[i] * aa[i]);
		DFT(cc, true);
		vector<T> ans(sc);
		for (int i = 0; i < sc; ++i) ans[i] = cc[i].get_real() + 0.5;
		return ans;
	}
};

//FIM DO COPIADO DA INTERNET

typedef pair<int, int> pii;
vector<pii> seg[4];
typedef long long int lli;
typedef vector<int> vi;
vi A[4] = {vi(MAXN, 0), vi(MAXN, 0), vi(MAXN, 0), vi(MAXN, 0)};
vi B[4] = {vi(MAXN, 0), vi(MAXN, 0), vi(MAXN, 0), vi(MAXN, 0)};
vi C[4];

int conv(char c){
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
}

void fill(vi &v, vector<pii> &s){
	int r = 0;
	for (pii p : s){
		if (p.second < r) continue;
		int l = max(r, p.first);
		for (int i = l; i <= p.second; i++)
			v[i] = 1;
		r = p.second;
	}
}

void mult(vi &A, vi &B, vi &C){
	static FFT<int, double> fft;
	C = fft.multiply(A, B);
}

int main(){ _
	int S, T, k;
	string s, t;
	cin >> S >> T >> k >> s >> t;
	for (int i = 0; i < S; i++){
		int j = conv(s[i]);
		int l = max(0, i-k);
		int r = min(S-1, i+k);
		seg[j].push_back(pii(l, r));
	}
	for (int i = 0; i < 4; i++)
		fill(A[i], seg[i]);
	
	for (int i = 0; i < T; i++){
		int j = conv(t[i]);
		B[j][T-1-i] = 1;
	}

	for (int i = 0; i < 4; i++)
		mult(A[i], B[i], C[i]);
	
	int ans = 0;
	for (int i = 0; i < MAXN; i++){
		int sum = 0;
		for (int j = 0; j < 4; j++) sum += int(C[j][i]);
		ans += (sum == T);
	}
	cout << ans << endl;
	return 0;
}
