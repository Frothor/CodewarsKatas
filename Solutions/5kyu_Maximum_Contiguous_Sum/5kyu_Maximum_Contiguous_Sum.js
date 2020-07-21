function maxContiguousSum (arr) {
  var max = 0, sum = 0;
  for (var i = 0; i < arr.length; i++) {
    sum += arr[i];
    if (sum > max) {
      max = sum
    }
    if (sum < 0 ) {
      sum = 0;
    }
  }
  return max;
}

var maxContiguousSum = function(arr) {
    var currentSum = 0;
    return arr.reduce(function(maxSum, number) {
        currentSum = Math.max(currentSum + number, 0);
        return Math.max(currentSum, maxSum);
    }, 0);
}