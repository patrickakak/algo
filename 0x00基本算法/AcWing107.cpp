#include <iostream>
#define ll long long
using namespace std;
const int N = 500006;
int n, a[N], b[N];
ll ans;

void merge(int l, int mid, int r) {
  if (l == r) return;
  merge(l, (l+mid)>>1, mid);
  merge(mid+1, (mid+1+r)>>1, r);
  int i = l, j = mid+1;
  // 归并排序左右合并时进行逆序对统计
  for (int k=l; k<=r; k++)
    if (j > r || (i <= mid && a[i] <= a[j])) b[k] = a[i++];
    else b[k] = a[j++], ans += mid - i + 1;
  for (int k=l; k<=r; k++) a[k] = b[k];
}

void Ultra_QuickSort() {
  for (int i=1; i<=n; i++) cin >> a[i];
  ans = 0;
  merge(1, (1+n)>>1, n);
  cout << ans << endl;
}

int main() {
  while (cin >> n && n) Ultra_QuickSort();
  return 0;
}