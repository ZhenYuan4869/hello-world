//1.组合式继承
function Person(name) {
    this.name = name;
}
Person.prototype.say = function () {
    console.log('hi, i am '+ this.name);
}
    
function Chinese(name) {
    Person.call(this, name); // NOTE: super函数调用，注意这里有跟父类的显式耦合
}
Chinese.prototype = new Person(); // prototype对象更换为animal实例，实现继承
Chinese.prototype.say = function () {
  Person.prototype.say.apply(this); // 父类方法引用，注意这里有跟父类的显式耦合
  console.log(', i live in china');
}
//演示
var chinese = new Chinese('Chinese');
chinese.say();
console.log(chinese);


//2.寄生组合式继承
function Person(name) {
  this.name = name;
}
Person.prototype.say = function () {
  console.log('hi, i am '+ this.name);
}
  
function Chinese(name) {
  Person.call(this, name); // NOTE: super函数调用，注意这里有跟父类的显式耦合
}
Chinese.prototype = Object.create(Person.prototype); // 使用Object.create来替代new实体的操作实现继承
Chinese.prototype.say = function () {
Person.prototype.say.apply(this); // 父类方法引用，注意这里有跟父类的显式耦合
console.log(', i live in china');
}
//演示
var chinese = new Chinese('Chinese');
chinese.say();
console.log(chinese);