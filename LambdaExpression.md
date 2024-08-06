```C++
#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}
```
This illustration shows the parts of lambda syntax:  
![image](https://github.com/user-attachments/assets/4076981d-8561-487d-8c32-de16c638d2fc)
1. capture clause  (Also known as the lambda-introducer in the C++ specification.)
2. parameter list Optional. (Also known as the lambda declarator)
3. mutable specification Optional.
4. exception-specification Optional.
5. trailing-return-type Optional.
6. lambda body.
