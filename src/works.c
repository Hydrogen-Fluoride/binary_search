#include <stdio.h>

int n;
int k;
int A[100000];

int isOK(int work) {
  int index = 0;
  for (int i = 0; i < k; i++) {
    int wrk = work;
    while (index < n && wrk - A[index] >= 0) {
      wrk -= A[index];
      index++;
    }
    if (index == n) {
      break;
    }
  }
  return index == n;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (isOK(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
