# cpp
A repository for practice programming in C++

## [PPP Style Guide](https://www.stroustrup.com/Programming/PPP-style.pdf)
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

* 변수 정의 시 반드시 초기화를 해주어야 한다. 

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

* 함수 선언 역시 한 줄로 표현해야 하며, 만약 매개변수 목록이 길어짐에 따라 해당 함수 선언에 여러 줄이 필요할 경우 함수가 너무 복잡하게 선언된 것은 아닌지 고민을 해봐야 한다. 이 경우에는 함수를 새로 정의해 해당 함수의 규모를 축소할 것을 권장한다.  

```c++
    int find_index(const string& s, char c); // find c’s position in s (-1 means 'not found')
```

### Variables and constants
* 변수는 선언과 동시에 초기화되거나, 사용 전에 필히 초기화해야 한다. 초기치가 결정되지 않은 상황이라면 변수를 미리 선언해서는 안 된다. 아래 예를 보자. 

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

* 초기치 `n`을 매개변수로 전달받아 조건을 만족하는지 검사하며, 해당 조건 검사를 통과했을 때 비로소 변수 `res`를 선언함과 동시에 초기화를 수행했다. 이처럼 코드를 작성할 경우 초기화되지 않은 변수를 잘못 사용할 수 있는 경우를 사전에 예방할 수 있다.

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
* 위 예는 초기치 `n`에 대한 조건 검사를 수행하기 전에 미리 변수 `res`를 선언한 상황이다. 만약 초기치가 조건 검사를 통과하지 못하면 변수 `res`는 무의미한 변수가 된다. 따라서 이와 같이 초기치가 결정되지 않은 상황에서 미리 변수 선언을 해서는 안 된다. 이런 사소한 부분이 나중에 큰 재앙을 일으킬 수 있다.
* 변수 선언과 동시에 초기화를 하는 것이 가장 좋지만, 초기치가 정해지지 않아 변수 선언과 초기화를 동시에 할 수 없는 경우라면 변수 선언 부분과 해당 변수를 초기화하는 부분이 코드 상에서 최대한 근접해야 한다. 이 거리가 멀어질수록 초기화를 망각하거나 초기화되지 않은 변수 사용에 따른 오류 발생 가능성이 그만큼 높아질 것이다. 
* 초기치를 사용자로부터 입력받아야 하는 상황이라면, 입력 바로 직전에 변수를 선언한다.

```c++
    int x;
    cin>>x;
```

* `cin` 연산이 실패할 수 있다. 이럴 경우에는 오류를 탐지하는 부분을 추가로 구현해 다른 초기치로 초기화하는 식으로 대응하면 된다. 

```c++
    if (cin.fail()) {
        x = 0;
    }
```
* 몇몇 형(`string` and `vector`)은 암묵적으로 선언과 동시에 초기화된다. 아래 코드는 초기화되지 않은 변수는 등장하지 않는다.

```c++
    vector<string> vec;
    for (string buf; cin>>buf; ) vec.push_back(buf);
```

* 의미가 결여된 상수 (magic constants)를 절대 쓰지 않는다.

```c++
    for (int i=1; i<32; ++i) {
        // process a month
    }
```

* 도대체 32가 의미하는 바는 무엇인가? 달(month)과 관련된 연산을 수행하는 부분이라면, 왜 31이 아닌 32인가? 그러면 이 값은 `vector`의 크기를 표현한 것인가? 의미를 파악하기에 모호한 상황이다. 차라리 아래와 같이 사용한다면 모호한 상황을 예방할 수 있다.

```c++
    const int mmax = 32;    // here we explain what 32 is and why

    // ...
    for (int i=1; i<mmax; ++i) {
        // process a month
    }
```

* 아래 코드가 훨씬 명확하다.

```c++
    for (int i=1; i<months.size(); ++i) {   // oh! Now it's obvious
        // process a month
    }
```

* `const` 키워드는 객체의 값을 수정할 일이 없을 경우에 사용한다. 

### Expressions and operators
* 길고 복잡한 표현식은 피해야 한다. 예를 들어, 대입문에서의 계산 부분(right-hand) 표현식에 네 개 이상의 연산자가 사용됐다면, 해당 부분이 과연 명확한지 고민해봐야 한다. 또한 표현식 작성 시 표기를 잘 하려고 현학적으로 작성하지 말아야 한다. 
* `count=count+1` 표현보다는 간결한 표현 형태(`++count` or `count++`)를 사용하고, 후위 연산(postfix, `count++`) 보다는 전위 연산(prefix, `++count)를 사용하는 것을 권장한다.
* 괄호 사용을 권장하지만, 기본적인 연산자 결합 순위에 구태여 괄호를 사용하지 말아야 한다. 예를 들면, 곱셈과 덧셈의 우선순위라든지, 논리 연산자 등이 있다. 우리는 `a*b+c/d` 표현식이 `(a*b)+(c/d)`로 계산됨을 알고 있고, `i<0 || max<i` 표현식이 `(i<0) || (max<i)`로 계산됨을 알고 있다. 
* 표현식 중간에 대입문을 중첩시키지 말아야 한다. (e.g. `z=a+(b=f(x))*c`) 코드를 분리시키는 편이 훨씬 명확하다. 

### Language feature use
* 배열보다는 벡터, 포인터보다는 라이브러리에서 제공하는 기능을 이용하는 것을 권장한다. 배열과 포인터는 불필요한 디버깅 또는 오류를 일으킬 가능성이 높다. * 형 변환은 꼭 필요한 경우에만 사용한다.
* 매크로는 헤더 가드 외에는 사용하지 않는다.
* 전역 변수를 사용하지 않는다.
* `delete` 또는 `new`를 단독으로 사용하지 않는다. C++에서 제공하는 기능을 이용하면 해당 기능들을 훨씬 안정적으로 사용할 수 있다.

### Line length
* 줄 단위 표기는 가독성과 밀접한 관련이 있다. 코드를 화면 상에 출력할 경우에는 최대 100글자, 종이 형태로 출력할 경우에는 최대 80글자를 사용한다.
* 개행은 코드 에디터가 자동으로 수행하지만, 코드의 형태나 의미를 잘 표현할 수 있도록 사용자가 직접 수행하는 것을 권장한다. 

```c++
    // bad:
    cout << item_name << ": unit = " << unit_count << "; number of units = " << number_of_units<< "; total = " << unit_count*number_of_units << '\n';
    // better:
    cout << item_name
         << ": unit = " << unit_count
         << "; number of units = " << number_of_units
         << "; total = " << unit_count*number_of_units
         << '\n';
```

* 코드 형태(layout)은 코드의 논리적인 구조를 잘 반영하면서 강조할 수 있어야 한다. 

### Error handling and reporting (§5.1)
* 일반적인 프로그램이라면 아래 사항들을 준수해야 한다.
1. 올바른 입력값이 입력되면 기대한 대로 동작해야만 한다.
2. 올바르지 않은 모든 입력에 대해 합당한 오류 메세지를 출력해야만 한다.
3. 하드웨어의 오동작(misbehaving hardware)에 대해 고려하지 않는다.
4. 시스템 소프트웨어의 오동작(misbehaving system software)에 대해 고려하지 않는다. 
5. 오류가 발견되면 종료할 수 있다. 

* 따로 언급되지 않는다면, 프로그램은 오류로부터 복구할 필요가 없다. 만약 프로그램에서 오류(e.g. 잘못된 입력)가 발견된다면, `std_lib_facilities.h`에 선언되어 있는 `error()` 함수를 호출해 프로그램을 종료할 수 있다. (§5.6.3)
* `runtime_error`를 사용하면 오류 메세지를 화면에 출력할 수 있다.
```c++
    int main()
    try {
        // . . . our program . . .

        return 0; // 0 indicates success
    }
    catch (runtime_error& e) {
        cerr << "runtime error: " << e.what() << '\n';
        keep_window_open();
        return 1; // 1 indicates failure
    }
```
### Compiler errors and warnings
* 프로그램은 컴파일 시 경고나 오류 없이 깔끔히 처리되어야 한다. 컴파일 시 오류가 발생하면 컴파일이 중지되지만, 경고만 발생한 경우에는 컴파일을 완료한다. 이때 경고를 무시하는 경우가 대부분인데, 대다수의 경고는 잠재적인 오류를 나타낸다. 따라서 오류뿐만 아니라 경고도 꼭 해결하는 것을 권장한다. 
* 경고 중 한 가지를 예외로 둔다. 아래와 같은 경우에서는 `signed/unsigned` 경고가 발생해도 무시한다. 

```c++
    for (int i=0; i<v.size(); ++i) // ...
```

* `v`는 표준 라이브러리 컨테이너 중 하나다(`vector` or `string`). 일반적인 PC에서 오류가 발생할 수 있는 경우는 벡터의 크기가 2<sup>31</sup>을 넘어가는 경우 뿐이다. 이 경우는 거의 등장하지 않는다.
* 이 부분에 대한 자세한 설명 또는 2<sup>31</sup> 크기보다 더 큰 벡터가 필요한 경우에는 §25.5.3을 참고한다. 

## The Real Stroustrup Interview<br>
https://www.stroustrup.com/ieee_interview.pdf
