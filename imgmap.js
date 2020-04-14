const util=require('util')
process.stdin.on('data',(dat)=>{
    let a=dat.toString().split(/\s+/).map((v)=>{
        return parseFloat(v);
    });
    process.stdout.write(util.format("%d %d\n",a[4]+a[2]-a[0],a[5]+a[3]-a[1]));
});