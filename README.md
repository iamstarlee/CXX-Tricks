## 10. 二维vector的最后一行
```C++
vector<vector<int>>& triangle
triangle.back()
```

## 9. C++中的pair
```C++
pair<ListNode*, ListNode*> results = f();
head = results.first;
tail = results.second;
//等价于
tie(head, tail) = f();
// 使用tie直接将结果更新到head和tail中[
```

## 8. 哈希表的遍历for(auto& count: counts)
如果没有&，每次遍历都会给重新开辟空间存放遍历的值，空间复杂度是O（n），而使用引用的话，即使用同一块空间。

## 7. int类型是32位，其最大值为啥是2的31次方减一
int类型是带符号整数，最高位是补码意义下的符号位，因此根据等比数列的求法：

$$ 2^0+2^1+2^2+...+2^{30} = {1 - 2*2^{30} \over (1-2)}=2^{31}-1 $$

## 6. this指针
在C++中，`this`指针指向对象的实例，每一个对象都可以通过`this`指针来访问自己的地址。友元函数没有`this`指针，因为友元不是类的成员，只有成员函数才有`this`指针。

## 5. std::iota in C++
```C++
void iota (ForwardIterator first, ForwardIterator last, T val);
```
Store increasing sequence, assign to every element in the range [first, last] successive values of val.

## 4. Convert string to integer
The C stdlib library atoi() function is used to convert a numeric string into integer value. Remember to convert string to char before using it.
```C++
string token;
atoi(token.c_str());
```

## 3. sort的lambda写法
```c++
std::sort(x, x + n,
          // Lambda expression begins
          [](float a, float b) {
              return (std::abs(a) < std::abs(b));
          } // end of lambda expression
        );
```

## 2. 二维vector的初始化
```C++
#define M 4
#define N 4

// one step, recommended
vector<vector<int>> matrix(M, vector<int>(N, 0));
```

## 1. C++ compilation in Ubuntu
```bash
g++ -o main main.cpp
```
```bash
./main
```


## 0. Cuda and Onnxruntime with C++ programming
- [Cuda-C-Programming-guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/)  
- [CUDA-ExecutionProvider](https://onnxruntime.ai/docs/execution-providers/CUDA-ExecutionProvider.html)
