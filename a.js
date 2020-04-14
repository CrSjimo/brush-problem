let a='';
process.stdin.on('data',dat=>a+=dat.toString());
process.stdin.on('end',()=>{
    a=a.split(/\s+/).map(v=>parseInt(v));
    process.stdout.write((a[0]*a[1]/2).toString()+'\n');
});
