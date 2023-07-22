from typing import Any

class Tree_node:
    
    def __init__(self, data: Any):
        self.__data: Any = data
        self.__right_child: Tree_node | None = None
        self.__left_child: Tree_node | None = None
    
    @property
    def data(self) -> Any:
        return self.__data
    
    @property
    def right_child(self):
        return self.__right_child
    
    @property
    def left_child(self):
        return self.__left_child
    
    @data.setter
    def data(self, data: Any) -> None:
        self.__data = data
    
    @right_child.setter
    def right_child(self, right_child) -> None:
        self.__right_child = right_child
    
    @left_child.setter
    def left_child(self, left_child) -> None:
        self.__left_child = left_child