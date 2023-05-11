from .node import Node
from typing import Any

class Stack:
    def __init__(self):
        self.__top: Node | None = None
        self.__size: int = 0
    
    def peek(self):
        if self.is_empty():
            return None
        return self.__top.data
    
    @property
    def size(self) -> int:
        return self.__size
    
    def push(self, data: Any):
        new_node = Node(data)
        self.__size +=1
        if self.is_empty():
            self.__top = new_node
            return
        new_node.next = self.__top
        self.__top = new_node
    
    def pop(self):
        if self.is_empty(): raise Exception("Stack is empty")
        self.__top = self.__top.next
        self.__size -= 1
        
    def is_empty(self) -> bool:
        if self.__top is None:
            return True
        return False
    
    def clear(self) -> None:
        self.__top = None

    def __str__(self) -> str:
        if self.is_empty():
            return '[]'
        temp: Node = self.__top
        msg: str = ''
        msg = f'{temp.data}'
        temp = temp.next
        while(temp):
            msg += f' {temp.data}'
            temp = temp.next
        return msg