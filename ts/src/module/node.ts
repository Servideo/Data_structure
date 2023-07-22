export class Node<T> {
  public prev: Node<T> | null = null;
  public data: T;
  public next: Node<T> | null = null;
  constructor(data: T) {
    this.data = data;
  }
}
