export class Node {
  #data;
  #next;
  #prev;
  constructor(data) {
    this.#prev = this.#next = null;
    this.#data = data;
  }
  // getter
  getprev() {
    return this.#prev;
  }

  getData() {
    return this.#data;
  }

  getNext() {
    return this.#next;
  }

  // setter
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
