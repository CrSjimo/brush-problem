# APPLEACH题解

百度查了一下, 原题是HDU 1503.

题意大概是把两个字符串连在一起,然后最长公共子串只输出一次. 

## 操作

按照[最长公共子序列](./lcs.md)的方法去解. 

在遍历的时候,使用一个二维数组来记录回溯的路径. 

```c
#define IS_SUBSEQ_ITEM 0
#define IS_DP_J 1
#define IS_DP_I -1
for(int i = 1;i<=len1;i++){
    for(int j = 1;j<=len2;j++){
        if(s1[i-1] == s2[j-1]){
            dp[i][j] = dp[i-1][j-1]+1;
            pth[i][j] = IS_SUBSEQ_ITEM;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                pth[i][j] = IS_DP_J;
            }else{
                dp[i][j] = dp[i][j-1];
                pth[i][j] = IS_DP_I;
            }
        }
    }
}
```

例程中使用`pth`数组来记录. 

`0`表示`s1`的第`i`项与`s2`的第`j`项相等并构成了最长公共子序列的一项. 

`1`表示`s1`的第`i`项构成了最长公共子序列的一项. 

`-1`表示`s2`的第`j`项构成了最长公共子序列的一项. 

据此回溯. 

### 回溯的过程

用`i`和`j`回溯

首先把`i`置为`len1`, `j`置为`len2`, 然后读取pth数组,如果读到`0`,就回溯`i-1` `j-1`,如果读到`1`,就回溯`i-1` `j`,如果读到`-1`,就回溯`i` `j-1`. 

回溯直到`i`和`j`都等于`0`为止, 然后按照回溯的顺序给遍历到的字符输出. (注:最后的一个else里输出`s1[i-1]`或`s2[j-1]`皆可.

```c
void digui(int i,int j){
    if(i == 0 && j == 0){
        return;
    }
    if(pth[i][j] == IS_DP_J){
        digui(i-1,j);
        printf("%c",s1[i-1]);
    }else if(pth[i][j] == IS_DP_I){
        digui(i,j-1);
        printf("%c",s2[j-1]);
    }else{
        digui(i-1,j-1);
        printf("%c",s2[j-1]);
    }
}
```

代码: [lcs-3.c](./lcs-3.c)

![van樣嫌弃](./lcs-appleach.webp)