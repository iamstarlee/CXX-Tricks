#include<limits.h>

int main(){
  int minv = INT_MIN;
  int maxv = INT_MAX;
  return 0;
}
/**
如果是int，可以用INT_MAX表示正无穷，INT_MIN表示负无穷，需要包含limits.h。
如果是double，可以用DBL_MAX表示正无穷，-DBL_MAX表示负无穷(注意不是DBL_MIN)，需要包含float.h。
**/
