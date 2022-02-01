# C++ Tutorial
## 04 - 객체지향프로그래밍 1
### 객체(<i>object</i>)
* 절차지향적인 방법으로 구조체 형 변수를 대상으로 연산을 수행하고자 할 때:
  ```cpp
  typedef struct Animal {
    char name[30];
    int age;
    int health;
    int food;
    int clean;
  } Animal;

  // ...

  int main() {
    Animal animal;
    play(animal);
    sleep(animal);

    return 0;
  }
  ```
  * 구조체 형 변수에 어떠한 연산을 하고자 할 때, 함수의 전달인자로 해당 구조체 형 변수를 매번 넘겨줘야 함
  * 데이터와 데이터의 처리가 서로 <b>분리</b>되어 있는 상태

* 객체지향적인 방법으로 구조체 형 변수를 대상으로 연산을 수행하고자 할 때:
  ```cpp
  typedef struct Animal {
    char name[30];
    int age;
    int health;
    int food;
    int clean;
  } Animal;

  // ...

  int main() {
    Animal animal;
    animal.play();
    animal.sleep();

    return 0;
  }
  ```
  * 함수 호출 시 매번 구조체 형 변수를 넘겨줄 필요 없음
  * 데이터와 데이터의 처리가 서로 <b>결합</b>되어 있는 상태
    * 함수는 구조체 형 변수의 내부 정보들을 모두 알고있음
  * 이러한 형태를 <b>객체</b>라고 함

* 객체는 실세계에 존재하는 대상을 <b>추상화</b> 과정을 거쳐 추상적인 개념으로 표현한 결과물이며, 이는 상태를 알려주는 변수(member variable)와 행위들을 나타내는 함수(method)들로 구성

### 추상화(<i>abstraction</i>)
* 실세계에 존재하는 대상을 관찰해 이를 잘 표현할 수 있는 <b>공통되면서 핵심적인 특징들을 도출</b>하는 과정
  * 핵심적인 특징이란, 실세계에 존재하는 대상을 프로그램으로 구현하고자 할 때 <b>반드시 필요한 부분</b>들을 의미
  * 추상화를 통해 도출한 특징들은 프로그램 동작 시 꼭 필요한 요소이며, 그 외 특징들은 프로그램에서 불필요한 요소들임
  * 실세계로부터 무언가를 관찰한 결과로 얻은 추상적인 표현이 <b>객체</b>가 됨
* 추상화를 통해 도출한 특징들은 크게 속성(attribute)과 행위(behavior)로 나눌 수 있음
  * Attribute는 <i>member variable</i>
  * Behavior는 <i>method</i>
* 추상화를 통해 도출한 특징들 중 서로 관련있는 것끼리 묶어놓고 속성들을 외부에서 보이지 않도록 감추는 것을 캡슐화(<i>encapsulation</i>)라고 함
  * 예를 들어, 자동차를 추상화했다고 가정하면, 여러 속성들과 행위들을 도출할 수 있음
    * 속성에는 자동차의 속도, 주유량, 주행거리, ... 등이 있음
    * 행위에는 감속, 가속, 조향, ... 등이 있음
  * 이때, 가속 행위와 관련있는 속성들을 묶는 것을 캡슐화라고 할 수 있음 
  * 자동차의 속도, 주유랑, 주행거리, ... 등은 외부에 보이지 않는 정보이며, 이러한 정보들에 접근하거나 수정해야 할 경우 메서드를 통해서 작업이 이루어져야 함
  * 캡슐화의 가장 큰 장점은 <b>객체가 내부적으로 어떻게 동작하는지 몰라도 사용이 가능해짐</b>

### 캡슐화(<i>encapsulation</i>)
* 추상화를 통해 도출된 특징들 중에서 <b>서로 관련있는 속성과 행위</b>를 묶는 것
* 캡슐화에서 가장 중요한 것은 <b>외부에서 접근이 필요한 부분을 제외한 모든 부분들을 외부에서 접근하지 못 하도록 숨겨야 함</b>
  * Information hiding

    <img src="./img/encap.png" width="50%">
  
  * 캡슐화 과정을 거치면 클래스 내부 구현의 응집도(<i>cohesion</i>)를 높여 다른 외부 클래스와의 결합도(<i>coupling</i>)를 낮출 수 있음
    * High cohension, loose coupling
* <b>객체가 내부적으로 어떻게 구현되었는지 몰라도 사용 가능한 상태가 된다는 점이 캡슐화의 가장 큰 장점</b>
  * 예를 들어, 어떤 회사에서 고객을 관리하고 있으며, 고객의 등급을 올리고자 함
  * 고객의 등급이 변할 때 주변에 영향받는 상태들이 있음(고객에게 제공되는 혜택, 복지, 정보, ...)
  * 고객의 등급을 조정하는 메서드를 사용하면 내부적으로 세세한 내용들이 어떻게 변화하는지 알지 못하더라도 해당 기능을 단순하게 사용할 수 있음

### 클래스(<i>class</i>)
* Group of objects with the same structure and properties
* 객체를 실체화(메모리 할당)할 수 있는 설계도
* 클래스를 사용해 객체를 실체화한 것을 인스턴스(<i>instance</i>)라고 함

### 인스턴스(<i>instance</i>)
* Object that belongs to <b>a specifit class</b>
* 클래스로부터 <b>실체화(클래스에 명세된 내용을 기반으로 메모리에 할당된)</b>된 것
  * 클래스는 객체의 추상화 결과물이며, 이는 눈에 보이지 않는 추상 개념임
  * 객체는 클래스를 기반으로 <b>실체화</b>

### 객체, 클래스, 인스턴스
* 객체는 실세계에 존재하는 무언가를 추상화 과정을 거쳐 상태와 행위들로 이루어진 소프트웨어 덩어리고, 클래스는 객체를 실체화할 수 있는 설계도이며, 인스턴스는 클래스를 기반으로 실체화한 결과물

### 접근 지시자(<i>access modifier</i>)
* C++ 클래스에서 사용 가능한 접근 지시자:
  * `public`: 클래스 외부에서 제한 없이 접근 가능
  * `private`: 클래스 외부에서 접근 불가
  * `protected`: 상속한 하위 클래스에서만 접근 가능
* 클래스 내 접근 지시자는 생략 가능:
  * `struct`에서 접근 지시자가 생략되면 기본 접근 지시자는 `public`
  * `class`에서 접근 지시자가 생략되면 기본 접근 지시자는 `private`
* 동물을 클래스로 표현한 예:
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
    void view_state();
   private:
    // member variable of class, both static and non-static, 
    // are named like ordinary nonmember variables, 
    // but with a trailing underscore.
    int food_;
    int weight_;
  };  // semocolon!

  void Animal::set_animal(int food, int weight) {
    food_ = food;
    weight_ = weight;
  }

  void Animal::increase_food(int num) {
    food_ += num;
    weight_ += num / 7;
  }

  void Animal::view_state() {
    std::cout << "The animal's food: " << food_ << std::endl;
    std::cout << "The animal's weight: " << weight_ << std::endl;
  }

  int main() {
    Animal cat; // cat is a instance of the class `Animal`
    cat.set_animal(100, 10);
    cat.increase_food(10);
    cat.view_state();

    return 0;
  } 
  ```

###### [뒤로가기](/tutorial/#index)
---
### SUBTITLE

###### [처음으로](#c-tutorial)
###### [뒤로가기](/tutorial/#index)
---