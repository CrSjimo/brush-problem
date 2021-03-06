# lcs原理

## 动♂态规划

状♂态：`dp[i][j]`

`i`: 比较序列`s1`的1~i项的最♂长公共子序列

`j`: 比较序列`s2`的1~j项的最♂长公共子序列

`dp[i][j]`: 最长公共子序列长度

## 开始操♂作

```c
for/*♂*/(int j = 1;j<=len2;j++){
    if(s1[i] /*♂*/== s2[j]){
        dp[i][j] = dp[i-1]/*♂*/[j-1]+1;
    }else{
        dp[i][j] = max(dp[i-1][j]/*♂*/,dp[i][j-1]);
    }
}
```

### `s1[i] == s2[j]`的操♂作

因为相♂等，所以这两项是所得子序列的一部♂分，把`s1[i-1]`与`s2[j-1]`的最♂长子序列长♂度加上一就是所得到的最♂长子序列长♂度

### `s1[i] != s2[j]`的操♂作

这两项不是子序列的一部♂分，所以取包♂括`s1[i]`不包♂括`s2[j]`的最♂长子序列长♂度，即`dp[i][j-1] `与不包♂括`s1[i]`包♂括`s2[j]`的最长子序列长♂度,即`dp[i-1][j]`取最大值即为当前最♂长子序列长♂度

最后，`dp[len1][len2]`就是整个序列的最♂长子序列长♂度

![当♂真](./lcs-dangzhen.webp)