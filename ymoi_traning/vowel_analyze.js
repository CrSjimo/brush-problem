let vowels=['a','e','i','o','u','y','и','ū',]
let sep_vowels=['ä','ï','ä','ë','ï','ö','ü','ÿ','ṻ'];
let combines=new Set();
function analyze(s){
    s.toLowerCase();
    let tmp='';
    for(let i=0;i<s.length;i++){
        if(vowels.indexOf(s[i])!=-1){
            tmp+=s[i];
        }else if(sep_vowels.indexOf(s[i])!=-1){
            if(tmp!='')combines.add(tmp);
            tmp='';
            tmp+=s[i];
        }else{
            if(tmp!='')combines.add(tmp);
            tmp='';
        }
    }
    if(tmp!='')combines.add(tmp);
}

process.stdin.on('data',(dat)=>{
    analyze(dat.toString());
});

process.stdin.on('end',()=>{
    console.log(...[...combines].sort());
})