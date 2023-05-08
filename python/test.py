from module.linked_list import Linked_list
from module.queue import Queue
from module.stack import Stack
from module.node import Node
        
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
    e = input().split()
    q = insert_queue(e)
    q.enqueue('1')
    q.dequeue()
    q.enqueue('18')
    q.enqueue('80')
    q.dequeue()
    print(q.front)
if __name__ == "__main__":
    main()