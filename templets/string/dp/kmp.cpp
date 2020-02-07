/* 
前缀函数$\pi$(prefix function): $\pi[i]$代表子串$s[0 \dots i]$与其后缀相等的最长真前缀（proper prefix，即不包含本身的前缀）。
$$
\pi[i] = \max_ {k = 0 \dots i} \{k : s[0 \dots k-1] = s[i-(k-1) \dots i] \}
$$
"aabaaab" - $[0, 1, 0, 1, 2, 2, 3]$.

$O(n)$，在线
 */
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
