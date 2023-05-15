package module;

public class LinkedList<T> {

  private Node<T> head, last;
  private int size;

  public LinkedList() {
    this.head = this.last = null;
    this.size = 0;
  }

  public Node<T> get(int index) {
    if (index < 0 || index > this.size) 
      throw new IllegalArgumentException("List index out range");
    Node<T> current = this.head;
    if (index == 0) return current; else if (
      index == this.size - 1
    ) return this.last;
    current = current.next;
    for (int i = 1; i < index; i++) current = current.next;
    return current;
  }

  public Node<T> getHead(){
    return this.head;
  }

  public Node<T> getTail(){
    return this.last;
  }
  
  public int getSize() {
    return this.size;
  }

  public boolean isEmpty() {
    if (this.head == null) return true;
    return false;
  }

  public void clear(){
    this.head = this.last = null;
    this.size = 0;
  }

  public void add(T data) {
    this.size++;
    Node<T> newNode = new Node<>(data);
    if (this.isEmpty()) {
      this.head = this.last = newNode;
      return;
    }
    this.last.next = newNode;
    this.last = newNode;
  }

  public void pop(int index) {
    if (index < 0 || index > this.size)
      throw new IndexOutOfBoundsException("List index out range.");
    Node<T> current = this.head;
    Node<T> prev = this.head;
    int length = this.getSize();
    this.size--;
    if (index == 0) {
      this.head = current.next;
      return;
    }
    current = current.next;
    for (int i = 1; i < index; i++) {
      prev = current;
      current = current.next;
    }
    if (index == length - 1) {
      prev.next = this.last.next;
      this.last = prev;
      return;
    }
    prev.next = current.next;
  }

  public String toString() {
    if (this.isEmpty()) return "[]";
    Node<T> current = this.head;
    String msg = String.valueOf(current.data);
    current = current.next;
    while (current != null) {
      msg += " " + String.valueOf(current.data);
      current = current.next;
    }
    return msg;
  }

  public void reverse() {
    if (this.isEmpty() || this.size < 2) return;
    this.last = this.head;
    Node<T> prev = null;
    Node<T> current = this.head;
    Node<T> next;
    while (current != null) {
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
    this.head = prev;
  }

}
