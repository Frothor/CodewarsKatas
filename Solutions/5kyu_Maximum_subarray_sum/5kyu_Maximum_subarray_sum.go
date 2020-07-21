package kata

func max(a, b int) int {
  if a > b {
    return a
  } else {
    return b
  }
}

func MaximumSubarraySum(numbers []int) int {
  res, sum := 0, 0
  for i := range numbers {
    sum += numbers[i]
    res = max(res, sum)
    sum = max(sum, 0)
  }
  return res
}