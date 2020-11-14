for(i=1;i<n;i++) {
    for(int j=0;j<=w;j++) {
        if(j>=w1[i]) {
            dp_1[i][j]=max(dp_1[i-1][j],dp_1[i-1][j-w1[i]]+v[i]);
        }else {
            dp_1[i][j]=dp_1[i-1][j];
        }
    }
}
