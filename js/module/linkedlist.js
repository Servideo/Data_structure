import { Node } from "./node.js";

export class LinkedList {
  #head;
  #size;
  #last;
  constructor() {
    this.#head = null;
    this.#last = null;
    this.#size = 0;
  }

  // getter
  getSize() {
    return this.#size;
  }

  insertEnd(data) {
    let newNode = new Node(data);

    if (this.#head == null) {
      this.#head = newNode;
      // actualiza el tamaño de la lista
      this.#size++;
      return;
    } else if (this.#head.getNext() == null) {
      this.#last = newNode;
      this.#head.setNext(this.#last);
      this.#last.setNext(this.#head);
      this.#size++;
      return;
    }
    newNode.setNext(this.#last.getNext());
    this.#last.setNext(newNode);
    this.#last = newNode;
    this.#size++;
  }
  print() {
    if (this.#head == null) return;
    let temp = this.#head;
    let msg = `${temp.getData()}`;
    temp = temp.getNext();
    while (temp != this.#head) {
      msg += ` ${temp.getData()}`;
      temp = temp.getNext();
    }
    return msg;
  }
  reverse() {
    if (this.#head == null) return;
    this.#last = this.#head;
    let prev = null;
    let current = this.#head;
    let next;
    do {
      next = current.getNext();
      current.setNext(prev);
      prev = current;
      current = next;
    } while (current != this.#head);

    this.#head.setNext(prev);
    this.#head = prev;
  }
}
