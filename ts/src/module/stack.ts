import { Node } from "./node.js";

export class Stack<T> {
  #top: Node<T> | null;
  #size: number;
  constructor() {
    this.#top = null;
    this.#size = 0;
  }

  peek(): Node<T> {
    if (this.isEmpty()) throw new Error("Stack empty.");
    return this.#top!;
  }

  size(): number {
    return this.#size;
  }

  push(data: T): void {
    const newNode: Node<T> = new Node(data); 
    this.#size++;
    if(this.isEmpty()){
        this.#top = newNode;
        return;
    }
    newNode.next = this.#top;
    this.#top = newNode;
  }

  pop(): void {
    if (this.isEmpty()) throw new Error("Stack empty.");
    this.#top = this.#top!.next;
    this.#size--;
  }

  isEmpty(): boolean {
    if (this.#top == null) return true;
    return false;
  }

  clear(): void {
    this.#top = null;
    this.#size = 0;
  }

  toString(): string {
    if (this.isEmpty()) return "[]";
    let msg = "";
    let current = this.#top!;
    msg += `${current.data}`;
    current = current!.next!;
    while (current) {
      msg += ` ${current.data}`;
      current = current!.next!;
    }
    return msg;
  }
}
