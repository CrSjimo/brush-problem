# 黑匣子-题解

由于我们要取出第i小的数，而堆可以取出最小的数，因此我们想到可以用堆来解决问题。

建两个堆，一个小根堆，记为`hp1`，一个大根堆，记为`hp2`

先把$a$和$b$分别读入，然后扫描$b$

对于$b$的每一项$b_i$，从$a$中按顺序取出项直到总共有$b_i$项被取出，把它们加入`hp1`

把`hp1`里最小的一项pop出来，插入到`hp2`上

然后就是关键的对顶操作。只要`hp1`中有小于`hp2`中最大元素的元素，就把`hp1`和`hp2`互换堆顶，这样可以保证$\forall x \in hp1, x > max(hp2)$

输出`hp2`堆顶

```c++
for(int i=1;i<=m;i++){
    for(;j<=b[i];j++){
        hp1.push(a[j]);
    }
    hp2.push(hp1.top());hp1.pop();
    while(!hp1.empty() && hp1.top()<hp2.top()){
        int hp1top = hp1.top();hp1.pop();
        int hp2top = hp2.top();hp2.pop();
        hp1.push(hp2top);
        hp2.push(hp1top);
    }
    printf("%d\n",hp2.top());
}
```