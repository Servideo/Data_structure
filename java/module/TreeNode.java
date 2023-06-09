package module;

class TreeNode<T>{
    public TreeNode<T> rightNode, leftNode;
    public T data;

    public TreeNode(T data){
        this.data = data;
        this.rightNode = this.leftNode = null;
    }
}