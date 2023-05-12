from module.linked_list import Linked_list
from module.queue import Queue
from module.stack import Stack
from module.node import Node
from module.doublylinked import Doubly_linked_list
        
def insert_linked(array: list[str]) -> Linked_list:
    llist: Linked_list = Linked_list()
    for element in array:
        llist.add(element)
    return llist

def insert_queue(array: list[str], size: int = 0) -> Queue:
    queue: Queue = Queue(size)
    for element in array:
        queue.enqueue(element)
    return queue

def insert_stack(array: list[str]) -> Stack:
    stack: Stack = Stack()
    for element in array:
        stack.push(element)
    return stack
        
def main():
    llist: Doubly_linked_list = Doubly_linked_list()
    llist.add(1)
    llist.add(2)
    llist.add(3)
    llist.add(4)
    try:
        prompt: str = int(input("ingresa un indice: "))
        llist.pop(prompt)
    except Exception as err:
        print(err)
    print(f"lista: {llist}")
    llist.reverse()
    print(f"lista: {llist}")
    
if __name__ == "__main__":
    main()