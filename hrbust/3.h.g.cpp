#include <iostream>
using namespace std;
int main(){
	int n, a[105][105] = {0}, i, j, tmp;
	cin >> n;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			cin >> a[i][j];
	int sum_peo = 0, sum_car;
	for(i = 1; i <= n; i ++)
		sum_peo += a[1][i];
	
	sum_car = sum_peo / 36;
	sum_peo -= sum_car * 36;
	if(sum_peo > 0)
		sum_car += 1;

	for(i = 2; i <= n; i ++){
		for(j = 1; j <= n; j++){
			tmp = j;
			while(tmp--){
				sum_peo -= a[tmp][j];	
			}
			sum_peo += a[i][j];
		}
		tmp = sum_peo / 36;
		if (sum_peo % 36 !=  0)
			tmp ++;
		if(tmp > sum_car)
			sum_car = tmp;
	}
	cout << sum_car <<endl;
}