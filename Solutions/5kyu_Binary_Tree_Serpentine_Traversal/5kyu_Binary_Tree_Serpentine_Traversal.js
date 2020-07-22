function serpentineTree(node)
{ 
  const left = {}
  dfs(node,left)
  return Object.values(left).reduce((arr,val,i)=>arr.concat(i%2?val.reverse():val),[])
}

function dfs(node,obj,d=0){
  if (!node) return;
  if (!obj[d]) obj[d]=[]
  obj[d].push(node.data)
  dfs(node.left,obj,d+1)
  dfs(node.right,obj,d+1)
}

//Other solution:
function serpentineTree(node) {
  var resultArr = [];
  var counter = 0;

  function run(arr) {
    let newArr = [];
    counter++
    if (counter % 2) {
      resultArr = resultArr.concat(arr.map(function(node) {
        return node.data
      }))
    } else {
      resultArr = resultArr.concat(arr.map(function(node) {
        return node.data
      }).reverse())
    }
    
    arr.forEach(function(node) {
      if (node.left) {
        newArr.push(node.left)
      }
      if (node.right) {
        newArr.push(node.right)
      }
    })
    if (newArr.length) {
      run(newArr)
    };

  }
  run([node]);
  return resultArr;
}

//Another
const serpentineTree = node => {
  const run = (nodes, rev = false) => {
    if (!nodes.length) return [];
    const values = nodes.map(n => n.data);
    const children = nodes.reduce((cs, n) => cs.concat([n.left, n.right]), []).filter(c => c);
    return (rev ? values.reverse() : values).concat(run(children, !rev));
  }
  return run([node]);
}