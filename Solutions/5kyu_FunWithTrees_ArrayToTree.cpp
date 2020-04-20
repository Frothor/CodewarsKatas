/*
5kyu Fun with trees: array to tree

You are given a non-null array of integers. Implement the method arrayToTree which creates a binary tree from its values in accordance to their order, while creating nodes by depth from left to right.

For example, given the array [17, 0, -4, 3, 15] you should create the following tree:

    17
   /  \
  0   -4
 / \
3   15 
The class TreeNode is available for you:

class TreeNode 
{
  public:
    TreeNode(int value, TreeNode* left, TreeNode* right)
      : m_value(value), m_left(left), m_right(right)
    {
    }

    TreeNode(int value)
      : m_value(value), m_left(NULL), m_right(NULL)
    {
    }

    bool operator==(const TreeNode& rhs) const
    {
        ... // Already implemented for you and used in test cases 
    }
    ...
}

This kata is part of fun with trees series:

Fun with trees: max sum
Fun with trees: array to tree
Fun with trees: is perfect
*/

class Solution
{
  public:
    static TreeNode* arrayToTree(std::vector<int> arr, std::size_t i = 0) 
    {
        if (i >= arr.size()) 
          return nullptr;
          
        return new TreeNode(arr[i], arrayToTree(arr, 2 * i + 1),
                                   arrayToTree(arr, 2 * i + 2));
    }
};


/*Naive solution
class Solution
{
  public:
    static TreeNode* arrayToTree(std::vector<int> arr) 
    {
        int n = arr.size();
        
       std::map<int, TreeNode*> map;

	      for (int i = 0; i < n; i++)
		      map[i] = new TreeNode(arr[i]);
        
        for(int i = n/2 - 1; i >= 0; i--) {
          int l = i*2 + 1;
          int r = i*2 + 2;
          if(l < n && r < n) {
            map[i] = new TreeNode(arr[i], map[l], map[r]);
            }
          else if(l < n)
            map[i] = new TreeNode(arr[i], map[l], NULL);
            
        }
        return map[0]; // TODO: implementation
    }
};
*/