#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
using namespace std;
#define REP(I,N) for(int I = 0;I<N;I++)

int  transfer[30][30];
const int numlower = 26;

const int target = 'm' - 'a' ;


int dfs(int i, int j, int t) { // t mean time,to avoid infinite loop
	t++;
	int result = 0;
	if (i == j)
		return 1;
	else if (t > numlower) return 0;
	for (int p = 0; p < numlower; p++) {
		if (transfer[i][p] != 0) {
			result += dfs(p, j, t);
			if (result > 0)
				break;
		}
	}
	return result;
}



int main() {

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	memset(transfer, 0, sizeof(transfer));

	string mantra;
	while (getline(cin, mantra)) {
		if (mantra == "0") {
			int ok;
			ok = dfs(1, target, 0);
			cout << (ok ? "Yes." : "No.") << endl;

			memset(transfer, 0, sizeof(transfer));
			continue;
		}

		// cout<<mantra<<endl;

		int end, end_letter, begin_letter;
		end = mantra.size() - 1;
		if (end < 0)
			break;

		begin_letter = tolower(mantra[0]) - 'a';
		end_letter = tolower(mantra[end]) - 'a';
		if (begin_letter != end_letter) // avoid infinite loop
			transfer[begin_letter][end_letter] = 1;
#ifdef TEST
		cout << "mantra=" << mantra << " " << begin_letter << " "
		     << end_letter << endl;
#endif
	}

	return 0;
}

