typedef struct vertax{
  int x, y;
  vertax(int a,int b) {
    x = a;
    y = b;
  }
}vertax;

bool cmp(vertax a, vertax b) {
  if (a.x < b.x || (a.x == b.x && a.y <= b.y))
    return true;
  else
    return false;
}

int main () {
  StarBurst
  #ifdef Miku_My_Wife
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int N, l, W;
  cin>>N>>l>>W;
  vector<vertax> vec;
  _for(i, 0, N) {
    int x, y;
    cin>>x>>y;
    vec.PB(vertax(x, y));
  }
  sort(ALL(vec), cmp);
  VI validX(1, vec[0].x);
  VI pos(1, 0); //pos[i]: the position where x == i
  _for(i, 1, N) {
    if (*(validX.end() - 1) != vec[i].x) {
      validX.PB(vec[i].x);
      pos.PB(i);
    }
  }
  pos.PB(N);

  int ans = 1;
  _for(L, 0, validX.size()) {
    int R = L;
    while (R < validX.size() && validX[R] - validX[L] <= W) {
      R++;
    }
    VI V;
    V.clear();
    for(int i = pos[L]; i < pos[R]; i++) {
      V.PB(vec[i].y);
    }
    //test(pos,"pos");
    //test(validX,"valid");
    //test(V,"V");
    sort(ALL(V));
    int U = 0, D = 0;
    while (D < V.size()) {
      if(V[D] - V[U] <= l) {
        ans = max(ans, D - U + 1);
        D++;
      } else {
        U++;
      } 
    }
  }
  cout<<ans<<'\n';

  return 0;
}