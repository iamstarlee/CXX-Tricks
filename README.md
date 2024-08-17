## std::iota in C++
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
