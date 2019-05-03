# assn4
4.2
드디어 창을 띄웠음 >> mainwindow.ui
기존 과제는 QWidget 을 상속받아 메인윈도우를 띄웠는데, 나는 QMainWindow로 고쳐서 상속받아서 띄웠음.
왜냐하면 QWidget일 경우, 파일시스템이 어떤 식으로 돌아가는지 모르기 때문.

Problem1 에서, 두 ISeq 간의 비교연산을 진행하는 QCOMPARE을 구현해야 함.
사실 Problem1 제대로 동작하는지도 불분명.


4.3
Problem 1 완료; song 의 <<, >>, == operator 는 seq의 operator 만으로 구현이 가능할 줄 알았으나 불가능하여(물론 가능한 방법이 존재하긴 하겠지만) song의 operator를 따로 구현해줌.
