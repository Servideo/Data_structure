from typing import Any


class Node:
    def __init__(self, data: Any):
        self.__prev: Node | None = None
        self.__data: Any = data
        self.__next: Node | None = None

    @property
    def data(self) -> Any:
        return self.__data

    @property
    def next(self):
        return self.__next

    @property
    def prev(self):
        return self.__prev

    @data.setter
    def data(self, data: Any) -> None:
        self.__data = data

    @next.setter
    def next(self, next) -> None:
        self.__next = next

    @prev.setter
    def prev(self, prev) -> None:
        self.__prev = prev
