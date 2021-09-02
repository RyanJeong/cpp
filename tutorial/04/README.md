# C++ Tutorial
## 04 - 객체지향프로그래밍
###### [뒤로가기](/tutorial/#index)
---

### 등장 배경
* 절차지향프로그래밍 방법은 데이터 흐름(flow)에 기반한 방법
    * Top-Down
* 소프트웨어의 규모가 커짐에 따라 절차지향프로그래밍 방법 기반의 소프트웨어 설계 및 구현은 비효율적인 방법이 됨
* 이를 해결하기 위해 함수(procedure) 단위로 소프트웨어를 구조화하는 구조적프로그래밍 방법이 등장하게 됨
* 함수는 데이터 처리부를 하나의 단위로써 구조화할 수 있으나, <b>데이터는 구조화할 수 없음</b>
    * 절차지향프로그래밍과 구조적프로그래밍은 둘 다 전역 이름 영역(`namespace`)를 사용함에 따라 이름(변수명, 함수명 등) 포화상태에 빠짐

        <img src="./img/hardest_tasks.jpg" width="50%">

    * 데이터의 형태에 따라 다른 동작을 수행하는 함수들이 많아지면서 전달인자가 무엇인가에 따라, 또는 전달인자가 적절한 형태인가를 검사하는 코드가 늘어나게 됨
        * 만약 더하는 기능을 함수로 따로 분리했다고 가정하면, 전달인자의 형태에 따라 적절한 함수를 호출해야 함

            `int sum_int(int a, int b); double sum_double(double a, double b); ...`

* 소프트웨어의 규모가 커짐에 따라 데이터 처리를 구조화하는 것 뿐만 아니라, <b>데이터 구조화</b>에 대한 필요성도 높아짐

### 객체지향프로그래밍(Object-Oriented Programming)
* 이전까지 사용하던 방법들은 큰 문제를 작은 문제(함수)로 쪼개어 주어진 문제를 해결하는 Top-Down 방식
* 객체지향프로그래밍 방법은 작은 문제를 해결할 수 있는 <b>객체</b>를 만들고 해당 객체들을 조합해 큰 문제를 해결하는 Bottom-Up 방식
    * <b>객체 설계 시 객체 간 독립성이 높다면(loose coupling), 코드 수정 시 상대적으로 작은 범위의 코드만을 수정하면 되며, 재사용에 용이함</b>
        * 가장 이상적인 객체 설계
    * 객체 설계 시 객체 간 독립성이 낮다면(strong coupling), 코드 수정 시 상대적으로 큰 범위의 코드를 수정해야 함과 동시에 재사용에 제약이 많음
* <b>높은 독립성을 갖는 객체를 설계</b>(작은 문제)하고, <b>객체들 간 유기적인 상호작용 기반의 프로그램 동작 논리를 구성</b>(큰 문제)하는 방법으로 개발 기간 및 유지관리 비용을 비약적으로 절약할 수 있음

#### 객체(<i>object</i>)
* Abstract representation of something in <b>the real world</b>
    * 실세계에 존재하는 무언가를 추상화 과정을 거쳐 추상적인 개념으로 표현한 결과물
    * 상태와 행위들로 이루어진 소프트웨어 덩어리

        <img src="./img/object.jpg" width="50%">

#### 추상화(<i>abstraction</i>)
* 실세계에 존재하는 특정 대상을 관찰해 이를 잘 표현할 수 있는 <b>공통되면서 핵심적인 특징들을 도출</b>하는 과정
    * 핵심적인 특징이란, 실세계에 존재하는 대상을 프로그램으로 구현하고자 할 때 <b>반드시 필요한 부분</b>들을 의미
    * 추상화를 통해 도출한 특징들은 프로그램 동작 시 꼭 필요한 요소이며, 그 외 특징들은 프로그램에서 불필요한 요소들임
    * 실세계로부터 무언가를 관찰한 결과로 얻은 추상적인 표현이 <b>객체</b>
* 추상화를 통해 도출한 특징들은 크게 속성(attribute)과 행위(behavior)로 나눌 수 있음
    * Attribute는 <i>member variable</i>
    * Behavior는 <i>method</i>
* 추상화를 통해 도출한 특징들 중 서로 관련있는 것끼리 묶어놓은 것을 캡슐화(<i>encapsulation</i>)라고 함
    * 예를 들어, 자동차를 추상화했다고 가정하면, 여러 속성들과 행위들을 도출할 수 있음
        * 속성에는 자동차의 속도, 주유량, 주행거리, ... 등이 있음
        * 행위에는 감속, 가속, 조향, ... 등이 있음
    * 이때, 가속 행위와 관련있는 속성들을 묶는 것을 캡슐화라고 할 수 있음 

#### 클래스(<i>class</i>)
* Group of objects with the same structure and properties
* 객체를 실체화(메모리 할당)할 수 있는 설계도
    * 클래스를 사용해 객체를 실체화한 것을 인스턴스(<i>instance</i>)라고 함

#### 인스턴스(<i>instance</i>)
* Object that belongs to <b>a specifit class</b>
* 클래스로부터 <b>실체화(클래스에 명세된 내용을 기반으로 메모리에 할당된)</b>된 것
    * 클래스는 객체의 추상화 결과물이며, 이는 눈에 보이지 않는 추상 개념임
    * 객체는 클래스를 기반으로 실체화
    * 자동차라는 클래스가 있을 때, <b>Genesis G90, Volvo XC90</b> 등은 객체

#### 객체, 클래스, 인스턴스
* 객체는 실세계에 존재하는 무언가를 추상화 과정을 거쳐 상태와 행위들로 이루어진 소프트웨어 덩어리고, 클래스는 객체를 실체화할 수 있는 설계도이며, 인스턴스는 클래스를 기반으로 실체화한 결과물임
    ```c++
    #include <iostream>

    class Animal {
    // If access modifier is not specified, 
    // everything in a class is public
    public:
        // member function of class

        // in C++, structure is a class 
        // where members are public by default

        void set_animal(int food, int weight);
        void increase_food(int num);
        void view_state(void);
    private:
        // member variable of class, both static and non-static, 
        // are named like ordinary nonmember variables, 
        // but with a trailing underscore.
        int food_;
        int weight_;
    };  // semocolon!

    void Animal::set_animal(int food, int weight)
    {
        food_=food;
        weight_=weight;

        return;
    }

    void Animal::increase_food(int num)
    {
        food_+=num;
        weight_+=num/7;

        return;
    }

    void Animal::view_state(void)
    {
        std::cout << "The animal's food: " << food_ << std::endl;
        std::cout << "The animal's weight: " << weight_ << std::endl;

        return;
    }

    int main(void)
    {
        Animal cat; // cat is a instance of the class `Animal`
        cat.set_animal(100, 10);
        cat.increase_food(10);
        cat.view_state();

        return 0;
    } 
    ```

#### 캡슐화(<i>encapsulation</i>)
* 추상화를 통해 도출된 특징들 중에서 <b>서로 관련있는 속성과 행위</b>를 묶는 것
* 캡슐화에서 가장 중요한 것은 <b>외부에서 접근이 필요한 부분을 제외한 모든 부분들을 외부에서 접근하지 못 하도록 숨겨야 함</b>
    * Information hiding

        <img src="./img/encap.png" width="50%">
    
    * 캡슐화 과정을 거치면 클래스 내부 구현의 응집도(<i>cohesion</i>)를 높여 다른 외부 클래스와의 결합도(<i>coupling</i>)를 낮출 수 있음
        * High cohension, loose coupling
* 객체가 내부적으로 어떻게 구현되었는지 몰라도 사용 가능한 상태가 된다는 점이 캡슐화의 가장 큰 장점
    * 예를 들어, 어떤 회사에서 고객을 관리하고 있으며, 고객의 등급을 올리고자 함
    * 고객의 등급이 변할 때 주변에 영향받는 상태들이 있음(고객에게 제공되는 혜택, 복지, 정보, ...)
    * 고객의 등급을 조정하는 메서드를 사용하면 내부적으로 세세한 내용들이 어떻게 변화하는지 알지 못하더라도 해당 기능을 단순하게 사용할 수 있음

* 객체지향 언어에서는 일반적으로 접근제한자(<i>access modifier</i>)를 제공하며, 종류는 아래와 같음:
    * `public`: 클래스 외부에서 제한 없이 접근 가능
    * `private`: 클래스 외부에서 접근 불가
    * `protected`: 상속한 하위 클래스에서만 접근 가능

* `struct`에서 접근제한자가 생략되면 `public`으로 간주
* `class`에서 접근제한자가 생략되면 `private`으로 간주

#### 상속(<i>inheritance</i>)
* 객체지향의 핵심 기능 중 하나로, 특정 클래스의 모든 특징들을 물려 받는 것

    <img src="./img/inheritance.gif" width="50%">

    * `Predator_wild_cats` 클래스와 `Pet_dogs` 클래스는 `Mammal` 클래스로부터 상속 받았음
    * `Predator_wild_cats` 클래스와 `Pet_dogs` 클래스는 `Mammal` 클래스의 <i>child class</i>
    * `Mammal` 클래스는 `Predator_wild_cats` 클래스와 `Pet_dogs` 클래스의 <i>parent class</i>

* 상속 관계는 계층형(hierachical) 구조를 형성하며, 계층 구조의 아래 쪽으로 내려갈수록 구체화(specialize)되고 계층 구조의 위 쪽으로 올라갈수록 일반화(generalize)된다고 표현
* 클래스가 구체화될수록 인스턴스 고유의 특징들이 더 많이 포함되며, 일반화될수록 객체 고유의 특징들이 더 많이 포함됨
* 상속은 코드의 재사용성(reuseability)를 높임
* <b>is-a</b> 관계는 상속에서의 가장 이상적인 형태
    * `instance`는 `class`다.
        * 사자(lion)는 `Predator_wild_cats`다.
        * 비글(beagle)은 `Pet_dogs`다.
    * <b>is-a</b> 관계라면 문장에서의 자식 클래스를 부모 클래스로 대치해도 의미가 성립됨
        * 사자(lion)는 `Mammal`이다.
        * 비글(beagle)은 `Mammal`이다. 
* <b>has-a</b> 관계를 형성하지 않도록 상속 시 주의해야 함
    * `Sensor` 클래스가 `Vehicle` 클래스를 상속하며, `Sensor` 클래스의 인스턴스 카메라(camera)가 있다고 가정하면, 카메라와 클래스는 서로 <b>has-a</b> 관계를 가짐
    * 코드 재사용을 목적으로 <b>has-a</b> 관계를 형성하는 상속을 하게 되면, 부자연스러운(복잡한) 상속 관계가 형성될 수 있음
    * 다형성(<i>polymorphism</i>) 사용 권장

#### 다형성(<i>polymorphism</i>)
* 객체지향의 핵심 기능 중 하나로, 상속을 이용한 방법
    * 재정의(<i>override</i>)
* 하위 클래스에서 상위 클래스의 메소드를 재정의하여 어떠한 하위 클래스의 인스턴스가 상위 클래스의 메소드를 호출하는가에 따라 다른 동작을 구현할 수 있음
    * <i>Subtype polymorphism</b>
    * 상위 클래스 `Mammal`에 울음소리를 반환하는 `make_sound()` 메서드가 있을 때, 하위 클래스 `Pet_dogs`에서 `make_sound()`를 호출하면 `bow!`를 반환하고, 하위 클래스 `Pet_cats`에서 `make_sound()`를 호출하면 `meow!`를 반환
    * 다형성 지원 이전에는 `if`문을 사용해 조건에 맞는 부분으로 분기해 구현함에 따라 코드가 복잡해지고 양이 많아지는 단점이 있었음
* 다형성을 사용하면 상위 클래스에서 코드를 수정하지 않고 상속받은 하위 클래스에서 필요한 부분만 수정함으로써 유지보수 측면에 장점이 있음
* 코드의 가독성(readability) 향상을 기대할 수 있음

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---
