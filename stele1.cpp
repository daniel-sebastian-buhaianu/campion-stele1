#include <fstream>
#define KMAX 60000
using namespace std;
int main()
{
	ifstream f("stele1.in");
	int K, N;
	f >> K >> N;
	f.close();
	long long a[KMAX+1];
	a[1] = 1;
	int col = a[1] < N ? 1 : 0;
	int i;
	for (i = 2; i <= K; i++)
	{
		a[i] = a[i-1] + 2*(i-1);
		if (a[i]+i-1 < N) col = i;
	}
	col++;
	for (i = K+1; a[i-1]+i-2 < N; i++)
		a[i] = a[i-1] + 2*(i-1);
	if (i > K+1) col = i-1;
	long long rand = 1, x = a[col]+col-1;
	while (x > N) rand++, x--;
	ofstream g("stele1.out");
	g << a[K] << '\n';
	g << col << ' ' << rand;
	g.close();
	return 0;
}

