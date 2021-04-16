// bottom -up 상향식 for문
// d[n]은 d[n]부터 차례차례 거꾸로 가야된다
// d[n]=d[i]+d[n-i]은 d[i]에는 거기까지의 최대의 수+ d[n-i]는 추가되는 수까지포함..?
// ex) d[5] = d[5] 부터 초기화하지만 d[4] + d[1] 은 d[4]까지의 최고의 수이기때문에, d[2]+d[2]도 다 고려되어있다.
// ex) 즉 d[4]+d[1] ,d[3]+d[2] 이런것만 고려하면 되는 것.
// -내피셜-
//--------------------------------------------------------------------------------

//공식풀이//붕어빵 되팔기
// D[n] : n개팔아서 얻을 수 있는 최대 수익
// P[1] + D[n-1] : 마지막 사람사람에게 1개씩 팔았을 경우
// P[2] + D[n-2] : 2개씩 팔았을경우
// P[i] + D[n-i] : i개씩 팔았을 경우  (1<=i<=n)
// 붕어빵을 1개부터 n개까지  d[n]을 1칸을 체울때 1~n까지 검사해야함 따라서 1칸을 체우는 시간복잡도는 O(n)
// 따라서 n개까지 갯수를 세야하니 n*O(n) 즉 시간복잡도는 O(n^2)이다.
#include <bits/stdc++.h>
#include <algorithm>
int d[1001];  //카드 가격
int ans[1001]; //해당 카드 갯수당 최고의 숫자
int main() {
	int n;
	int tmp = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		ans[i] = d[i];
	}
	if (n != 1) {
		for (int i = 2; i <= n; i++) { //d[i]일때 가장 최고가격으로 구입하는 가격 ans[i]
			for (int j = 1; j <= i; j++) { //1은 항상 한가지가 최고의 수
				tmp = ans[j] + d[i - j];
				if (ans[i] < tmp)
					ans[i] = tmp;
			}
		}
	}/* 공식답
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(ans[i], ans[i - j] + d[j]);
		}
	}*/
	printf("%d", ans[n]);
}