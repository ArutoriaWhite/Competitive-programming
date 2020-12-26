  #include "lib1227.h"
  const int maxN = 1e6+5;

  long long* D, odd[maxN], even[maxN]; 
  int N, built=0;

  void init(int n, long long d[]) {
      N = n;
      D = d;
  }

  void change(int a, int b, long long k) {
    if (!(a&1))
    {
        odd[a] += k, odd[b+1] -= k;
        even[a] -= k, even[b+1] += k;
    }
    else
    {
        even[a] += k, even[b+1] -= k;
        odd[a] -= k, odd[b+1] += k;
    }
  }
  inline void build()
  {
      if (built) return;
      built=1;
      for (int i=1; i<N; i++)
      {
          even[i] += even[i-1];
          odd[i] += odd[i-1];
      }
  }

  long long query(int c){
      build();
      if (c&1) return D[c] + odd[c];
      else return D[c] + even[c];
  }