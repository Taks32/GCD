#include <stdio.h>

const int n = 10000;

unsigned int Euclidean_gcd_rec(unsigned int x, unsigned int y){
  if (x == 0) return y;
  return Euclidean_gcd_rec(y % x, x);
}

unsigned int Euclidean_gcd_itr(unsigned int x, unsigned int y){
  while (x != 0) {
    int z = x;
    x = y % x;
    y = z;
  }
  return y;
}

unsigned int binary_gcd_rec(unsigned int x, unsigned int y){
  if (y == 0) return x;
  if (x == 0) return y;
  if (x % 2 == 0 && y % 2 == 0) return 2 * binary_gcd_rec(x / 2, y / 2);
  if (x % 2 == 0) return binary_gcd_rec(x / 2, y);
  if (y % 2 == 0) return binary_gcd_rec(x, y / 2);
  if (y >= x) return binary_gcd_rec(x, (y - x) / 2);
  return binary_gcd_rec((x - y) / 2, y);
}

unsigned int binary_gcd_itr(unsigned int x, unsigned int y){
  int res = 1;
  while (1) {
    if (x == 0) {
      res = res * y;
      break;
    }
    if (y == 0) {
      res = res * x;
      break;
    }
    if (x % 2 == 0) {
      if (y % 2 == 0) {
        res += res;
        x = x / 2;
        y = y / 2;
      } else x = x / 2;
    } else if (y % 2 == 0) y = y / 2;
    else if (y >= x) y = (y - x) / 2;
    else x = (x - y) / 2;
  }
  return res;
}


int main(){
  unsigned int i, j, c;


  c = 0;
  for(i = 1; i <= n; i++){
    for(j = i+1; j <= n; j++){
      if(binary_gcd_itr(i, j) == 1){
        c++;
      }
    }
  }
  c = 2*c+1;

  printf("%f\n", (double) c / (n*n));
  return 0;
}
