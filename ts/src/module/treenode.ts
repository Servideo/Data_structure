export class TreeNode<T>{
    public rightChild: TreeNode<T> | null = null;
    public data: T;
    public leftChild: TreeNode<T> | null = null;
    constructor(data: T){
        this.data = data;
    }
}