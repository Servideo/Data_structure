package module;

public class Node<T> {

  Node<T> prev, next;
  T data;

  public Node(T data) {
    this.prev = this.next = null;
    this.data = data;
  }
}
