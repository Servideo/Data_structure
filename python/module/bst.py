from functools import cache
from typing import Any

#modules/
from .linked_list import Linked_list
from .queue import Queue
from .stack import Stack
from .node import Node
from .TreeNode import Tree_node
from .binarytree import Binary_tree


class Binary_search_tree (Binary_tree):
    
    def __init__(self):
        self.root: Tree_node | None = None
    
    @cache  
    def recursive_insert(self, root: Tree_node, data: Any) -> None:
        if root is None:
            return Tree_node(data)
        else:
            if root.data == data:
                return root
            
            elif root.data < data:
                root.right_child = self.recursive_insert(root.right_child, data)
            
            else:
                root.left_child = self.recursive_insert(root.left_child, data) 
        return root
        
    def recursive_create_tree(self, llist:Linked_list) -> None:
        temp:Node = llist.head
        while temp:
            self.root = self.recursive_insert(self.root, temp.data)
            temp = temp.next
    
    def insert_value(self, data = Any) -> None:
        new_data = Tree_node(data)
        if self.is_empty():
            self.root = new_data
            return
        queue:Queue = Queue()
        queue.enqueue(self.root)
        while not queue.is_empty():
            temp:Tree_node = queue.front.data
            queue.dequeue()
            if temp.data < new_data.data:
                if not temp.right_child:
                    temp.right_child = new_data
                    return
                else:
                    queue.enqueue(temp.right_child)
            else:
                if not temp.left_child:
                     temp.left_child = new_data
                     return
                else:
                    queue.enqueue(temp.left_child)
    
    def create_tree(self, llist:Linked_list) -> None:
        temp:Node = llist.head
        while temp:
            self.insert_value(temp.data)
            temp = temp.next
    