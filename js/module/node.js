"use strict";

export class Node {
  #data;
  #next;
  #prev;
  constructor(data) {
    this.#prev = this.#next = null;
    this.#data = data;
  }

  getPrev() {
    return this.#prev;
  }

  getData() {
    return this.#data;
  }

  getNext() {
    return this.#next;
  }

  setPrev(prev) {
    this.#prev = prev;
  }

  setData(data) {
    this.#data = data;
  }

  setNext(next) {
    this.#next = next;
  }
}
