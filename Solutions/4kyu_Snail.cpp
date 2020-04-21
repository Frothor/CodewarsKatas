/*
4kyu Snail

Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
*/

#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
   int n = snail_map.size();
    if (n == 0 || snail_map[0].size() == 0)
        return {};

    int m = snail_map[0].size();

    std::vector<int> v;

    int col_start = 0, col_end = m - 1, row_start = 0, row_end = n - 1;

    while (col_start <= col_end && row_start <= row_end) {
        for (int i = col_start; i <= col_end; i++)
            v.push_back(snail_map[row_start][i]);

        row_start++;

        for (int i = row_start; i <= row_end; i++)
            v.push_back(snail_map[i][col_end]);

        col_end--;

        for (int i = col_end; i >= col_start; i--)
            v.push_back(snail_map[row_end][i]);

        row_end--;

        for (int i = row_end; i >= row_start; i--)
            v.push_back(snail_map[i][col_start]);

        col_start++;

    }

    return v;
}

/*
#include <cstddef>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>>& xs) {
  std::vector<int> res;
  if (xs[0].empty())
    return res;
  const std::size_t ny = xs.size(), nx = xs[0].size();
  res.reserve(ny * nx);
  std::ptrdiff_t x0 = 0, y0 = 0, x1 = nx - 1, y1 = ny - 1, x = 0, y = 0;
  while (y0 <= y1) {
    while (x < x1) res.push_back(xs[y][x++]); y0++;
    while (y < y1) res.push_back(xs[y++][x]); x1--;
    while (x > x0) res.push_back(xs[y][x--]); y1--;
    while (y > y0) res.push_back(xs[y--][x]); x0++;
  }
  res.push_back(xs[y][x]);
  return res;
}



#include <vector>
using namespace std;
inline vector<int> snail(vector<vector<int>> array) {
  int leftlimit=0, uplimit=0, rightlimit=array[0].size()-1, downlimit=rightlimit, cx=-1, cy=-1;
  vector <int> ans;
  while (leftlimit<=rightlimit){
    for (cy++, uplimit++,    cx++; cx <= rightlimit; cx++) ans.push_back(array[cy][cx]); 
    for (cx--, rightlimit--, cy++; cy <= downlimit ; cy++) ans.push_back(array[cy][cx]);
    for (cy--, downlimit--,  cx--; cx >= leftlimit ; cx--) ans.push_back(array[cy][cx]);
    for (cx++, leftlimit++,  cy--; cy >= uplimit   ; cy--) ans.push_back(array[cy][cx]);
  } 
  return ans;
}
*/