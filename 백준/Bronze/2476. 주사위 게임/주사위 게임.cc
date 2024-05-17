#include<iostream>;
#include<vector>;
#include<algorithm>;

using namespace std;

int main() {
	int n, ans;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {

		int arr[3];
		int num = 0, cnt = 0, reward = 0;
		cin >> arr[0] >> arr[1] >> arr[2];

		for (int j = 0; j < 3; j++) {

			int tmp = 0;
			for (int k = 0; k < 3; k++) {

				if (arr[j] == arr[k]) tmp++;
			}

			if (tmp > cnt) {

				cnt = tmp;
				num = arr[j];
			}

			if (cnt == 1) {

				for (int k = 0; k < 3; k++) {

					if (arr[j] > num) num = arr[j];
				}
			}
		}

		if (cnt == 3) reward = 10000 + (num * 1000);
		else if (cnt == 2) reward = 1000 + (num * 100);
		else reward = num * 100;

		v.push_back(reward);
	}

	ans = *max_element(v.begin(), v.end());

	cout << ans << "\n";
}