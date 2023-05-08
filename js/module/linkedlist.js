"use strict";

import Node from "./node.js";

export class LinkedList {
  #head;
  #size;
  #last;
  constructor() {
    this.#head = this.#last = null;
    this.#size = 0;
  }

  getSize() {
    return this.#size;
  }
  get(index) {
    if (this.isEmpty()) return;
    else if (index === 0) return this.#head.getData();
    else if (index === this.#size - 1) return this.#last.getData();
    let current = this.#head.getNext();
    for (let i = 1; i < index; i++) current = current.getNext();
    return current.getData();
  }
  isEmpty(){
    if (this.#head == null) return true;
    return false;
  }

  add(data) {
    let newNode = new Node(data);
    this.#size++;
    if (this.isEmpty()) {
      this.#head = this.#last = newNode;
      return;
    }
    this.#last.setNext(newNode);
    this.#last = newNode;
  }
  pop(index) {
    if (this.isEmpty() || index >= this.#size) return;
    let current = this.head;
    let prev = this.#head;
    if (index == 0) {
      this.#head = current.next;
      this.#size--;
      return;
    }
    current = current.next;
    for (let i = 1; i < index; i++) {
      prev = current;
      current = current.next;
    }
    if (index == this.#size - 1) {
      prev.next = this.last.next;
      this.last = prev;
      this.#size--;
    }
    prev.next = current.next;
    this.#size--;
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
    this.#last = this.#head;
    let prev = null;
    let current = this.#head;
    let next;
    while(current){
      next = current.getNext();
      current.setNext(prev);
      prev = current;
      current = next;
    }
    this.#head = prev;
  }
}