export class Node<T> {
  public prev: Node<T> | null;
  public data: T;
  public next: Node<T> | null;
  constructor(data: T) {
    this.next = this.prev = null;
    this.data = data;
  }
}
