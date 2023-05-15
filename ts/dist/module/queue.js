import { Node } from "./node.js";
export class Queue {
    #front;
    #rear;
    #size;
    #maxSize;
    constructor(maxSize = 0) {
        this.#front = this.#rear = null;
        this.#maxSize = maxSize;
        this.#size = 0;
    }
    front() {
        if (this.isEmpty())
            throw new Error("List empty");
        return this.#front;
    }
    back() {
        if (this.isEmpty())
            throw new Error("Queue empty.");
        return this.#rear;
    }
    size() {
        return this.#size;
    }
    MaxSize() {
        return this.#maxSize;
    }
    setMaxSize(maxSize) {
        if (maxSize < this.#maxSize)
            return;
        this.#maxSize = maxSize;
    }
    enqueue(data) {
        if (this.#maxSize > 0 && this.#size > this.#maxSize)
            return;
        const newNode = new Node(data);
        this.#size++;
        if (this.isEmpty()) {
            this.#front = this.#rear = newNode;
            return;
        }
        this.#rear.next = newNode;
        this.#rear = newNode;
    }
    dequeue() {
        if (this.isEmpty())
            throw new Error("Queue empty.");
        this.#front = this.#front.next;
        this.#size--;
        if (this.#front == null)
            this.#rear = null;
    }
    isEmpty() {
        if (this.#front == null)
            return true;
        return false;
    }
    clear() {
        this.#front = this.#rear = null;
        this.#maxSize = this.#size = 0;
    }
    toString() {
        if (this.isEmpty())
            return "[]";
        let msg = "";
        let current = this.#front;
        msg += `${current.data}`;
        current = current.next;
        while (current) {
            msg += ` ${current.data}`;
            current = current.next;
        }
        return msg;
    }
}
//# sourceMappingURL=queue.js.map