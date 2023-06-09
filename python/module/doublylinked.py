from .node import Node
from typing import Any


class Doubly_linked_list():

    def __init__(self):
        self.__head: Node = None
        self.__tail: Node = None
        self.__size: int = 0

    def get(self, index: int) -> Node:
        if index < 0 or index >= self.size:
            raise IndexError('List index out range.')
        if index == 0:
            return self.head
        elif index == self.size - 1:
            return self.tail
        temp: Node = self.head.next
        for _ in range(1, index):
            temp = temp.next
        return temp

    @property
    def head(self) -> Node:
        return self.__head

    @property
    def tail(self) -> Node:
        return self.__tail

    @property
    def size(self) -> int:
        return self.__size

    def add(self, data: Any) -> None:
        newNode: Node = Node(data)
        self.__size += 1
        if self.is_empty():
            self.__head = self.__tail = newNode
            return
        newNode.prev = self.__tail
        self.__tail.next = newNode
        self.__tail = newNode

    def pop(self, index: int) -> None:
        if index < 0 or index >= self.size:
            raise IndexError('List index out range.')
        size: int = self.size
        self.__size -= 1
        if index == 0:
            self.__head.next.prev = self.__head.prev
            self.__head = self.__head.next
            return
        elif index == size - 1:
            self.__tail.prev.next = self.__tail.next
            self.__tail = self.__tail.prev
            return
        temp: Node = self.head.next
        prev: Node = temp.prev
        for _ in range(1, index):
            prev = temp
            temp = temp.next
        prev.next = temp.next
        temp.next.prev = prev

    def is_empty(self) -> bool:
        return True if self.__head is None else False

    def clear(self) -> None:
        self.__head = self.__tail = None
        self.__size = 0

    def __str__(self) -> str:
        if self.is_empty():
            return "[]"
        temp: Node = self.__head
        msg: str = f'{temp.data}'
        temp = temp.next
        while temp:
            msg += f' {temp.data}'
            temp = temp.next
        return msg

    def reverse(self) -> None:
        if self.is_empty() or self.size < 2:
            return
        self.__tail = self.__head
        prev: Node = self.head.prev
        current: Node = self.head
        while current:
            next: Node = current.next
            current.next = prev
            current.prev = next
            prev = current
            current = next
        self.__head = prev

    def copy(self):
        llist: Doubly_linked_list = Doubly_linked_list()
        temp: Node = self.__head
        while temp:
            llist.add(temp.data)
            temp = temp.next
        return llist