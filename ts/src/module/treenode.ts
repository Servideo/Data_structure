export class TreeNode<T>{
    public rightChild: TreeNode<T> | null;
    public data: T;
    public leftChild: TreeNode<T> | null;
    constructor(data: T){
        this.data = data;
        this.rightChild = null;
        this.leftChild = null;
    }
}