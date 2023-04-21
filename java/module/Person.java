package module;

public class Person {
    String name;
    String lastName;
    public Person(String name,String lastName){
        this.name = name;
        this.lastName = lastName;
    }
    public void greeting(){
        System.out.printf("hola %s\n",name,lastName);
    }
}
