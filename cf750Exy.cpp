string str;
struct node{
    int rm[5][5];
}T[200010*6];
int match[4] = {2,0,1,7};
node operator + (node A,node B){
    node C;
    for(int i = 0 ; i < 5 ; i ++){
        for(int j = 0;j < 5; j ++){
            C.rm[i][j] = INF;
            for(int k = i ; k <= j; k ++){
                C.rm[i][j] = min(C.rm[i][j], A.rm[i][k] + B.rm[k][j]);
            }
        }
    }
    return C;
}
void build(int l,int r,int cur){
    if(l > r)return;
    if(l == r){
        for(int i = 0 ; i < 5 ; i ++){
            T[cur].rm[i][i] = 0;
            for(int j = i + 1; j < 5 ; j ++){
                T[cur].rm[i][j] = INF;
            }
        }
        int x = str[l] - '0';
        for(int i = 0; i < 4; i ++){
            if(x == match[i]){
                T[cur].rm[i][i] = 1;
                T[cur].rm[i][i + 1] = 0;
            }
        }
        if(x == 6){
            T[cur].rm[3][3] = T[cur].rm[4][4] = 1;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,cur << 1);
    build(mid + 1, r , cur << 1 | 1);
    if(r <= mid)T[cur] = T[cur << 1];
    else T[cur] = T[cur << 1] + T[cur << 1 | 1];
}
node query(int lx,int rx,int l,int r,int cur){
    if(l >= lx && r <= rx)return T[cur];
    int mid = (l + r) >> 1;
    if(rx <= mid)return query(lx,rx,l,mid,cur << 1);
    else if(lx > mid)return query(lx, rx, mid + 1, r, cur << 1 | 1);
    return query(lx,rx,l,mid,cur << 1) + query(lx, rx, mid + 1, r, cur << 1 | 1);
}
int main() {
    ios::sync_with_stdio(0);
    int n,q;
    cin >> n >> q;
    cin >> str;
    build(0,n-1,1);
    int L , R;
    while(q--){
        cin >> L >> R;
        L --;R--;
        node ans = query(L,R,0,n-1,1);
        if(ans.rm[0][4] == INF){
            cout << -1 << endl;
        }else{
            cout << ans.rm[0][4] << endl;
        }
    }
    return 0;
}
