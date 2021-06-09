# cpp
A repository for practice programming in C++

## [WIP] - [PPP Style Guide](https://www.stroustrup.com/Programming/PPP-style.pdf)
### Naming (§3.7)
* 형 이름 (type name)은 대문자 사용 (e.g. `Table` and `Temperature`)
* 형이 아닌 이름들은 소문자 사용 (e.g. `x` and `var`)
* 이름에 여러 단어들이 사용될 경우 _ (underscore) 사용 (e.g. `initial_value` and `symbol_tbl`)
* 항상 의미있는 이름을 사용할 것
* 두문자어 (acronyms)를 남용하지 말 것
* 너무 긴 이름을 사용하지 말 것 (e.g. `remaining_free_slots_in_symbol_table`)
* 이름의 길이는 유효 범위와 비례해야 하며, 이를테면 어떤 이름의 유효 범위가 넓을수록 해당 이름이 더 설명적이여야 함 (§8.4)

* 숫자 문자와 알파벳 간 식별이 명확해야 하며, `0Oo1lL`과 같이 식별에 어려운 이름 사용은 지양해야 함
* 변수 이름을 전부 대문자로 사용하지 말 것 (e.g. `ALL_CAPS`)
* C++ 식별자는 대소문자를 구분함에 유의할 것 (e.g. `Val` and 'va' are different)

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

* 중괄호 ({ and })의 위치를 주목할 것
* 보통 들여쓰기를 할 때 탭 ('\t)을 사용하지만, 코드 에디터의 설정에 따라 간격이 바뀌는 등의 문제가 발생할 수 있음
* 빈 칸 (' ')을 사용하면 위 문제를 해결할 수 있으며, 최소한 3 칸 이상 간격을 사용할 것
* 위 코딩 스타일은 보통 K&R style이라고 불리며, 불필요한 개행을 줄임
* Else-if 부분에서 닫는 중괄호와 여는 중괄호를 같이 사용하는 형태 (`} else {`, cuddled)는 해당 줄을 지우거나 주석 처리할 때 추가 작업이 필요하므로 권장하지 않음
* 함수 정의 시 여는 괄호를 다음 줄에 사용하면 클래스 정의와 함수 정의를 쉽게 구분할 수 있음
    * [Which layout style is the best for my code?](https://www.stroustrup.com/bs_faq2.html#layout-style)

### Whitespace
* 함수, 클래스, 논리적으로 서로 구분되는 코드들 다음에 빈 줄 (empty lines or vertical whitespace)을 사용하면 가독성을 높일 수 있음

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

* 절대 한 줄에 두 개 이상의 문장을 넣지 말 것
    * 코드를 훑는 과정에서 중요한 부분을 놓칠 수 있음

```c++
    int x = 7; char* p = 29; // don’t
    int x = 7; f(x); ++x; // don’t
```

* `if` 문, `for` 문, `while` 문의 내부 문장이 단일 문장이면서 간결한 형태라면 한 줄로 표현

```c++
    while (cin>>s) 
        v.push_back(s);

    while (cin>>s) v.push_back(s);
```

* 예약어 `if`, `for`, `while`, `switch`와  `(` 사이에 빈 칸을 한 칸 띄울 것 
* 함수 호출 또는 함수 정의 시 함수의 이름과 `(` 사이에 빈 칸을 사용하지 말 것
* 클래스 이름과 `{` 사이에 빈 칸을 한 칸 띄울 것
* 표현식 내부에 빈 칸을 넣지 말 것 (의미를 강조하기 위한 빈 칸 삽입은 예외)

```c++
    if (x<0 || max<=x) // ...
    cin>>s;
    int a = z+y*z;
```

* 함수의 매개변수 형을 나열할 경우 빈 칸을 사용하고, 함수의 전달인자 목록 작성 시 빈 칸을 쓰지 않음

```c++
    void f(int, char*, couble);
    f(1,"2",3.4);
```

* 포인터 변수 선언 시 전통적인 C++ 표기를 따를 것

```c++
    int* p;     // do it this way
    int *p;     // don't
    int * p;    // don't
    int*p;      // don't
```

* 변수 정의 시 초기화를 잊지 말고 사용할 것

```c++
    Vector<string> v;

    string s;
    while (cin>>s) v.push_back(s);
```

```c++
    int* p = &v[i];
```

### Comments (§7.6.4)
* 코드를 한 눈에 파악하기 어려운 경우, 이해를 돕기 위해 주석 사용
* 코드 작성자와 해당 코드를 보는 사람을 위한 내용이며, 컴파일러는 이를 무시함
* 코드가 명확한 부분은 구태여 설명하지 말 것
* 주석은 아래와 같이 사용되면 좋음
    
    1. Stating intent (what is this code supposed to do), 의도 설명
    2. Strategy (the general idea of this is …), 코드 작성 근거 및 전략
    3. Stating invariants, pre- and post-conditions (§5.10), 불변 조건과 코드 수행 전후상태 설명

* 주석 작성 시 의미가 명확하고 알기 쉬운 영어를 사용할 것
* 주석 작성 시 잘못된 표현 (문법, 철자, 구두점 및 대문자) 사용에 주의할 것 

* 모든 프로그램 파일 (`.h` or `.cpp`)은 주석으로 시작해야 하며, 이때 이름과 날짜, 프로그램이 수행해야 하는 작업이 포함되어야 함

```c++
    /*
        Joe Q. Programmer
        Spring Semester 2011 (Jan 31)
        Solution for exercise 6.5.
        I use the technique from PPP section XX.Y.ZZ
    */
```


```


## The Real Stroustrup Interview<br>
https://www.stroustrup.com/ieee_interview.pdf
