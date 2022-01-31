const int p = 31;
const int m = 1e9 + 9;
ll compute_hash(string const& s) {

	ll hash_value = 0;
	ll p_pow = 1;
	for (char ch : s) {
		hash_value = (hash_value + (ch - 'a' + 1) * 1LL * p_pow) % m;
		p_pow = (p_pow * 1LL * p) % m;
	}
	return hash_value;
}
