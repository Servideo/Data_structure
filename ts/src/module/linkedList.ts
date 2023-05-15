import { Node } from "./node.js";

export class LinkedList<T> {
  #head: Node<T> | null;
  #tail: Node<T> | null;
  #size: number;
  constructor() {
    this.#head = this.#tail = null;
    this.#size = 0;
  }

  head(): Node<T> {
    if (this.isEmpty()) throw new Error("List empty");
    return this.#head!;
  }

  tail(): Node<T> {
    if (this.isEmpty()) throw new Error("List empty");
    return this.#tail!;
  }

  size(): number {
    return this.#size;
  }

  get(index: number): Node<T> {
    if (this.isEmpty() || index >= this.#size || index < 0)
      throw new RangeError("list index out range");
    else if (index == 0) return this.#head!;
    else if (index == this.#size - 1) return this.#tail!;
    let current = this.#head!.next;
    for (let i = 1; i < index; i++) current = current!.next;
    return current!;
  }

  isEmpty(): boolean {
    if (this.#head == null) return true;
    return false;
  }

  clear(): void {
    this.#head = this.#tail = null;
    this.#size = 0;
  }

  add(data: T): void {
    const newNode = new Node(data);
    this.#size++;
    if (this.isEmpty()) {
      this.#head = this.#tail = newNode;
      return;
    }
    this.#tail!.next = newNode;
    this.#tail = newNode;
  }

  pop(index: number): void {
    if (this.isEmpty() || index >= this.#size || index < 0)
      throw new RangeError("list index out range");
    let size = this.size();
    this.#size--;
    if (index == 0) {
      this.#head = this.#head!.next;
      return;
    }
    let current = this.#head!.next;
    let prev = this.#head;
    for (let i = 1; i < index; i++) {
      prev = current;
      current = current!.next;
    }
    if (index == size - 1) {
      prev!.next = current!.next;
      this.#tail = prev!;
      return;
    }
    prev!.next = current!.next;
  }

  toString(): string {
    if (this.isEmpty()) return "[]";
    let msg = "";
    let current = this.#head!;
    msg += `${current.data}`;
    current = current!.next!;
    while (current) {
      msg += ` ${current.data}`;
      current = current!.next!;
    }
    return msg;
  }

  reverse(): void {
    if (this.isEmpty()) throw new Error("List empty");
    this.#tail = this.#head;
    let prev: Node<T> | null = null;
    let current: Node<T> | null = this.#head;
    let next: Node<T> | null;
    while (current) {
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
    this.#head = prev;
  }
}
