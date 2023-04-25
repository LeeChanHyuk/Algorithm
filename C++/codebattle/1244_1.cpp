#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
int ans;

void ok(int cnt, string s, int a) {
	if (cnt == n) {
		int temp = stoi(s);
		if (temp > ans) ans = temp;
		return;
	}

	int sz = s.size();
	for (int i = a; i < sz-1; i++) {
		for (int j = i + 1; j < sz; j++) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			ok(cnt + 1, s, i);
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	}

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for(int t =1; t <=T; t++){
		string s;
		cin >> s >> n;
		ans = 0;
		if (n > s.size()) 	n = s.size();

		ok(0, s, 0);

		cout << "#" << t << ' ';
		cout << ans << '\n';

	}

	return 0;
}