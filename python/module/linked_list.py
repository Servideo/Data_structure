from .node import Node
from typing import Any

class Linked_list:
    def __init__(self):
        self.__head = self.__last = None
        self.__size = 0

    @property
    def size(self) -> int:
        return self.__size
    
    @property
    def head(self):
        return self.__head
    
    @property
    def tail(self):
        return self.__last
        
    def get(self, index: int) -> any:
        if self.is_empty(): return None
        if index == 0:
            return self.__head.data
        elif index == self.size - 1:
            return self.__last.data
        current: Node = self.__head.next
        for _ in range(1, index):
            current = current.next
        return current.data

    def is_empty(self) -> bool:
        if (self.__head is None):
            return True
        return False

    def add(self, data: Any) -> None:
        new_data: Node = Node(data)
        self.__size += 1
        if self.is_empty():
            self.__head = self.__last = new_data
            return
        self.__last.next = new_data
        self.__last = new_data

    def pop(self, index: int) -> None:
        if self.is_empty() or index >= self.__size:
            return
        current: Node = self.__head
        prev: Node = self.__head
        if index == 0:
            self.__head = current.next
            self.__size -= 1
            return
        current = current.next
        for _ in range(1, index):
            prev = current
            current = current.next
        if index == self.__size - 1:
            prev.next = self.__last.next
            self.__last = prev
            self.__size -= 1
            return
        prev.next = current.next
        self.__size -= 1

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