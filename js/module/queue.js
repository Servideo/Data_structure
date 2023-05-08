"use strict";

import Node from "./node.js";

export class queque {
  #front;
  #rear;
  #maxSize;
  #size;
  constructor(maxSize = 0) {
    this.#front = null;
    this.#rear = null;
    this.#maxSize = maxSize;
    this.#size = 0;
  }
  front() {
    return this.#front;
  }

  back() {
    return this.#rear;
  }

  size() {
    return this.#size;
  }

  setMaxSize(maxSize = 0){
    if(maxSize < this.#maxSize) return;
    this.#maxSize = maxSize;
  }

  maxSize(){
    return this.#maxSize;
  }

  enqueue(data) {
    this.#size++;
    if (this.isEmpty()) {
      newNode = new Node(data);
      this.#rear = this.#rear = newNode;
      return;
    }
    this.#rear.setNext(newNode);
  }

  dequeue() {
    if (this.isEmpty()) return;
    this.#front = this.#front.getNext();
    this.#size--;
    if (this.#front == null) this.#rear == null;
  }

  isEmpty() {
    if (this.#front == null) return true;
    return false;
  }

  clear() {
    this.#front = this.#rear = null;
    this.#maxSize = this.#size = 0;
  }

  toString() {
    if (this.isEmpty()) return "[]";
    let temp = this.#front;
    let msg = `${temp.getData()}`;
    temp = temp.getNext();
    while (temp) {
      msg += ` ${temp.getData()}`;
      temp = temp.getNext();
    }
    return msg;
  }
}
