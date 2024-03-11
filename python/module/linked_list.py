from .node import Node
from typing import Any


class Linked_list:
    def __init__(self):
        self.__head:Node | None = None
        self.__last:Node | None = None
        self.__size = 0

    @property
    def size(self) -> int:
        return self.__size

    @property
    def head(self) -> Node:
        if self.is_empty():
            raise Exception('List empty.')
        return self.__head

    @property
    def tail(self) -> Node:
        if self.is_empty():
            raise Exception('List empty.')
        return self.__last

    def get(self, index: int) -> Node:
        if index < 0 or index >= self.size:
            raise IndexError('List index out range.')
        if index == 0:
            return self.__head
        elif index == self.size - 1:
            return self.__last
        current: Node = self.__head.next
        for _ in range(1, index):
            current = current.next
        return current

    def create_list(self, lists:list[Any]) -> None:
        for element in lists:
            self.add(element)
        
    def is_empty(self) -> bool:
        return True if self.__head is None else False

    def add(self, data: Any) -> None:
        new_data: Node = Node(data)
        self.__size += 1
        if self.is_empty():
            self.__head = self.__last = new_data
            return
        self.__last.next = new_data
        self.__last = new_data

    def pop(self, index: int) -> None:
        if index < 0 or index >= self.size:
            raise IndexError('List index out range.')
        current: Node = self.__head
        prev: Node = self.__head
        length: int = self.size
        self.__size -= 1
        if index == 0:
            temp:Node = self.__head
            self.__head = current.next
            del temp
            return
        current = current.next
        for _ in range(1, index):
            prev = current
            current = current.next
        if index == length - 1:
            prev.next = self.__last.next
            self.__last = prev
            del current
            return
        prev.next = current.next
        del current

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
        if self.is_empty() or self.__size < 2:
            return
        self.__last = self.__head
        prev: Node = None
        current: Node = self.__head
        while current:
            next: Node = current.next
            current.next = prev
            prev = current
            current = next

        self.__head = prev

    def copy(self):
        llist: Linked_list = Linked_list()
        temp: Node = self.__head
        while temp:
            llist.add(temp.data)
            temp = temp.next
        return llist