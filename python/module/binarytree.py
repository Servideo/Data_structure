
from functools import cache
from typing import Any

# modules/
from .TreeNode import Tree_node
from .linked_list import Linked_list
from .queue import Queue
from .node import Node
from .stack import Stack


class Binary_tree:

    def __init__(self):
        self.root: Tree_node | None = None

    def insert_value(self, data: Any) -> None:
        new_data: Tree_node = Tree_node(data)
        if self.is_empty():
            self.root = new_data
            return
        tree: Queue = Queue()
        tree.enqueue(self.root)

        while not tree.is_empty():
            temp: Tree_node = tree.front.data
            tree.dequeue()
            if not temp.left_child:
                temp.left_child = new_data
                return
            else:
                tree.enqueue(temp.left_child)
            if not temp.right_child:
                temp.right_child = new_data
                return
            else:
                tree.enqueue(temp.right_child)

    def create_tree(self, llist: Linked_list) -> None:
        temp: Node = llist.head
        while temp:
            self.insert_value(temp.data)
            temp = temp.next

    def is_empty(self) -> bool:
        return True if self.root is None else False

    def clear(self) -> None:
        temp: Tree_node = self.root
        self.root = None
        del temp

    @cache
    def __high(self, node: Tree_node) -> int:
        if node is None:
            return -1
        left: int = self.__high(node.left_child) + 1
        max_int: int = left
        right: int = self.__high(node.right_child) + 1
        if right > max_int:
            max_int = right
        return max_int

    def high(self) -> int:
        if self.is_empty():
            raise Exception("Tree is empty")
        return self.__high(self.root) + 1

    @cache
    def __view_level(self, node: Tree_node, level: int, llist: Linked_list) -> None:
        if node is None:
            return
        if level == 0:
            llist.add(node.data)
        self.__view_level(node.left_child, level - 1, llist)
        self.__view_level(node.right_child, level - 1, llist)

    def view_level(self, level: int) -> Linked_list:
        if self.is_empty():
            raise Exception("Tree is empty")
        llist: Linked_list = Linked_list()
        self.__view_level(self.root, level, llist)
        return llist

    @cache
    def __recursive_pre_order(self, root: Tree_node, llist: Linked_list) -> None:
        if root:
            llist.add(root.data)
            self.__recursive_pre_order(root.left_child, llist)
            self.__recursive_pre_order(root.right_child, llist)

    def recursive_pre_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("Tree is empty")
        llist: Linked_list = Linked_list()
        self.__recursive_pre_order(self.root, llist)
        return llist

    def pre_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("Tree is empty")
        llist: Linked_list = Linked_list()
        stack: Stack = Stack()
        stack.push(self.root)
        current: Tree_node = self.root
        while not stack.is_empty():
            if current:
                llist.add(current.data)

                if current.right_child:
                    stack.push(current.right_child)

                current = current.left_child

            else:
                current = stack.peek().data
                stack.pop()

        return llist

    @cache
    def __recursive_post_order(self, root: Tree_node, llist: Linked_list) -> None:
        if root:
            self.__recursive_post_order(root.left_child, llist)
            self.__recursive_post_order(root.right_child, llist)
            llist.add(root.data)

    def __recursive_post_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("Tree is empty")
        llist: Linked_list = Linked_list()
        self.travel_post_order(self.root, llist)
        return llist

    def post_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("Tree is empty")

        current: Tree_node = self.root
        llist: Linked_list = Linked_list()
        prev_stack: Stack = Stack()
        current_stack: Stack = Stack()
        prev_stack.push(current)

        while not prev_stack.is_empty():
            current = prev_stack.peek().data
            current_stack.push(current)
            prev_stack.pop()
            if current.left_child is not None:
                prev_stack.push(current.left_child)
            if current.right_child is not None:
                prev_stack.push(current.right_child)

        while not current_stack.is_empty():
            current = current_stack.peek().data
            llist.add(current.data)
            current_stack.pop()

        return llist

    @cache
    def __recursive_in_order(self, root: Tree_node, llist: Linked_list) -> None:
        if not root:
            return
        self.__recursive_in_order(root.left_child, llist)
        llist.add(root.data)
        self.__recursive_in_order(root.right_child, llist)

    def recursive_in_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("tree empty")
        llist: Linked_list = Linked_list()
        self.__recursive_in_order(self.root, llist)
        return llist

    def in_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("tree is empty")
        llist: Linked_list = Linked_list()
        stack: Stack = Stack()
        current: Tree_node = self.root
        while not stack.is_empty() or current is not None:
            if current is not None:
                stack.push(current)
                current = current.left_child
            else:
                if stack.is_empty():
                    break
                current = stack.peek().data
                llist.add(current.data)
                stack.pop()
                current = current.right_child

        return llist

    def level_order(self) -> Linked_list:
        if self.is_empty():
            raise Exception("Tree is empty")
        llist: Linked_list = Linked_list()
        queue: Queue = Queue()
        queue.enqueue(self.root)
        while not queue.is_empty():
            temp: Tree_node = queue.front.data
            llist.add(temp.data)
            if temp.left_child:
                queue.enqueue(temp.left_child)
            if temp.right_child:
                queue.enqueue(temp.right_child)
            queue.dequeue()
        return llist

    def search(self, key: Any) -> Tree_node:
        if self.is_empty():
            raise Exception("Tree is empty")

        elif self.root.data == key:
            return self.root

        current: Tree_node | None = None
        queue: Queue = Queue()
        queue.enqueue(self.root)

        while not queue.is_empty():
            current = queue.front.data
            queue.dequeue()

            if current.data == key:
                return current

            if current.left_child:
                queue.enqueue(current.left_child)

            if current.right_child:
                queue.enqueue(current.right_child)

        if current is None:
            raise Exception("item not found.")

    def delete(self, key: Any) -> None:
        if self.is_empty():
            raise Exception("Tree is empty.")

        if self.root.left_child is None and self.root.right_child is None:
            if self.root.data == key:
                self.root = None
                return
            else:
                raise Exception("item not found.")

        current: Tree_node | None = None
        target: Tree_node | None = None
        last: Tree_node | None = None
        queue: Queue = Queue()
        queue.enqueue(self.root)

        while not queue.is_empty():
            current = queue.front.data
            queue.dequeue()

            if current.data == key:
                target = current

            if current.left_child:
                last = current
                queue.enqueue(current.left_child)

            if current.right_child:
                last = current
                queue.enqueue(current.right_child)

        if target is not None:
            target.data = current.data
            if last.left_child == current:
                last.left_child = None

            else:
                last.right_child = None

            del current

        else:
            raise Exception("item no found.")
