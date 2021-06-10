# cpp
A repository for practice programming in C++

## [WIP] - [PPP Style Guide](https://www.stroustrup.com/Programming/PPP-style.pdf)
### Naming (§3.7)
* 형 이름(type name)은 대문자로 시작한다. (e.g. `Table` and `Temperature`)
* 형이 아닌 이름들은 소문자로 시작한다. (e.g. `x` and `var`)
* 이름에 여러 단어들이 사용될 경우 `_`(underscore)로 시작한다. (e.g. `initial_value` and `symbol_tbl`)
* 이름은 의미를 잘 나타내야 한다.
* 두문자어(acronyms)를 남용해서는 안 된다.
* 너무 긴 이름을 사용해서는 안 된다. (e.g. `remaining_free_slots_in_symbol_table`)
* 이름의 길이는 유효 범위와 비례해야 하며, 이를테면 어떤 이름의 유효 범위가 넓을수록 해당 이름이 더 설명적이여야  한다. (§8.4)

* 숫자 문자와 알파벳 간 식별이 명확해야 하며, `0Oo1lL`과 같이 식별에 어려운 이름 사용은 지양해야 한다.
* 변수 이름을 전부 대문자로 사용해서는 안 된다. (e.g. `ALL_CAPS`)
* C++ 식별자는 대소문자를 구분함에 유의해야 한다. (e.g. `Val` and `val` are different)

### Indentation

```c++
    // if statement:
    if (a==b) {
        // ...
    }
    else {
        // ...
    }

    // loop:
    for (int i=0; i<v.size(); ++i) {
        // ...
    }

    // Switch statement:
    switch(a) {
    case a:
        // ...
        break;
    case b:
        // ...
        break;
    default:
        // ...
    }

    // function:
    double sqrt(double d)
    {
        // ...
    }

    // class or struct:
    class Temperature_reading {
    public:
        // ...
    private:
        // ...
    };
```

* 중괄호({ and })의 위치를 주목하자.
* 보통 들여쓰기를 할 때 탭(`'\t'`)을 사용하지만, 코드 에디터의 설정에 따라 간격이 바뀌는 등의 문제가 발생할 수 있다. 이때 빈 칸(`' '`)을 사용하면 해당 문제를 해결할 수 있으며, 빈 칸 사용 시 최소 3 칸 이상의 간격을 사용해야 한다.
* 위 코딩 스타일은 보통 K&R style이라고 불리며, 불필요한 개행을 예방하는 장점이 있다. 
* Else-if 부분에서 닫는 중괄호와 여는 중괄호를 같이 사용하는 형태(`} else {`, cuddled)는 해당 줄을 지우거나 주석 처리할 때 추가 작업이 필요하므로 권장하지 않는다.
* 함수 정의 시 여는 괄호를 다음 줄에 표시하는 이유는 클래스 정의와 함수 정의를 쉽게 구분하기 위함이다. 
    * [Which layout style is the best for my code?](https://www.stroustrup.com/bs_faq2.html#layout-style)

### Whitespace
* 함수, 클래스, 그리고 논리적으로 서로 구분되는 코드들(e.g. 변수 선언구간, 반복문 구간, 반환문 구간 등) 다음에 빈 줄(empty lines or vertical whitespaces)을 사용하면 가독성을 높일 수 있다.

```c++
    void fct1()
    {
        Vector<string> v;               // to be used in the whole of the function

        string s;                       // input
        while (cin>>s) v.push_back(s);

        for (int i= 0; i<size(); ++i) { // processing
            // …
        }
    }

    int fct2()
    {
        // something

        // something else
    }

    class X {
        // …
    };
```

* 한 줄에 두 개 이상의 문장을 사용하면 코드를 검토하는 과정 중에 중요한 부분을 놓칠 수 있는 여지를 남긴다. 따라서 한 줄에 두 개 이상의 문장은 절대로 사용해서는 안 된다. 

```c++
    int x = 7; char* p = 29; // don’t
    int x = 7; f(x); ++x; // don’t
```

* `if` 문, `for` 문, `while` 문의 내부 문장이 단일 문장이면서 해당 문장이 간결하다면, 한 줄로 표현한다. 

```c++
    while (cin>>s) 
        v.push_back(s);

    while (cin>>s) v.push_back(s);
```

* 예약어 `if`, `for`, `while`, `switch`와  `(` 사이에 빈 칸을 한 칸 띄워야 한다. 
* 함수 호출 또는 함수 정의 시 함수의 이름과 `(` 사이에 빈 칸을 사용해서는 안 된다. 
* 클래스 이름과 `{` 사이에 빈 칸을 한 칸 띄워야 한다. 
* 표현식 내부에 빈 칸을 넣어서는 안 되며, 논리 연산자 등에 의해 여러 개의 표현식이 같이 사용될 경우 각 표현식의 의미를 강조하기 위해 빈 칸을 사용하는 것은 예외로 둔다. 

```c++
    if (x<0 || max<=x) // ...
    cin>>s;
    int a = z+y*z;
```

* 함수의 매개변수 형을 나열할 경우에는 빈 칸을 사용하고, 함수의 전달인자 목록을 작성할 경우에는 빈 칸을 생략한다. 

```c++
    void f(int, char*, couble);
    f(1,"2",3.4);
```

* 포인터 변수 선언 시 전통적인 C++ 표기를 따르라. 

```c++
    int* p;     // do it this way
    int *p;     // don't
    int * p;    // don't
    int*p;      // don't
```

* 변수 정의 시 초기화를 잊지 말고 꼭 해주어야 한다. 

```c++
    Vector<string> v;

    string s;
    while (cin>>s) v.push_back(s);
```

```c++
    int* p = &v[i];
```

### Comments (§7.6.4)
* 코드를 한 눈에 파악하기 어려운 경우, 코드 검토 시 이해를 돕기 위해 주석을 사용한다. 
* 코드가 명확한 부분은 구태여 설명하지 아니한다. 
* 주석은 아래와 같은 내용들을 포함했을 때 가장 이상적이라 할 수 있다. 
    
    1. Stating intent (what is this code supposed to do)
    2. Strategy (the general idea of this is …)
    3. Stating invariants, pre- and post-conditions (§5.10)

* 주석은 결국 사람이 읽는 문장인 만큼, 주석 작성 시 영어로 작성하되 의미가 명확하고 현학적이지 않으며 간결해야 한다. 특히, 잘못된 표현(문법 오류, 철자 오류, 구두점 및 대문자 오류 등)을 사용하지 않도록 주의해야 한다. 
* 모든 프로그램 파일(`.h` or `.cpp`)은 파일 시작 부분에 주석이 작성되어 있어야 하며, 주석 안에는 이름과 날짜, 프로그램이 수행되어야 하는 작업 내용이 포함되어야 한다. 

```c++
    /*
        Joe Q. Programmer
        Spring Semester 2011 (Jan 31)
        Solution for exercise 6.5.
        I use the technique from PPP section XX.Y.ZZ
    */
```

* 주요한(non-trivial) 함수와 코드에는 주석을 통해 해당 부분이 어떻게 동작되어야 하는가에 대해 설명한다. 

```c++
    // Bjarne Stroustrup 1/15/2010
    // Chapter 5 Exercise 11

    /*
        Write out Fibonacci numbers.
        Find the largest Fibonacci number that fits in an int
    */

    #include "std_lib_facilities.h"

    void fib()
    /*
        Compute the series and note when the int overflows;
        the previous value was the largest that fit
    */
    {
        int n = 1; // element n
        int m = 2; // element n+1

        while (n<m) {
            cout << n << '\n';
            int x = n+m;
            n = m; // drop the lowest number
            m = x; // add a new highest number
        }

        cout << "the largest Fibonacci number that fits in an int is " << n << '\n';
    }
```

* 다음은 불변 조건과 코드 수행 전후상태 설명에 대한 적절한 예시다. 

```c++
    class vector { // vector of double
        /*
        invariant:
            for 0<=n<sz elem[n] is element n
            sz<=space;
            if sz<space there is space for (space-sz) elements after elem[sz-1]
        */
        int sz;         // number of elements
        double* elem;   // pointer to the elements (or 0)
        int space;      // number of element plus number of free slots
        // …
    };

    vector::vector(int s)
          :sz(s), elem(new double[s]), space(s)
    {
        if (s<0)        // size must be non-negative
            throw Bad_vector_size();
        for (int i=0; i<sz; ++i)
            elem[i]=0;  // elements are initialized
    } 
```

### Declarations
* 선언은 한 줄로 표현하며, 해당 선언이 의미하는 바를 주석을 사용해 설명한다. 

```c++
    int p, q, r, b;     // No! Also: not very mnemonic names; where are the initializers?

    const int max = v.size()/2; // maximum partition size
    int nmonths = 0;            // number of months before current date
```

* 함수 선언 역시 한 줄로 표현해야 하며, 만약 매개변수 목록이 길어짐에 따라 해당 함수 선언에 여러 줄이 필요할 경우 함수가 너무 복잡하게 선언된 것은 아닌지 고민이 필요하다. 이 경우에는 함수를 덜 복잡하게 새로 정의하는 것을 권장한다. 

```c++
    int find_index(const string& s, char c); // find c’s position in s (-1 means 'not found')
```

### Variables and constants
* 변수는 선언과 동시에 초기화되거나, 사용 전에 필히 초기화해야 한다. 특히 초기화에 사용할 적절한 값이 결정되지 않은 상태에서 변수를 미리 선언해서는 안 된다. 아래 예를 보자. 

```c++
    vector<int> make_random_numbers(int n)
        // make n uniformly distributed random numbers
    {
        if (n<0)
            error("make_random_number: bad size");
        vector<int> res(n);
        // …

        return res;
    }
```

* 위 예는 초기치 `n`이 조건 검사를 통과했을 때 비로소 변수 `res`를 선언함과 동시에 초기화를 수행했다. 이처럼 코드를 작성할 경우 초기화되지 않은 변수를 잘못 사용할 수 있는 경우를 사전에 예방할 수 있다.

```c++
    vector<int> make_random_numbers(int n)
        // make n uniformly distributed random numbers
    {
        vector<int> res; // why define res when you don’t yet have a size for it?
        if (n<0)
            error("make_random_number: bad size");
        res.resize(n);
        // …

        return res;
    }
```
* 위 예는 초기치 `n`에 대한 조건 검사를 수행하기 전에 미리 변수 `res`를 선언한 상황이다. 만약 초기치가 조건 검사를 통과하지 못하면 변수 `res`는 무의미한 변수가 된다. 따라서 이와 같이 변수 선언을 해서는 안 된다. 이런 사소한 부분이 나중에 큰 재앙을 일으킬 수 있다. 


### Expressions and operators

### Language feature use

### Line length

### Error handling and reporting

### Compiler errors and warnings


## The Real Stroustrup Interview<br>
https://www.stroustrup.com/ieee_interview.pdf
