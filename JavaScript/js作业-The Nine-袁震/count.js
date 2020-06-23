var addBtn = document.getElementById('add-btn');
var subBtn = document.getElementById('sub-btn');
var countEle = document.getElementById('count');

//计数器
var count = 0;
addBtn.addEventListener('click',function(){
    count++;
    countEle.innerText = count;
})
subBtn.addEventListener('click',function(){
    count--;
    countEle.innerText = count;
})