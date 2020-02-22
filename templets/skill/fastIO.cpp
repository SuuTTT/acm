#define siz 10000000
char buf[siz], *bit = buf;

inline int nextInt(void) {
	register int ret = 0;
	register int neg = false;
	
	for (; *bit < '0'; ++bit)
		if (*bit == '-')neg ^= true;
	
	for (; *bit >= '0'; ++bit)
		ret = ret * 10 + *bit - '0';
	
	return neg ? -ret : ret;
}
signed main(void) {
	fread(buf, 1, siz, stdin);
}

/* 
    no fread
    
 */

inline int next(void) {
	register int ret = 0;
	register int neg = false;
	register int bit = getchar();
	for (; bit < '0'; bit = getchar())
		if (bit == '-')neg ^= true;
	for (; bit >= '0'; bit = getchar())
		ret = ret * 10 + bit - '0';
	return neg ? -ret : ret;
}