from .TreeNode import Tree_node
from .bst import Binary_search_tree

class Avl_tree (Binary_search_tree):
    
    def __init__(self):
        self.root: Tree_node | None = None
    