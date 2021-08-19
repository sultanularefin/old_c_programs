
    function Node(val) {
        this.value = val;
        this.left = null;
        this.right = null;

    }
    // https://www.w3schools.com/js/js_object_prototypes.asp
    // Bin


    function BinarySearchTree() {
        this.root = null;
        this.Added_result = 0;
    }

    BinarySearchTree.prototype.push = function (val) {
        if (isNaN(val)) {
            console.log("Not a number")
            return;
        }

        this.Added_result = this.Added_result + val;
        this.push1(val);

    }

    // adding methods to BinarySearchTree prototype
    BinarySearchTree.prototype.push1 = function (val) {

        var root = this.root;


        if (!root) {
            this.root = new Node(val);
          
            return;
        }

        var currentNode = root;
        var newNode = new Node(val);

       

        while (currentNode) {
            if (val < currentNode.value) {
                if (!currentNode.left) {
                    currentNode.left = newNode;
                    break;
                }
                else {
                    currentNode = currentNode.left;
                }
            }
            else {
                if (!currentNode.right) {
                    currentNode.right = newNode;
                    break;
                }
                else {
                    currentNode = currentNode.right;
                }
            }
        }

        //console.log(root);

    }


    BinarySearchTree.prototype.SUM1 = function (node) {
        if ((node === undefined) || (node === null)) {
            return 0;
        }
        else {
            return node.value + this.SUM1(node.left) + this.SUM1(node.right);
        }
    }

    BinarySearchTree.prototype.SUM = function () {
        if (!this.root) {
            console.log("Tree Empty");
           
            return;
        }
        else {
            var node = this.root;
            var total = 0;
            return this.SUM1(node, total);

        }
    }

    var bst = new BinarySearchTree();
    bst.push(8);
    bst.push(3);
    bst.push(1);
    bst.push(6);
    bst.push(4);
    bst.push(7);
    bst.push(10);
    bst.push(14);
    bst.push(13);
    //bst.push("5a");

    bst.totalAdded = function () {
        return this.Added_result;
    };

    var result = bst.SUM();
    console.log(result);

    console.log(bst.totalAdded());