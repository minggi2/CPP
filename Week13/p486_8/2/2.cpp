6행을 다음과 같이 수정한다.

virtual void play() { 
    cout << "1번 sample" << endl; 
}

그러면 다형성이 발생하여 실제 객체의 play() 함수가 호출된다.

출력 결과

1번 sample
2번 sample
3번 sample
4번 sample