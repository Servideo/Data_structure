from node import Node
from typing import Any

class Doubly_linked_list():
    
    def __init__ (self):
        self.__head: Node = None
        self.__tail: Node = None
        self.__size: int = 0
    
    def get(self, index:int) -> Node:
        if index < 0 or index >= self.size:
            raise Exception('List index out range')
        if index == 0:
            return self.head
        elif index == self.size - 1:
            return self.tail
        temp:Node = self.head.next
        for _ in range(1, index):
            temp = temp.next
        return temp
     
    @property
    def head(self):
        return self.__head
    
    @property
    def tail(self):
        return self.__tail
        
    @property
    def size(self):
        return self.__size
    
    def add(self, data: Any):
        newNode: Node = Node(data)
        self.__size +=1
        if self.is_empty():
            self.__head = self.__tail = newNode
            return
        newNode.prev = self.__tail
        self.__tail.next = newNode
        self.__tail = newNode        
    
    def pop(self, index: int):
        if index < 0 or index >= self.size:
            raise Exception('List index out range')
        size: int = self.size
        self.__size -=1
        if index == 0:
            self.__head = self.__head.next
            return
        elif index == size - 1:
            self.__tail.prev.next = self.__tail.next
            self.__tail = self.__tail.prev
        temp:Node = self.head.next
        for _ in range(1, index):
            temp = temp.next
        temp.prev.next = temp.next
        temp.next.prev = temp.prev
    
    def is_empty(self) -> bool:
        if self.__head is None:
            return True
        return False
    
    def clear(self):
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
    
    def reverse(self):
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