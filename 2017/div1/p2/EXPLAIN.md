# 2. 음수의 개수
## 해설
주어지는 질문에 따라서 “구간의 음수의 개수”를 구하거나, “해당하는 수의 부호를 변환”하는 문제.  
수열의 길이 ![equation](https://latex.codecogs.com/svg.latex?N)이 최대 ![equation](https://latex.codecogs.com/svg.latex?100%2C000)이고 질문의 개수 ![equation](https://latex.codecogs.com/svg.latex?Q) 또한 최대 ![equation](https://latex.codecogs.com/svg.latex?100%2C000)개이므로, 매 질문마다 전체 수열을 확인하면 시간복잡도가 ![equation](http://latex.codecogs.com/svg.latex?O%28NQ%29%3D10%5E%7B10%7D)가 되고, 제한 시간을 초과하게된다.  
그러므로 이 문제는 ‘**segment tree(구간 트리)**’라는 자료구조를 사용해야한다.  
이 자료구조를 사용하면 시간복잡도 ![equation](https://latex.codecogs.com/svg.latex?O%28QlogN%29)만에 해결 할 수 있으므로 제한 시간을 초과하지 않는다.
