# Polynomial with Array
> 다항식을 배열로 표현을 하려면 어떻게 표현할 수 있을까?

- 변수가 1개인 Polynomial을 표현해보자.
  - f(x) = c x^e 일 때, 0 <= c <= 2^31 / 0 <= e <= 100 의 범위를 갖는다고 가정하자.
    1. 이런 제한 조건들을 필수적으로 적어주는 이유는, 확실한 Data type을 결정하기 위해!
    2. 다음으로는 어떤 Operation을 이용할 것인가? ```int poly[101];``` 최대차수 크기의 배열을 이용해보자!
  - index는 차수, 각 elements들은 Coefficients를 나타내도록 한다.

- 2 Dimensional array를 이용한 Polynomial
  - ```arr[항의 갯수][2]``` 이렇게 선언을 한 후, ```arr[0]```는 계수, ```arr[1]```은 차수로 둔다면, 메모리 적으로 큰 이득을 볼 수 있다!
  - 하지만 위의 1D array는 두 다항식의 연산에 있어서 빠른 속도를 보인다. 2D Array의 경우는 맞는 차수를 탐색해서 연산을 해주어야 한다.
  
- 미분은 어떻게 할 것 인가?
  - 미분한 값은 e = e-1이 될 것이고 c = e X c 임을 우리는 알고 있다.
  - 그에 따라 배열 내의 값을 새로 정리해주면 된다.
