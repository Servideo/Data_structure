package module;

public class Node<T> {

  public Node<T> prev, next;
  public T data;

  public Node(T data) {
    this.prev = this.next = null;
    this.data = data;
  }
}
