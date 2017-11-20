# 2. 음수의 개수
## 시간 제한 : 1초 | 메모리 제한 : 256MB
## 문제 내용
“자작”이는 음수를 찾는 능력이 탁월하다고 한다. 이를 의심한 “마루"는 직접 이를 평가하려고 한다. “마루"가 작성한 문제는 다음과 같은 형식으로 작성되었다.  
  
* 첫번째 줄에는 수열의 길이 ![equation](http://latex.codecogs.com/svg.latex?N%281%5Cleq%20N%5Cleq%20100%2C000%29)과 명령어의 개수 ![equation](http://latex.codecogs.com/svg.latex?Q%281%5Cleq%20Q%5Cleq%20100%2C000%29)가 주어진다.
* 두번째 줄에는 (공백으로 구분된) 길이가 ![equation](http://latex.codecogs.com/svg.latex?N)이고 정수로 이루어진 초기수열이 다음과 같이 주어진다.
![equation](http://latex.codecogs.com/svg.latex?n_1%2C%20n_2%2C%20n_3%2C%20...%2C%20n_%7BN-1%7D%2C%20n_%7BN%7D)
각 원소는 ![equation](http://latex.codecogs.com/svg.latex?0)값을 갖지 않고, 절대값은 ![equation](http://latex.codecogs.com/svg.latex?1%2C000)보다 작다. ![equation](https://latex.codecogs.com/svg.latex?%280%3C%7Cn_i%7C%3C1000%2C%201%5Cleq%20i%5Cleq%20N%29)
* 세번째 줄부터는 각 줄마다 하나의 명령어가 주어진다(전체 ![equation](http://latex.codecogs.com/svg.latex?Q)개의 명령). 명령어에는 다음과 같이 두 가지 유형이 있다.
  * 1로 시작하는 “**1 x y**” 유형의 명령어: 이 명령어는 현재 수열의 ![equation](http://latex.codecogs.com/svg.latex?x)번째부터 ![equation](http://latex.codecogs.com/svg.latex?y)번째까지의 범위에 들어잇는 음수의 개수를 한 줄에 출력하도록 하는 명령어이다. (수열의 첫번째 원소를 ![equation](http://latex.codecogs.com/svg.latex?1)번째 원소라고 한다.)
  * 2로 시작하는 “**2 x**” 유형의 명령어: 이 명령어는 현재 수열의 ![equation](http://latex.codecogs.com/svg.latex?x)번째 원소의 부호를 바꾸어서 수열을 변경하도록 하는 명령어이다. 이 명령어에 대해서는 아무런 값도 출력하지 않는다. 
  
“마루"가 제시하는 문제의 답을 출력하는 프로그램을 작성하자.
  
예를 들어 다음과 같은 문제가 주어진다고 하자.
```
4 3
1 2 -3 4
1 1 3
2 2
1 1 3
```
1. 첫번째 줄에서 수열의 길이가 4로 주어졌고, 해당 길이의 초기수열은 두번째 줄에 주어졌다. 명령어의 총 개수는 3개로 주어졌고 이는 세번째 줄부터 다섯번째 줄까지 주어졌다.
2. 첫번째 명령어에 의해 1번째부터 3번째 범위, 즉 {1, 2, -3}에 들어있는 음수의 개수를 구하면 1개이므로 한 줄에 1을 출력한다.
3. 두번째 명령어에 의해 2번째 원소의 부호를 바꾸므로 수열은 {1, -2, -3, 4}로 변경된다. 이 명령어에 대해서는 아무런 값도 출력하지 않는다.
4. 세번째 명령어에 의해 1번째부터 3번째 범위, 즉 {1, -2, -3}에 들어있는 음수의 개수를 구하면 2개이므로 한 줄에 2를 출력한다.
5. 따라서 최종 결과는 다음과 같다.
```
1
2
```
  
그 외 다른 예제는 다음과 같다.
  
## 예제 입력
```
10 4
-1 -2 -3 -4 -5 -6 -7 -8 -9 -10
1 1 10
2 5 
2 1 
1 1 10
```
## 예제 출력
```
10
8
```
