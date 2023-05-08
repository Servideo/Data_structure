from typing import Any

class Node:
    def __init__(self, data: Any):
        self.__prev: Node | None = None
        self.__data: any = data
        self.__next: Node | None = None

    # getter
    @property
    def data(self) -> Any:
        return self.__data

    @property
    def next(self) -> Any:
        return self.__next

    @property
    def prev(self) -> Any:
        return self.__prev

    # setter
    @data.setter
    def data(self, data: Any) -> None:
        self.__data = data

    @next.setter
    def next(self, next: Any) -> None:
        self.__next = next

    @prev.setter
    def prev(self, prev: Any) -> None:
        self.__prev = prev
