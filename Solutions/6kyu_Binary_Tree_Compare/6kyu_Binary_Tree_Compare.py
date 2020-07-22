# return True if the two binary trees rooted and a and b are equal in value and structure
# return False otherwise
def compare(a, b):
    
    if a is None and b is None: 
        return True
    
    if a is not None and b is not None: 
        return ((a.val == b.val) and compare(a.left, b.left) and  compare(a.right, b.right))
    return False

#Better
def compare(a, b):
    return a.val == b.val and compare(a.left, b.left) and compare(a.right, b.right) if a and b else a == b