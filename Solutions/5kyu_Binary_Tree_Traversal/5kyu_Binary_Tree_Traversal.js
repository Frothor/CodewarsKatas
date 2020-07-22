/*
A Node has the following properties:
var data; // A number or string.
Node left; // Undefined if there is no left child.
Node right; // Undefined if there is no right child.
*/

// 1.) Root node, 2.) traverse left subtree, 3.) traverse right subtree.
function preOrder(node)
{
  const arr = [];
  helper(node, arr);
  return arr;
  function helper(node, arr){
    if(!node) return;
    arr.push(node.data);
    helper(node.left, arr);
    helper(node.right, arr);
  }
}

// 1.) Traverse left subtree, 2.) root node, 3.) traverse right subtree.
function inOrder(node)
{
  const arr = [];
  helper(node, arr);
  return arr;
  function helper(node, arr){
    if(!node) return;
    helper(node.left, arr);
    arr.push(node.data);
    helper(node.right, arr);
  }
}

// 1.) Traverse left subtree, 2.) traverse right subtree, 3.) root node.
function postOrder(node)
{
  const arr = [];
  helper(node, arr);
  return arr;
  function helper(node, arr){
    if(!node) return;
    helper(node.left, arr);
    helper(node.right, arr);
    arr.push(node.data);
  }
}