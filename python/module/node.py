class Node:
    def __init__(self, data: any):
        self.data = data
        self.next = None

    # getter
    def get_data(self) -> str:
        return self.data

    def get_next(self) -> str:
        return self.next

    # setter
    def set_data(self, data) -> None:
        self.data = data

    def set_next(self, next) -> None:
        self.next = next
