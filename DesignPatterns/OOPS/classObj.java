package DesignPatterns.OOPS;

class Person{
    public String name;
    public int age;
    Person(String name,int age){
        this.name = name;
        this.age = age;
    }
    public String getName(){
        return name;
    }
    public int getAge(){
        return age;
    }
}
public class classObj {
    public static void main(String[] args) {
        Person person = new Person("John", 20);
        System.out.println(person.getName());
    }
}