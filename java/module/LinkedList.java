package module;

import module.Node;

public class LinkedList<T> {
    private Node<T> head;
    private Node<T> last;
    private int size;

    public LinkedList() {
        this.head = null;
        this.last = null;
        this.size = 0;
    }

    // getter
    public T get(int index) {
        if (index == 0) return this.head.data;
        else if (index == this.size - 1) return this.last.data;
        Node<T> current = this.head;
        for (int i = 1; i < index; i++) {
            current = current.next;
        }
        return current.data;
    }

    public int getSize() {
        return size;
    }

    // metodos
    public boolean isEmpty(){
        if(this.head == null) return true;
        return false;
    }
    public void add(T data) {
        this.size++;
        Node<T> newNode = new Node<>(data);
        if (this.isEmpty()) {
            this.head = newNode;
            return;
        } else if (this.last == null) {
            this.last = newNode;
            this.head.next = this.last;
            return;
        }
        this.last.next = newNode;
        this.last = newNode;
    }

    public String toString() {
        String msg;
        if(this.isEmpty()) return "Lista vacia";
        Node<T> current = this.head;
        msg = String.valueOf(current.data);
        current = current.next;
        while (current != null) {
            msg += " " + String.valueOf(current.data);
            current = current.next;
        }
        return msg;
    }

    public void reverse(){
        if(this.isEmpty()) return;
        this.last = this.head;
        Node<T> prev = null;
        Node<T> current = this.head;
        Node<T> next;
        while(current != null){
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        this.head = prev;
    }
}
