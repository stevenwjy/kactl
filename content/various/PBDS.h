/**
 * Author: 7 Halim
 * Description: STL to do some AVL Data Structure operation.
 * Time: O(N^2)
 */
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define fbo(x)  find_by_order(x)  // iterator x-th smallest element (0-based)
#define ook(x)  order_of_key(x)   // number of elements strictly smaller than x
