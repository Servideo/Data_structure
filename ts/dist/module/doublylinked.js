import { Node } from "./node.js";
export class DoublyLinkedList {
    #head = null;
    #tail = null;
    #size = 0;
    constructor() {
    }
    head() {
        if (this.isEmpty())
            throw new Error("List empty");
        return this.#head;
    }
    tail() {
        if (this.isEmpty())
            throw new Error("List empty");
        return this.#tail;
    }
    size() {
        return this.#size;
    }
    get(index) {
        if (this.isEmpty() || index >= this.#size || index < 0)
            throw new RangeError("list index out range.");
        else if (index == 0)
            return this.#head;
        else if (index == this.#size - 1)
            return this.#tail;
        let current = this.#head.next;
        for (let i = 1; i < index; i++)
            current = current.next;
        return current;
    }
    isEmpty() {
        return this.#head == null ? true : false;
    }
    clear() {
        this.#head = this.#tail = null;
        this.#size = 0;
    }
    add(data) {
        const newNode = new Node(data);
        this.#size++;
        if (this.isEmpty()) {
            this.#head = this.#tail = newNode;
            return;
        }
        newNode.prev = this.#tail;
        this.#tail.next = newNode;
        this.#tail = newNode;
    }
    pop(index) {
        if (this.isEmpty() || index > this.#size || index < 0)
            throw new RangeError("list index out range.");
        const size = this.size();
        this.#size--;
        if (index == 0) {
            this.#head.next.prev = this.#head.prev;
            this.#head = this.#head.next;
            return;
        }
        else if (index == size - 1) {
            this.#tail.prev = this.#tail.next;
            this.#tail = this.#tail.prev;
            return;
        }
        let temp = this.#head.next;
        let prev = this.#head;
        for (let i = 1; i < index; i++) {
            prev = temp;
            temp = temp.next;
        }
        prev.next = temp.next;
        temp.next.prev = prev;
    }
    toString() {
        if (this.isEmpty())
            return "[]";
        let msg = "";
        let current = this.#head;
        msg += `${current.data}`;
        current = current.next;
        while (current) {
            msg += ` ${current.data}`;
            current = current.next;
        }
        return msg;
    }
    reverse() {
        if (this.isEmpty())
            throw new Error("List empty.");
        this.#tail = this.#head;
        let prev = this.#head.prev;
        let current = this.#head;
        let next;
        while (current) {
            next = current.next;
            current.next = prev;
            current.prev = next;
            prev = current;
            current = next;
        }
        this.#head = prev;
    }
}
//# sourceMappingURL=doublylinked.js.map