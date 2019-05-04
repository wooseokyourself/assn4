# assn4
5.2 (D-9)
-
드디어 창을 띄웠음 >> mainwindow.ui
기존 과제는 QWidget 을 상속받아 메인윈도우를 띄웠는데, 나는 QMainWindow로 고쳐서 상속받아서 띄웠음.
왜냐하면 QWidget일 경우, 파일시스템이 어떤 식으로 돌아가는지 모르기 때문.
Problem1 에서, 두 ISeq 간의 비교연산을 진행하는 QCOMPARE을 구현해야 함.
사실 Problem1 제대로 동작하는지도 불분명.

-----

5.3 (D-8)
-
Problem 1 완료; song 의 <<, >>, == operator 는 seq의 operator 만으로 구현이 가능할 줄 알았으나 불가능하여(물론 가능한 방법이 존재하긴 하겠지만) song의 operator를 따로 구현해줌.
ui에서 .qrc 에서의 파일을 못 가져옴. ui 에디터 안에서는 분명히 뜨는데 실행시키면 안 뜸. 똑같은 과정이 새 프로젝트에서 되는 걸로 보아 현재 과제 프로젝트에 설정문제가 있는 듯 하나 진짜 찾을 자신이 1도 없음.


-----

5.4 (D-7)
-
과제 처음부터 mainwindow 소스가 as4.pro에 있길래 as4.pro 안에 .ui를 만들고 이리저리 생쇼를 했는데, 오늘 편의점 알바를 하던 도중 .ui는 as4가 아닌 app.pro에 넣어야 한다고 공지가 올라옴(이제서야?) 지금까지의 삽질은 정말 헛된 삽질이었음 안 알려줬으면 과제제출 절대못했음. 근데 이건 학생들이 하도 문의메일을 많이 해서 공지로 올려주신 걸테니, 나 말고도 수 많은 학생들이 나와 공통된 문제로 삽질을 해왔던 게 분명함. 

어쨌거나 오늘은 UI 초안을 만들었고, 스켈레톤 분석함; 
 - start와 duration의 자료형인 TimeInterval 과 TimeStamp 는 동일한 자료형임(unsigned long long)
 - 각 노트는 (TimeStamp start, TimeInterval duration, Pitch(int pitch, int octave))
 - 1 TimeInterval = 0.5 beat = 2unit = "0.25sec"
 
 앞으로는
 마우스클릭으로 노트를 삽입하고 삭제하는 GUI 구현해야 함.
 이 때, 노트가 삽입되면 ISeq::vector<Note*> m_notes 에 삽입된 노트의 위치를 토대로 새 Note push_back
 이런 식으로 실시간으로 형성되는 melody sequence와 drum sequence를 Song 객체가 가지고 있어야 하며,
 UI에서 PLAY 버튼 누를 시 이 Song 객체에 저장된 정보를 토대로 resource의 .wav 플레이하는 클래스를 구현해야함
