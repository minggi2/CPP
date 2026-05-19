point 클래스의 x, y를 private로 바꾸면
Rectangle 클래스에서 x, y를 직접 사용할 수 없어서 오류가 발생한다.
cout << x << "," << y; 이 부분이 컴파일 오류가 난다.
protected → 자식 클래스 접근 가능
private → 자식 클래스 접근 불가능
