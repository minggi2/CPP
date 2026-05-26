배열 arr의 자료형이 Sample1*가 아니라 Sample2*이면?
다음처럼 바뀐 경우이다. Sample2* arr[4];

arr에는 다음 객체들이 저장된다. 

arr[0] = a;   // Sample1*
arr[1] = b;   // Sample2*
arr[2] = c;   // Sample3*
arr[3] = d;   // Sample4*

여기서 문제는:
Sample3와 Sample4는 Sample2를 상속받지 않음
Sample1도 Sample2 타입이 아님
즉, Sample2* 배열에는 Sample2 계열 객체만 저장 가능하다.

따라서 이 코드는 자료형이 맞지 않아 컴파일 오류가 발생한다.