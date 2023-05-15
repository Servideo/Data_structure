from .node import Node
from typing import Any


class Queue:
    def __init__(self, max_size=0):
        self.__front: Node | None = None
        self.__rear: Node | None = None
        self.__max_size: int = max_size
        self.__size: int = 0

    @property
    def front(self) -> Node:
        return self.__front

    @property
    def back(self) -> Node:
        return self.__rear

    @property
    def size(self) -> int:
        return self.__size

    @property
    def max_size(self) -> int:
        return self.__max_size

    @max_size.setter
    def max_size(self, max_size=0):
        if max_size < self.__max_size:
            return
        self.__max_size = max_size

    def enqueue(self, data: Any) -> None:
        if self.__max_size > 0 and self.__size >= self.__max_size:
            return
        new_node: Node = Node(data)
        self.__size += 1
        if self.is_empty():
            self.__front = self.__rear = new_node
            return
        self.__rear.next = new_node
        self.__rear = new_node

    def dequeue(self) -> None:
        if self.is_empty():
            raise Exception("Queue is empty.")
        self.__front = self.__front.next
        if self.__front is None:
            self.__rear = None

    def is_empty(self) -> bool:
        if self.__front is None:
            return True
        return False

    def clear(self) -> None:
        self.__front = self.__rear = None
        self.__max_size = self.__size = 0

    def __str__(self) -> str:
        if self.is_empty():
            return '[]'
        temp: Node = self.__front
        msg: str = ''
        msg = f'{temp.data}'
        temp = temp.next
        while (temp):
            msg += f' {temp.data}'
            temp = temp.next
        return msg
