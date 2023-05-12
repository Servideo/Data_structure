package module;

public class Stack <T>{
    private int size;
    private Node<T> top;

    public Stack(){
        this.size = 0;
        this.top = null;
    }

    public int getSize(){
        return this.size;
    }

    public Node<T> peek(){
        return this.top;
    }

    public void push(T data){
        Node<T> newNode = new Node<>(data);
        this.size++;
        if(this.isEmpty()){
            this.top = newNode;
            return;
        }
        newNode.next = this.top;
        this.top = newNode;
    }

    public void pop(){
        if(this.isEmpty()){
            throw new IllegalArgumentException("Stack is empty");
        }
        this.top = this.top.next;
        this.size--;
    }

    public boolean isEmpty(){
        if (this.top == null)
            return true;
        return false;
    }

    public void clear(){
        if(this.isEmpty())
            return;
        this.top = null;
        this.size = 0;
    }

    public String toString() {
        if (this.isEmpty()) return "[]";
        Node<T> current = this.top;
        String msg = String.valueOf(current.data);
        current = current.next;
        while (current != null) {
          msg += " " + String.valueOf(current.data);
          current = current.next;
        }
        return msg;
    }
}
