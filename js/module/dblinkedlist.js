"use strict";

import {Node} from "./node.js";

export class DoublyLinkedList {
  #head;
  #tail;
  #size;
  constructor() {
    this.#head = this.#tail = null;
    this.#size = 0;
  }

  getSize() {
    return this.#size;
  }

  getHead() {
    return this.#head;
  }

  getTail() {
    return this.#tail;
  }

  get(index) {
    if (index >= this.#size || index < 0) 
      throw new Error("List index out range of list");
    else if (index == 0) return this.#head;
    else if (index == this.#size - 1) return this.#tail;
    let temp = this.#head.getNext();
    for (let i = 1; i < index; i++) {
      temp = temp.getNext();
    }
    return temp;
  }

  isEmpty() {
    if (this.#head == null) return true;
    return false;
  }

  clear() {
    this.#head = this.#tail = null;
    this.#size = 0;
  }

  add(data) {
    let newNode = new Node(data);
    this.#size++;
    if (this.isEmpty()) {
      this.#head = this.#tail = newNode;
      return;
    }
    newNode.setPrev(this.#tail);
    this.#tail.setNext(newNode);
    this.#tail = newNode;
  }

  pop(index) {
    if (index >= this.#size || index < 0) 
      throw new Error("List index out range of list");
    let size = this.getSize();
    this.#size--;
    if (index == 0) {
      this.#head = this.#head.getNext();
      return;
    } else if (index == size - 1) {
      this.#tail.getPrev().setNext(this.#tail.getNext());
      this.#tail = this.#tail.getPrev();
      return;
    }
    let current = this.#head.getNext();
    let prev = current.getPrev();
    for (let i = 1; i < index; i++) {
      prev = current;
      current = current.getNext();
    }
    prev.setNext(current.getNext());
    current.getNext().setPrev(prev);
  }

  toString() {
    if (this.isEmpty()) return "[]";
    let temp = this.#head;
    let msg = `${temp.getData()}`;
    temp = temp.getNext();
    while (temp) {
      msg += ` ${temp.getData()}`;
      temp = temp.getNext();
    }
    return msg;
  }

  reverse() {
    if (this.isEmpty() || this.#size < 2) return;
    this.#tail = this.#head;
    let prev = this.#head.getPrev();
    let current = this.#head;
    let next;
    while (current != null) {
      next = current.getNext();
      current.setNext(prev);
      current.setPrev(next);
      prev = current;
      current = next;
    }
    this.#head = prev;
  }
}
