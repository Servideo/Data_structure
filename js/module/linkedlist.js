import { Node } from "./node.js";

export class LinkedList {
  #head;
  #size;
  constructor() {
    this.#head = null;
    this.#size = 0;
  }

  // getter
  getHead() {
    return this.#head.getData();
  }

  getSize() {
    return this.#size;
  }
  
  insertEnd(head) {
    let newNode = new Node(head);

    if (this.#head == null) {
      this.#head = newNode;
      // actualiza el tamaño de la lista
      this.#size++;
      return;
    }
    let lastNode = this.#head;
    while (lastNode.getNext()) {
      lastNode = lastNode.getNext();
    }
    lastNode.setNext(newNode);
    this.#size++;
  }
  print() {
    let msg = "";
    if (this.#head == null) return;
    let temp = this.#head;
    while (temp) {
      msg += `${temp.getData()} `;
      temp = temp.getNext();
    }
    return msg;
  }
  reverse() {
    let prev = null;
    let current = this.#head;
    let next;
    while (current) {
      next = current.getNext();
      current.setNext(prev);
      prev = current;
      current = next;
    }
    this.#head = prev;
  }
}
